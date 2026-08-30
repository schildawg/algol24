/* algol.c -- the Algol-24 C runtime.  See algol.h. */

#include "algol.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

/* ---------------------------------------------------------------- memory --
 *
 * A bump allocator.  Individual objects are never freed: knowing when one dies
 * is what a garbage collector is for, and this does not have one -- values go
 * into collections, get captured by closures as heap cells, and are referenced
 * from several places at once, so there is no ownership to follow.  A bytecode
 * VM is where that changes: it would own its heap through Buffer and trace it.
 *
 * ⚠️ That is NOT a licence to leak.  Not collecting is a design decision; not
 * returning memory at exit is just a badly behaved C program.  Every chunk is
 * threaded onto a list and freed by alg_shutdown, which atexit runs.
 *
 * This was measured, not assumed.  Before the list existed, a program that
 * filled more than one chunk lost every earlier one outright -- the base
 * pointers were not kept anywhere -- and `leaks --atExit` reported 323 leaks
 * and 349 MB on a loop that concatenated strings.  One-chunk programs hid it,
 * because arena_next still pointed into the only chunk there was.
 *
 * ⚠️ What never freeing COSTS, and it is not obvious from the above: building
 * a string a piece at a time is quadratic in memory.  Strings are immutable
 * and `concat` copies both operands, so `S := S + 'x'` in a loop retains every
 * intermediate -- the sum of the lengths, about n^2/2 bytes, all of it live.
 * 40,000 appends peak at 770 MB.  algc used to need 1.25 GB to compile itself
 * for exactly this reason, and now needs 81 MB -- not because the emitter was
 * fixed, but because READING a source file with 'Result := Result + Line' cost
 * more than emitting one.  Both go through Buffer now.
 *
 * That is an allocation-VOLUME problem, not a reclamation one: the fix is a
 * growable buffer that appends in place, which is what `Builder` below already
 * is internally and what `Buffer` will expose to programs.  It needs no
 * collector.
 */
#define ARENA_CHUNK (1024 * 1024)

/* A chunk's header sits at its own front, so the list costs no extra
 * allocation.  Sized to a multiple of 8 to keep the body aligned. */
typedef struct ArenaChunk {
    struct ArenaChunk *previous;
} ArenaChunk;

#define ARENA_HEADER ((sizeof(ArenaChunk) + 7u) & ~(size_t)7u)

static ArenaChunk *arena_chunks = NULL;
static char       *arena_next   = NULL;
static size_t      arena_left   = 0;

/* The String most recently produced by concat, with the length it reached and
 * the room reserved for it.  See the ⚠️ in concat. */
static const char *arena_tail_text = NULL;
static int32_t     arena_tail_len  = 0;
static int32_t     arena_tail_cap  = 0;

/* Defined with the files, further down; a file still open at exit is a leaked
 * handle for the same reason a chunk is leaked memory. */
static void close_open_files(void);

/* Likewise a Buffer's bytes, which are the one allocation here that does NOT
 * come from the arena -- so freeing the chunks would not reclaim them. */
static void free_all_buffers(void);

/* Returns everything the process took.  Files and buffers first, because both
 * structs live in the arena and reading one after the chunks are gone would be
 * a use after free. */
static void alg_shutdown(void) {
    close_open_files();
    free_all_buffers();

    while (arena_chunks != NULL) {
        ArenaChunk *previous = arena_chunks->previous;
        free(arena_chunks);
        arena_chunks = previous;
    }

    arena_next = NULL;
    arena_left = 0;
}

static void *arena_alloc(size_t bytes) {
    /* Align to 8 so a Value or a pointer can live here later. */
    bytes = (bytes + 7u) & ~(size_t)7u;

    if (bytes > arena_left) {
        size_t body  = bytes > ARENA_CHUNK ? bytes : ARENA_CHUNK;

        char *block = malloc(ARENA_HEADER + body);
        if (block == NULL) alg_error("Out of memory.");

        ((ArenaChunk *)block)->previous = arena_chunks;
        arena_chunks = (ArenaChunk *)block;

        arena_next = block + ARENA_HEADER;
        arena_left = body;
    }

    char *result = arena_next;
    arena_next += bytes;
    arena_left -= bytes;

    return result;
}

/* ------------------------------------------------------------ collections --
 *
 * List, Set, Stack and Array are one structure underneath: a Value array that
 * grows by doubling.  They differ only in what their methods allow -- a Set
 * checks membership before adding, a Stack takes from the end, an Array has a
 * fixed size and starts full of nil.  A Map is separate because its entries are
 * pairs.
 *
 * Nothing is freed, so growing copies into a fresh allocation and abandons the
 * old one.
 *
 * A Map carries a hash index beside its entries once it is big enough to be
 * worth one, which changes none of the visible behaviour because insertion
 * order is specified separately from lookup and is kept by the entry array
 * alone.  See the ⚠️ on ObjMap for why that separation is load-bearing rather
 * than incidental.
 */
typedef struct {
    Obj     obj;
    Value  *items;
    int32_t count;
    int32_t capacity;
} ObjSeq;

typedef struct {
    Value key;
    Value value;
} MapEntry;

typedef struct {
    Obj       obj;
    MapEntry *entries;
    int32_t   count;
    int32_t   capacity;

    /* Side index from key to its position in 'entries'.  Open addressing,
     * linear probing, power-of-two size, -1 meaning empty.
     *
     * ⚠️ 'entries' is untouched by this and stays in INSERTION ORDER, which is
     * specified behaviour: Keys, Values, 'for ... in' and printing all read it
     * and only it.  Nothing iterates the index -- it is asked "where is this
     * key?" and answers with a position, never with an order.
     *
     * That is not a convenience, it is what makes the index legal.  An object
     * key hashes by its ADDRESS, so if the index ever became the iteration
     * source, pointer values would decide the order of emitted text and
     * the fixed-point check would start failing intermittently -- the worst failure
     * mode this project has.  That bug has been made once already, when the map
     * was a plain unordered hash. */
    int32_t  *index;
    int32_t   index_mask;
} ObjMap;

/* Declared here rather than beside the enum functions, because alg_iterable
 * walks an enum type and is defined further up. */
typedef struct {
    Obj obj;

    const char *name;
    Value      *members;
    int32_t     count;
    int32_t     capacity;
} ObjEnumType;

typedef struct {
    Obj obj;

    const char *type;
    const char *name;

    /* Position within its type.  Carried because truthiness needs it: the
     * interpreter's isTruthy reads an enum's ordinal, so the first member of
     * every enum is falsey. */
    int32_t     ordinal;
} ObjEnum;

static bool equals(Value a, Value b);
static bool strict_equals(Value a, Value b);
static const char *as_text(Value v);
static bool is_number(Value v);
static bool is_text(Value v);
static int32_t as_integer(Value v, const char *message);

/* Text is characters, not bytes [SRC-004] -- see the utf8 section, which sits
 * beside is_text because that is where the text predicates live, and is
 * declared here because counting and indexing are wanted well above it. */
static int32_t utf8_count(const char *text, int32_t bytes);
static int32_t utf8_offset(const char *text, int32_t bytes, int32_t index);
static int32_t utf8_chars_in(const char *text, int32_t bytes);
static int32_t utf8_decode(const char *at);
static int utf8_encode(int32_t code, char *out);
_Noreturn static void undefined(const char *what, const char *name);

/* Declared here because the protocol checks live in the collections section,
 * above where classes are defined. */
static bool has_method(Value v, const char *name, int32_t arity);
static double as_double(Value v);

static bool is_obj(Value v, ObjType type) {
    return v.type == VAL_OBJ && v.obj->type == type;
}

static Value object(Obj *obj);

/* ------------------------------------------------------------ big integers --
 *
 * An Integer is unbounded [LEX-018]: arithmetic that leaves the machine width
 * GROWS rather than raising, so "an Integer is an integer" is the whole of the
 * type and there is no range for a program to be surprised by.
 *
 * ⚠️ The slow path begins past 2^63 and almost nothing reaches it.  algc cannot
 * -- its own scanner accumulates digits through this very arithmetic -- so the
 * cost of the rule for an ordinary program is one predicted branch per
 * operation, which is what the old range check already spent.
 *
 * ⚠️ CANONICAL FORM: a big integer never holds a value that fits in an int64.
 * Every operation ends at big_value, which demotes.  Without that invariant one
 * value would have two representations, and '=' , hashing and Map keys would
 * all disagree with themselves.
 *
 * ⚠️ The limbs are base 2^32 with a separate sign, rather than two's complement,
 * because magnitude arithmetic is the same for both signs and the sign rules
 * are then stated once in the signed wrappers rather than threaded through
 * every loop. */

typedef struct {
    Obj obj;

    bool      negative;
    int32_t   count;    /* limbs in use; the top one is never zero */
    uint32_t *limbs;    /* little-endian, base 2^32 */
} ObjBigInt;

static ObjBigInt *big_alloc(int32_t count) {
    ObjBigInt *b = arena_alloc(sizeof(ObjBigInt));

    b->obj.type = OBJ_BIGINT;
    b->negative = false;
    b->count    = count;
    b->limbs    = count == 0 ? NULL : arena_alloc((size_t)count * sizeof(uint32_t));

    for (int32_t i = 0; i < count; i++) b->limbs[i] = 0;
    return b;
}

/* Drops leading zero limbs, and with them the possibility of a negative zero. */
static void big_trim(ObjBigInt *b) {
    while (b->count > 0 && b->limbs[b->count - 1] == 0) b->count--;
    if (b->count == 0) b->negative = false;
}

/* ⚠️ INT64_MIN has no positive counterpart, so the magnitude is taken through
 * unsigned arithmetic rather than by negating. */
static ObjBigInt *big_of_i64(int64_t n) {
    ObjBigInt *b = big_alloc(2);
    uint64_t   m;

    if (n < 0) {
        b->negative = true;
        m = (uint64_t)(-(n + 1)) + 1u;
    }
    else m = (uint64_t)n;

    b->limbs[0] = (uint32_t)(m & 0xFFFFFFFFu);
    b->limbs[1] = (uint32_t)(m >> 32);

    big_trim(b);
    return b;
}

static bool big_fits_i64(const ObjBigInt *b) {
    if (b->count < 2) return true;
    if (b->count > 2) return false;

    uint64_t m = ((uint64_t)b->limbs[1] << 32) | b->limbs[0];

    return b->negative ? m <= (uint64_t)INT64_MAX + 1u : m <= (uint64_t)INT64_MAX;
}

static int64_t big_to_i64(const ObjBigInt *b) {
    uint64_t m = 0;

    if (b->count > 1) m = (uint64_t)b->limbs[1] << 32;
    if (b->count > 0) m |= b->limbs[0];

    if (!b->negative) return (int64_t)m;
    if (m == (uint64_t)INT64_MAX + 1u) return INT64_MIN;

    return -(int64_t)m;
}

/* The one way a big integer becomes a Value -- see the canonical-form note. */
static Value big_value(ObjBigInt *b) {
    big_trim(b);

    if (big_fits_i64(b)) return alg_int(big_to_i64(b));
    return object((Obj *)b);
}

static int mag_cmp(const ObjBigInt *a, const ObjBigInt *b) {
    if (a->count != b->count) return a->count < b->count ? -1 : 1;

    for (int32_t i = a->count - 1; i >= 0; i--)
        if (a->limbs[i] != b->limbs[i]) return a->limbs[i] < b->limbs[i] ? -1 : 1;

    return 0;
}

static ObjBigInt *mag_add(const ObjBigInt *a, const ObjBigInt *b) {
    int32_t    n = (a->count > b->count ? a->count : b->count) + 1;
    ObjBigInt *r = big_alloc(n);
    uint64_t   carry = 0;

    for (int32_t i = 0; i < n; i++) {
        uint64_t sum = carry;

        if (i < a->count) sum += a->limbs[i];
        if (i < b->count) sum += b->limbs[i];

        r->limbs[i] = (uint32_t)sum;
        carry = sum >> 32;
    }
    big_trim(r);
    return r;
}

/* Requires |a| >= |b|, which every caller establishes with mag_cmp. */
static ObjBigInt *mag_sub(const ObjBigInt *a, const ObjBigInt *b) {
    ObjBigInt *r = big_alloc(a->count);
    int64_t    borrow = 0;

    for (int32_t i = 0; i < a->count; i++) {
        int64_t d = (int64_t)a->limbs[i] - borrow - (i < b->count ? (int64_t)b->limbs[i] : 0);

        if (d < 0) {
            d += (int64_t)1 << 32;
            borrow = 1;
        }
        else borrow = 0;

        r->limbs[i] = (uint32_t)d;
    }
    big_trim(r);
    return r;
}

static ObjBigInt *big_add_signed(const ObjBigInt *a, const ObjBigInt *b) {
    ObjBigInt *r;

    if (a->negative == b->negative) {
        r = mag_add(a, b);
        r->negative = a->negative;
    }
    else {
        int c = mag_cmp(a, b);

        if (c == 0) return big_alloc(0);

        if (c > 0) { r = mag_sub(a, b); r->negative = a->negative; }
        else       { r = mag_sub(b, a); r->negative = b->negative; }
    }
    big_trim(r);
    return r;
}

static ObjBigInt *big_negate_of(const ObjBigInt *a) {
    ObjBigInt *r = big_alloc(a->count);

    for (int32_t i = 0; i < a->count; i++) r->limbs[i] = a->limbs[i];

    r->negative = !a->negative;
    big_trim(r);
    return r;
}

static ObjBigInt *big_sub_signed(const ObjBigInt *a, const ObjBigInt *b) {
    return big_add_signed(a, big_negate_of(b));
}

static ObjBigInt *big_mul(const ObjBigInt *a, const ObjBigInt *b) {
    if (a->count == 0 || b->count == 0) return big_alloc(0);

    ObjBigInt *r = big_alloc(a->count + b->count);

    for (int32_t i = 0; i < a->count; i++) {
        uint64_t carry = 0;

        for (int32_t j = 0; j < b->count; j++) {
            uint64_t cur = (uint64_t)r->limbs[i + j]
                         + (uint64_t)a->limbs[i] * b->limbs[j] + carry;

            r->limbs[i + j] = (uint32_t)cur;
            carry = cur >> 32;
        }

        for (int32_t k = i + b->count; carry != 0; k++) {
            uint64_t cur = (uint64_t)r->limbs[k] + carry;

            r->limbs[k] = (uint32_t)cur;
            carry = cur >> 32;
        }
    }
    r->negative = a->negative != b->negative;

    big_trim(r);
    return r;
}

/* |a| divided by |b|, by binary long division.
 *
 * ⚠️ Shift-and-subtract rather than Knuth's algorithm D, deliberately.  It is
 * one loop with nothing to get subtly wrong, and the path is reached only by a
 * program dividing numbers past 2^63 -- where being obviously correct is worth
 * more than being fast. */
static void mag_divmod(const ObjBigInt *a, const ObjBigInt *b,
                       ObjBigInt **quotient, ObjBigInt **remainder) {
    ObjBigInt *q = big_alloc(a->count == 0 ? 1 : a->count);
    ObjBigInt *r = big_alloc(a->count + 2);

    r->count = 0;

    for (int64_t bit = (int64_t)a->count * 32 - 1; bit >= 0; bit--) {
        uint32_t carry = 0;

        for (int32_t i = 0; i < r->count; i++) {
            uint32_t out = r->limbs[i] >> 31;

            r->limbs[i] = (r->limbs[i] << 1) | carry;
            carry = out;
        }
        if (carry != 0) {
            r->limbs[r->count] = carry;
            r->count++;
        }

        if ((a->limbs[bit / 32] >> (bit % 32)) & 1u) {
            if (r->count == 0) {
                r->limbs[0] = 1;
                r->count = 1;
            }
            else r->limbs[0] |= 1u;
        }

        if (mag_cmp(r, b) >= 0) {
            ObjBigInt *d = mag_sub(r, b);

            for (int32_t i = 0; i < d->count; i++)   r->limbs[i] = d->limbs[i];
            for (int32_t i = d->count; i < r->count; i++) r->limbs[i] = 0;

            r->count = d->count;
            q->limbs[bit / 32] |= 1u << (bit % 32);
        }
    }
    big_trim(q);
    big_trim(r);

    *quotient  = q;
    *remainder = r;
}

/* Divides in place by a single limb and answers the remainder.  Used only to
 * render a big integer as decimal, nine digits at a time. */
static uint32_t mag_divmod_small(ObjBigInt *b, uint32_t divisor) {
    uint64_t rem = 0;

    for (int32_t i = b->count - 1; i >= 0; i--) {
        uint64_t cur = (rem << 32) | b->limbs[i];

        b->limbs[i] = (uint32_t)(cur / divisor);
        rem = cur % divisor;
    }
    big_trim(b);
    return (uint32_t)rem;
}

static double big_to_double(const ObjBigInt *b) {
    double d = 0.0;

    for (int32_t i = b->count - 1; i >= 0; i--) d = d * 4294967296.0 + b->limbs[i];

    return b->negative ? -d : d;
}

static ObjBigInt *big_copy(const ObjBigInt *a) {
    ObjBigInt *r = big_alloc(a->count);

    for (int32_t i = 0; i < a->count; i++) r->limbs[i] = a->limbs[i];

    r->negative = a->negative;
    return r;
}

/* Decimal, in nine-digit chunks so the division is by a single limb.
 *
 * ⚠️ The chunk array is sized from the value rather than fixed.  Each division
 * by 10^9 removes just under 30 bits, so 32 bits of limb need at most 2 chunks
 * -- generous, and generous is the point: a fixed cap would silently truncate
 * the one kind of number this whole path exists for. */
static const char *big_to_text(const ObjBigInt *value) {
    if (value->count == 0) return "0";

    ObjBigInt *work   = big_copy(value);
    int32_t    room   = value->count * 2 + 2;
    uint32_t  *chunk  = arena_alloc((size_t)room * sizeof(uint32_t));
    int32_t    chunks = 0;

    while (work->count > 0 && chunks < room)
        chunk[chunks++] = mag_divmod_small(work, 1000000000u);

    /* One chunk is nine digits; the leading one may be fewer. */
    char   *text = arena_alloc((size_t)chunks * 9 + 2);
    int32_t at   = 0;

    if (value->negative) text[at++] = '-';

    at += snprintf(text + at, 11, "%u", chunk[chunks - 1]);

    for (int32_t i = chunks - 2; i >= 0; i--)
        at += snprintf(text + at, 11, "%09u", chunk[i]);

    text[at] = '\0';
    return text;
}

static bool is_bigint(Value v)  { return is_obj(v, OBJ_BIGINT); }

/* Either shape of Integer, as one question. */
static bool is_integer(Value v) { return v.type == VAL_INT || is_bigint(v); }

static ObjBigInt *as_big(Value v) {
    return v.type == VAL_INT ? big_of_i64(v.integer) : (ObjBigInt *)v.obj;
}

/* -1, 0 or 1, comparing two Integers of either shape. */
static int big_compare(Value a, Value b) {
    ObjBigInt *x = as_big(a);
    ObjBigInt *y = as_big(b);

    if (x->negative != y->negative) return x->negative ? -1 : 1;

    int c = mag_cmp(x, y);
    return x->negative ? -c : c;
}


static bool is_sequence(Value v) {
    if (v.type != VAL_OBJ) return false;

    /* Named explicitly rather than "not a Map": classes and instances are also
     * heap objects, and treating one as a sequence would read its header as a
     * Value array. */
    return v.obj->type == OBJ_LIST
        || v.obj->type == OBJ_SET
        || v.obj->type == OBJ_STACK
        || v.obj->type == OBJ_ARRAY;
}

static Value object(Obj *obj) {
    Value v;
    v.type = VAL_OBJ;
    v.obj  = obj;
    return v;
}

/* ----------------------------------------------------------------- buffer --
 *
 * Growable bytes with an explicit lifetime: the memory primitive a future VM
 * needs, and the fix for the language's one memory cliff.
 *
 * Strings are immutable and concat copies both operands, so accumulating text
 * a piece at a time retains every intermediate -- about n^2/2 bytes, all live,
 * because nothing here is ever freed.  A Buffer appends in place and doubles
 * when it runs out, so n appends cost under 2n.  That is an allocation-volume
 * fix and needs no collector.
 *
 * ⚠️ The bytes are malloc'd rather than taken from the arena.  Everything else
 * in this runtime is arena-allocated, and a Buffer cannot be: Free has to
 * actually return the memory, since the VM will own and trace its own heap and
 * cannot do that out of an allocator that gives nothing back until exit.
 *
 * ⚠️ Free POISONS; it does not merely deallocate.  The same programs run under
 * the tree-walking interpreter, which has no free at all -- so a Free that only
 * released memory would read fine interpreted and be undefined compiled, which
 * is exactly the divergence between the two that matters.  Both
 * implementations therefore mark the buffer dead and raise on ANY later
 * access.  That is also a better rule than C's, so nothing is lost by it.
 *
 * ⚠️ Nothing observable may depend on capacity.  The compiler must emit
 * identical bytes twice, and capacity is a function of
 * allocation history: Length is the size, capacity is invisible, and printing
 * shows neither the contents nor the capacity -- see buffer_text.
 */
typedef struct ObjBuffer {
    Obj obj;

    char  *bytes;
    size_t length;
    size_t capacity;
    bool   freed;

    /* Every buffer ever made, so alg_shutdown can return what a program did
     * not free.  Threaded exactly as the files are and for the same reason:
     * the struct itself is arena-allocated and outlives every Free. */
    struct ObjBuffer *next;
} ObjBuffer;

static ObjBuffer *all_buffers = NULL;

/* Not an error.  A program is allowed to end without freeing -- 'never
 * collected' is the design -- but the process still gives the pages back. */
static void free_all_buffers(void) {
    for (ObjBuffer *buffer = all_buffers; buffer != NULL; buffer = buffer->next) {
        free(buffer->bytes);
        buffer->bytes    = NULL;
        buffer->capacity = 0;
    }
    all_buffers = NULL;
}

static void buffer_reserve(ObjBuffer *buffer, size_t needed) {
    if (needed <= buffer->capacity) return;

    size_t capacity = buffer->capacity < 32 ? 32 : buffer->capacity;
    while (capacity < needed) capacity *= 2;

    char *grown = realloc(buffer->bytes, capacity);
    if (grown == NULL) alg_error("Out of memory.");

    buffer->bytes    = grown;
    buffer->capacity = capacity;
}

/* The one gate.  Every read and every write goes through it, so a use after
 * Free raises rather than reading memory that has gone back to malloc. */
static ObjBuffer *as_buffer(Value v, const char *what) {
    if (!is_obj(v, OBJ_BUFFER)) {
        char message[96];
        snprintf(message, sizeof message, "Only a Buffer has '%s'.", what);
        alg_error(message);
    }

    ObjBuffer *buffer = (ObjBuffer *)v.obj;
    if (buffer->freed) alg_error("That Buffer has been freed.");

    return buffer;
}

Value alg_buffer(Value size) {
    int32_t length = as_integer(size, "A Buffer's size must be an Integer.");
    if (length < 0) alg_error("A Buffer's size cannot be negative.");

    ObjBuffer *buffer = arena_alloc(sizeof(ObjBuffer));

    buffer->obj.type = OBJ_BUFFER;
    buffer->bytes    = NULL;
    buffer->length   = 0;
    buffer->capacity = 0;
    buffer->freed    = false;

    buffer->next = all_buffers;
    all_buffers  = buffer;

    /* Buffer(n) is n bytes of zero, the way Array(n) is n nils -- Length is
     * the addressable size from the moment it is made, not a high-water mark
     * that subscripting has to wait for. */
    if (length > 0) {
        buffer_reserve(buffer, (size_t)length);
        memset(buffer->bytes, 0, (size_t)length);
        buffer->length = (size_t)length;
    }

    return object((Obj *)buffer);
}

static void buffer_append(ObjBuffer *buffer, const char *text, size_t added) {
    buffer_reserve(buffer, buffer->length + added);

    memcpy(buffer->bytes + buffer->length, text, added);
    buffer->length += added;
}

/* ⚠️ Must copy.  Handing back the internal pointer would alias mutable bytes
 * as an immutable String, and the next Append would change a String someone
 * already holds -- the same unsoundness as appending in place inside concat.
 * One copy per call, which is O(n) once rather than O(n) per append.
 *
 * ⚠️ A zero byte is REFUSED rather than converted.  A String here is a
 * NUL-terminated char*, so 'Hi\0\0' would come back as 'Hi' -- while the
 * tree-walker's String holds all four characters and prints all four.  That is
 * a silent divergence between the back ends on a Buffer(n), which starts full
 * of zeroes, so it would have been easy to reach.  The scan costs O(n) on a
 * call that already copies O(n). */
static Value buffer_text(ObjBuffer *buffer) {
    for (size_t i = 0; i < buffer->length; i++) {
        if (buffer->bytes[i] == '\0') alg_error("A Buffer holding a zero byte has no Text.");
    }

    char *text = arena_alloc(buffer->length + 1);

    if (buffer->length > 0) memcpy(text, buffer->bytes, buffer->length);
    text[buffer->length] = '\0';

    return alg_string(text);
}

/* 'width' is how many bytes the access needs, so a 4-byte PutInt at the last
 * byte is refused rather than running off the end.  The message follows
 * bounded()'s, and the limit goes negative on a buffer too short to hold one
 * -- which reads correctly as "no offset is in range". */
static size_t buffer_offset(ObjBuffer *buffer, Value index, size_t width) {
    int32_t at    = as_integer(index, "A Buffer offset must be an Integer.");
    int32_t limit = (int32_t)buffer->length - (int32_t)width;

    if (at < 0 || at > limit) {
        char message[96];
        snprintf(message, sizeof message, "Offset %d out of range 0..%d.", at, limit);
        alg_error(message);
    }
    return (size_t)at;
}

/* ⚠️ Little-endian explicitly, not the host's order.  A Buffer written on one
 * machine and read on another has to agree, and more immediately: the compiler
 * must emit identical bytes everywhere, which host byte order would not. */
static void buffer_put_int(ObjBuffer *buffer, size_t at, int32_t value) {
    uint32_t bits = (uint32_t)value;

    buffer->bytes[at]     = (char)(bits         & 0xFFu);
    buffer->bytes[at + 1] = (char)((bits >>  8) & 0xFFu);
    buffer->bytes[at + 2] = (char)((bits >> 16) & 0xFFu);
    buffer->bytes[at + 3] = (char)((bits >> 24) & 0xFFu);
}

static int32_t buffer_get_int(ObjBuffer *buffer, size_t at) {
    uint32_t bits = (uint32_t)(unsigned char)buffer->bytes[at]
                  | (uint32_t)(unsigned char)buffer->bytes[at + 1] <<  8
                  | (uint32_t)(unsigned char)buffer->bytes[at + 2] << 16
                  | (uint32_t)(unsigned char)buffer->bytes[at + 3] << 24;

    return (int32_t)bits;
}

static void buffer_resize(ObjBuffer *buffer, int32_t length) {
    if (length < 0) alg_error("A Buffer's size cannot be negative.");

    /* Growing zero-fills, so a Resize is the same as having asked for that
     * size to begin with.  Shrinking keeps the capacity: it costs nothing and
     * a buffer that shrinks usually grows again. */
    if ((size_t)length > buffer->length) {
        buffer_reserve(buffer, (size_t)length);
        memset(buffer->bytes + buffer->length, 0, (size_t)length - buffer->length);
    }
    buffer->length = (size_t)length;
}

static Value sequence(ObjType type) {
    ObjSeq *seq = arena_alloc(sizeof(ObjSeq));

    seq->obj.type = type;
    seq->items    = NULL;
    seq->count    = 0;
    seq->capacity = 0;

    return object((Obj *)seq);
}

static ObjSeq *as_sequence(Value v, const char *what) {
    if (!is_sequence(v)) alg_error(what);
    return (ObjSeq *)v.obj;
}

static void seq_append(ObjSeq *seq, Value item) {
    if (seq->count == seq->capacity) {
        int32_t capacity = seq->capacity < 8 ? 8 : seq->capacity * 2;
        Value  *items    = arena_alloc((size_t)capacity * sizeof(Value));

        if (seq->count > 0) memcpy(items, seq->items, (size_t)seq->count * sizeof(Value));

        seq->items    = items;
        seq->capacity = capacity;
    }
    seq->items[seq->count++] = item;
}

static int32_t seq_index_of(ObjSeq *seq, Value item) {
    for (int32_t i = 0; i < seq->count; i++) {
        if (strict_equals(seq->items[i], item)) return i;
    }
    return -1;
}

static void seq_remove_at(ObjSeq *seq, int32_t at) {
    memmove(&seq->items[at], &seq->items[at + 1],
            (size_t)(seq->count - at - 1) * sizeof(Value));
    seq->count--;
}

Value alg_list(void)  { return sequence(OBJ_LIST); }
Value alg_set(void)   { return sequence(OBJ_SET); }
Value alg_stack(void) { return sequence(OBJ_STACK); }

Value alg_array(Value size) {
    if (size.type != VAL_INT || size.integer < 0) alg_error("Array size must be a non-negative Integer.");

    Value  value = sequence(OBJ_ARRAY);
    ObjSeq *seq  = (ObjSeq *)value.obj;

    /* Fixed length, and nil-filled: reading an untouched slot yields nil rather
     * than being an error. */
    for (int64_t i = 0; i < size.integer; i++) seq_append(seq, alg_nil());

    return value;
}

/* Set(list) -- the way a set literal is spelled.  Duplicates collapse. */
Value alg_set_of(Value items) {
    Value   value = alg_set();
    ObjSeq *from  = as_sequence(items, "Set expects a List.");

    for (int32_t i = 0; i < from->count; i++) {
        if (seq_index_of((ObjSeq *)value.obj, from->items[i]) < 0) {
            seq_append((ObjSeq *)value.obj, from->items[i]);
        }
    }
    return value;
}

Value alg_map(void) {
    ObjMap *map = arena_alloc(sizeof(ObjMap));

    map->obj.type  = OBJ_MAP;
    map->entries   = NULL;
    map->count     = 0;
    map->capacity  = 0;
    map->index     = NULL;
    map->index_mask = 0;

    return object((Obj *)map);
}

static ObjMap *as_map(Value v, const char *what) {
    if (!is_obj(v, OBJ_MAP)) alg_error(what);
    return (ObjMap *)v.obj;
}

/* The index is built once a Map is worth indexing, and doubled when it fills
 * past half.  Below MAP_INDEX_AT the linear scan is faster than computing a
 * hash, and most Maps in the compiler are small -- a table for every two-key
 * Map would be a pessimisation, not an optimisation. */
#define MAP_INDEX_AT   8
#define MAP_INDEX_SLOTS 32

/* Hash agreeing with strict_equals: two keys it calls equal must land here on
 * the same value.  FNV-1a, mixing the type in so an Integer and a Double do not
 * systematically collide -- they are never equal, since strict_equals rejects
 * differing types before it looks at anything else.
 *
 * ⚠️ A String hashes by its CONTENTS, not its pointer, because strict_equals
 * compares them with strcmp.  Hashing the pointer would make two equal strings
 * land in different slots and the Map would hold both. */
/* ⚠️ ASCII, deliberately, in place of strcasecmp.  Identifiers in this language
 * are ASCII, because the SCANNER rejects a non-ASCII byte and one never reaches
 * the mangler at all, so the answers agree with
 * the locale-aware version and with the interpreter's own case-insensitive
 * compare.  It is not a micro-optimisation: strcasecmp_l goes through
 * locale tables and came out AHEAD of strcmp in algc's profile, at about a
 * quarter of the whole run. */
static int alg_stricmp(const char *a, const char *b) {
    for (;; a++, b++) {
        unsigned char x = (unsigned char)*a;
        unsigned char y = (unsigned char)*b;

        if (x >= 'A' && x <= 'Z') x += 32;
        if (y >= 'A' && y <= 'Z') y += 32;

        if (x != y) return (int)x - (int)y;
        if (x == 0)  return 0;
    }
}

/* FNV-1a over the name FOLDED, so two spellings of one name hash alike.
 *
 * ⚠️ Names are matched without regard to case [SRC-011], and a method table
 * keyed by the exact spelling could not answer 'B.DOUBLED ()' for a method
 * declared 'Doubled'.  The fold is inline rather than through a copy: this runs
 * on every method lookup, which is the hottest path in the runtime. */
static uint32_t hash_folded(const char *name) {
    uint32_t hash = 2166136261u;

    for (const unsigned char *p = (const unsigned char *)name; *p; p++) {
        unsigned char c = *p;
        if (c >= 'A' && c <= 'Z') c += 32;

        hash ^= c;
        hash *= 16777619u;
    }
    return hash;
}

static uint32_t hash_bytes(uint32_t hash, const void *data, size_t length) {
    const unsigned char *bytes = data;

    for (size_t i = 0; i < length; i++) {
        hash ^= bytes[i];
        hash *= 16777619u;
    }
    return hash;
}

static uint32_t hash_value(Value v) {
    /* ⚠️ ONE tag for every number, because strict_equals promotes [VAL-013] and
     * a hash must agree with it: an Integer and a Double of the same value have
     * to reach the same slot or Contains answers false for a key the Map holds.
     * Mixing the real type in is what used to keep them apart, and that was
     * right only while membership was strict. */
    ValueType tag = v.type;
    /* ⚠️ An Integer, a big Integer and a Double of one value must reach one
     * slot, because '=' promotes and [VAL-013] makes a Map keyed 1 findable by
     * 1.0.  They therefore share a tag as well as a hashed form. */
    if (tag == VAL_INT || is_bigint(v)) tag = VAL_DOUBLE;

    uint32_t hash = hash_bytes(2166136261u, &tag, sizeof tag);

    switch (v.type) {
        case VAL_NIL:    return hash;
        case VAL_BOOL:   return hash_bytes(hash, &v.boolean, sizeof v.boolean);

        /* ⚠️ Hashed AS A DOUBLE, so an Integer and a Double of one value reach
         * the same slot -- which [VAL-013] requires, since '=' promotes.
         *
         * ⚠️ It used to say "every int32 converts to a double exactly", and
         * that stopped being true when an Integer became unbounded: past 2^53
         * the conversion rounds, so two Integers can share a slot.  That is a
         * COLLISION and not a fault -- equal values still hash alike, which is
         * the only thing a hash must promise. */
        case VAL_INT: {
            double widened = (double)v.integer;
            return hash_bytes(hash, &widened, sizeof widened);
        }


        case VAL_DOUBLE: {
            /* ⚠️ All NaNs are one key in strict_equals, so all NaNs must be one
             * hash -- whatever payload the bits carry. */
            if (isnan(v.number)) return hash_bytes(hash, "NaN", 3);

            /* ⚠️ -0.0 and 0.0 ARE one key now, since strict_equals promotes and
             * '-0.0 == 0.0' in C.  The comment here used to say they were
             * different keys needing no normalising; that was true only while
             * the comparison was a memcmp.  Without this the Map holds both and
             * finds neither reliably. */
            double bits = v.number;
            if (bits == 0.0) bits = 0.0;

            return hash_bytes(hash, &bits, sizeof bits);
        }
        case VAL_STRING:
        case VAL_CHAR:   return hash_bytes(hash, v.string, (size_t)v.length);

        /* ⚠️ A big Integer is a NUMBER and hashes as one.  By address -- which
         * is what every other heap value does -- two equal big Integers would
         * be two Map keys, and a Map would hold a key it could not find. */
        case VAL_OBJ: {
            if (v.obj->type == OBJ_BIGINT) {
                double widened = big_to_double((ObjBigInt *)v.obj);
                return hash_bytes(hash, &widened, sizeof widened);
            }

            /* By address otherwise, matching strict_equals, which compares
             * collections and instances by identity.  Safe only because nothing
             * iterates the index -- see the ⚠️ on ObjMap. */
            void *address = v.obj;
            return hash_bytes(hash, &address, sizeof address);
        }
    }
    return hash;
}

/* Builds, or rebuilds, the index over the whole of 'entries'.
 *
 * Walks them in order, so the index never carries information the array does
 * not -- rebuilding from scratch is always correct, and is the reason the two
 * can never disagree about what the Map contains. */
static void map_reindex(ObjMap *map, int32_t slots) {
    /* ⚠️ The table is REUSED when the size has not changed, and that is not a
     * micro-optimisation to undo.  Two of the three callers are growing and
     * must allocate; the third is alg_remove, which rebuilds at the SAME size
     * on every single removal.  Allocating there instead abandons a whole table
     * per removed key, and the arena never gives one back -- so draining an
     * n-entry Map cost n tables.  Measured at n = 10,000: 1,272 MB, against
     * 8 MB with this line, and 4.7 GB at n = 20,000.
     *
     * ⚠️ The ⚠️ on alg_remove says the rebuild is O(n) "but the memmove above
     * already is, so nothing regresses".  That is true of TIME and was the
     * sentence that made the memory cost easy to miss. */
    if (map->index == NULL || slots != map->index_mask + 1) {
        map->index = arena_alloc((size_t)slots * sizeof(int32_t));
    }
    map->index_mask = slots - 1;

    for (int32_t i = 0; i < slots; i++) map->index[i] = -1;

    for (int32_t i = 0; i < map->count; i++) {
        uint32_t slot = hash_value(map->entries[i].key) & (uint32_t)map->index_mask;

        while (map->index[slot] != -1) slot = (slot + 1) & (uint32_t)map->index_mask;
        map->index[slot] = i;
    }
}

static int32_t map_index(ObjMap *map, Value key) {
    /* One behaviour, two implementations of finding it.  A Map too small to
     * have earned an index answers by scanning, which is what this always did. */
    if (map->index == NULL) {
        for (int32_t i = 0; i < map->count; i++) {
            if (strict_equals(map->entries[i].key, key)) return i;
        }
        return -1;
    }

    uint32_t slot = hash_value(key) & (uint32_t)map->index_mask;

    /* Terminates because the table is kept under half full, so an empty slot
     * always exists to stop at. */
    for (;;) {
        int32_t at = map->index[slot];

        if (at == -1) return -1;
        if (strict_equals(map->entries[at].key, key)) return at;

        slot = (slot + 1) & (uint32_t)map->index_mask;
    }
}

static void map_put(ObjMap *map, Value key, Value item) {
    /* Re-assigning an existing key keeps its original position. */
    int32_t found = map_index(map, key);
    if (found >= 0) {
        map->entries[found].value = item;
        return;
    }

    if (map->count == map->capacity) {
        int32_t   capacity = map->capacity < 8 ? 8 : map->capacity * 2;
        MapEntry *entries  = arena_alloc((size_t)capacity * sizeof(MapEntry));

        if (map->count > 0) memcpy(entries, map->entries, (size_t)map->count * sizeof(MapEntry));

        map->entries  = entries;
        map->capacity = capacity;
    }
    map->entries[map->count].key   = key;
    map->entries[map->count].value = item;
    map->count++;

    /* Build on reaching the threshold, then double whenever the table would go
     * half full.  Both cases rebuild from 'entries', so the new entry needs no
     * separate insertion in them. */
    if (map->index == NULL) {
        if (map->count >= MAP_INDEX_AT) map_reindex(map, MAP_INDEX_SLOTS);
        return;
    }
    if (map->count * 2 > map->index_mask + 1) {
        map_reindex(map, (map->index_mask + 1) * 2);
        return;
    }

    uint32_t slot = hash_value(key) & (uint32_t)map->index_mask;

    while (map->index[slot] != -1) slot = (slot + 1) & (uint32_t)map->index_mask;
    map->index[slot] = map->count - 1;
}

/* ------------------------------------------------------- literal building -- */

Value alg_list_keep(Value list, Value item) {
    seq_append(as_sequence(list, "Expected a List."), item);
    return list;
}

Value alg_map_keep(Value map, Value key, Value item) {
    map_put(as_map(map, "Expected a Map."), key, item);
    return map;
}

/* --------------------------------------------------------------- methods --
 *
 * Dispatch happens here rather than in the emitter, because a name means
 * different things to different receivers -- Contains is on every collection,
 * Get is on three of them -- and the receiver's type is only known at run time.
 * That is what the interpreter does too: get(Token) is resolved on the instance.
 */
/* ⚠️ Compared in 64 bits and only then narrowed.  An Integer is wider than a
 * position is, so truncating first would wrap a huge index into a valid one --
 * a silent wrong element where the language has a diagnostic that already says
 * exactly the right thing. */
static int32_t bounded(Value index, int32_t count, bool inclusive) {
    if (index.type != VAL_INT) alg_error("Index must be an Integer.");

    int64_t at    = index.integer;
    int64_t limit = inclusive ? count : count - 1;

    if (at < 0 || at > limit) {
        // Named, because the interpreter names it and the text is catchable.
        char message[96];
        snprintf(message, sizeof message, "Index %lld out of range 0..%lld.",
                 (long long)at, (long long)limit);
        alg_error(message);
    }
    return (int32_t)at;
}

Value alg_add_item(Value receiver, Value item) {
    ObjSeq *seq = as_sequence(receiver, "Only a List or a Set has 'Add'.");

    if (seq->obj.type == OBJ_ARRAY) alg_error("An Array has a fixed size.");

    /* A Set keeps the first occurrence and ignores the rest. */
    if (seq->obj.type == OBJ_SET && seq_index_of(seq, item) >= 0) return alg_nil();

    seq_append(seq, item);
    return alg_nil();
}

Value alg_put(Value receiver, Value key, Value item) {
    map_put(as_map(receiver, "Only a Map has 'Put'."), key, item);
    return alg_nil();
}

Value alg_get(Value receiver, Value key) {
    if (is_obj(receiver, OBJ_MAP)) {
        ObjMap *map   = (ObjMap *)receiver.obj;
        int32_t found = map_index(map, key);

        return found < 0 ? alg_nil() : map->entries[found].value;
    }
    ObjSeq *seq = as_sequence(receiver, "Only a collection has 'Get'.");

    return seq->items[bounded(key, seq->count, false)];
}

Value alg_set_at(Value receiver, Value index, Value item) {
    ObjSeq *seq = as_sequence(receiver, "Only an Array or a List has 'Set'.");

    seq->items[bounded(index, seq->count, false)] = item;
    return item;
}

Value alg_remove(Value receiver, Value key) {
    if (is_obj(receiver, OBJ_MAP)) {
        ObjMap *map   = (ObjMap *)receiver.obj;
        int32_t found = map_index(map, key);

        if (found < 0) return alg_nil();

        Value removed = map->entries[found].value;

        /* Close the gap so the remaining keys keep their relative order. */
        memmove(&map->entries[found], &map->entries[found + 1],
                (size_t)(map->count - found - 1) * sizeof(MapEntry));
        map->count--;

        /* ⚠️ Every stored position above 'found' has just shifted down by one,
         * so the whole index is stale -- it must be REBUILT, not patched.  That
         * is O(n) in TIME, and the memmove above already is, so nothing
         * regresses there.  ⚠️ It is O(1) in MEMORY only because map_reindex
         * reuses the table at an unchanged size; see the ⚠️ there before
         * touching either.
         *
         * Patching only the removed slot is the plausible wrong version: it
         * leaves every later key pointing one entry past itself, which reads as
         * a Map whose values have quietly shifted rather than as a crash. */
        if (map->index != NULL) map_reindex(map, map->index_mask + 1);

        return removed;
    }
    ObjSeq *seq = as_sequence(receiver, "Only a Map or a Set has 'Remove'.");

    int32_t found = seq_index_of(seq, key);
    if (found < 0) return alg_bool(false);

    seq_remove_at(seq, found);
    return alg_bool(true);
}

Value alg_remove_at(Value receiver, Value index) {
    ObjSeq *seq = as_sequence(receiver, "Only a List has 'RemoveAt'.");

    int32_t at      = bounded(index, seq->count, false);
    Value   removed = seq->items[at];

    seq_remove_at(seq, at);
    return removed;
}

Value alg_insert(Value receiver, Value index, Value item) {
    ObjSeq *seq = as_sequence(receiver, "Only a List has 'Insert'.");

    /* Inserting at Length appends, so a loop can fill a list. */
    int32_t at = bounded(index, seq->count, true);

    seq_append(seq, alg_nil());
    memmove(&seq->items[at + 1], &seq->items[at],
            (size_t)(seq->count - at - 1) * sizeof(Value));
    seq->items[at] = item;

    return alg_nil();
}

Value alg_contains(Value receiver, Value item) {
    if (is_obj(receiver, OBJ_MAP)) {
        return alg_bool(map_index((ObjMap *)receiver.obj, item) >= 0);
    }
    return alg_bool(seq_index_of(as_sequence(receiver, "Only a collection has 'Contains'."), item) >= 0);
}

Value alg_index_of(Value receiver, Value item) {
    /* -1 rather than an error, so a miss can be tested for. */
    return alg_int(seq_index_of(as_sequence(receiver, "Only a sequence has 'IndexOf'."), item));
}

Value alg_clear(Value receiver) {
    if (is_obj(receiver, OBJ_MAP)) {
        ObjMap *map = (ObjMap *)receiver.obj;

        map->count = 0;

        /* ⚠️ The index has to go too, not just the count.  A stale index over
         * an emptied array reports hits on entries that are no longer there,
         * and map_index would hand back a position past the end.  One line,
         * easy to miss, and the failure is silent. */
        map->index      = NULL;
        map->index_mask = 0;

        return alg_nil();
    }
    as_sequence(receiver, "Only a collection has 'Clear'.")->count = 0;
    return alg_nil();
}

Value alg_fill(Value receiver, Value item) {
    ObjSeq *seq = as_sequence(receiver, "Only an Array has 'Fill'.");

    for (int32_t i = 0; i < seq->count; i++) seq->items[i] = item;
    return alg_nil();
}

Value alg_push(Value receiver, Value item) {
    seq_append(as_sequence(receiver, "Only a Stack has 'Push'."), item);
    return item;
}

Value alg_pop(Value receiver) {
    ObjSeq *seq = as_sequence(receiver, "Only a Stack has 'Pop'.");

    if (seq->count == 0) alg_error("Pop from an empty Stack.");
    return seq->items[--seq->count];
}

Value alg_peek(Value receiver) {
    ObjSeq *seq = as_sequence(receiver, "Only a Stack has 'Peek'.");

    if (seq->count == 0) alg_error("Peek at an empty Stack.");
    return seq->items[seq->count - 1];
}

/* Numbers order numerically, including an Integer against a Double, and text
 * lexicographically.  Anything else is an error rather than whatever the host's
 * natural ordering happens to be -- the interpreter used to die with a raw
 * ClassCastException here. */
static int compare(Value a, Value b) {
    if (is_number(a) && is_number(b)) {
        double left  = as_double(a);
        double right = as_double(b);

        return left < right ? -1 : (left > right ? 1 : 0);
    }
    if (is_text(a) && is_text(b)) return strcmp(a.string, b.string);

    alg_error("Can only sort numbers against numbers, or text against text.");
    return 0;
}

Value alg_sort(Value receiver) {
    ObjSeq *seq = as_sequence(receiver, "Only a List or an Array has 'Sort'.");

    /* Insertion sort: the collections here are small, and it is stable, which
     * matters because both implementations have to agree on where equal
     * elements land. */
    for (int32_t i = 1; i < seq->count; i++) {
        Value   item = seq->items[i];
        int32_t j    = i - 1;

        while (j >= 0 && compare(seq->items[j], item) > 0) {
            seq->items[j + 1] = seq->items[j];
            j--;
        }
        seq->items[j + 1] = item;
    }
    return alg_nil();
}

Value alg_keys(Value receiver) {
    ObjMap *map  = as_map(receiver, "Only a Map has 'Keys'.");
    Value   keys = alg_list();

    for (int32_t i = 0; i < map->count; i++) seq_append((ObjSeq *)keys.obj, map->entries[i].key);
    return keys;
}

Value alg_values(Value receiver) {
    ObjMap *map    = as_map(receiver, "Only a Map has 'Values'.");
    Value   values = alg_list();

    for (int32_t i = 0; i < map->count; i++) seq_append((ObjSeq *)values.obj, map->entries[i].value);
    return values;
}

Value alg_to_list(Value receiver) {
    ObjSeq *seq   = as_sequence(receiver, "Only a Set has 'ToList'.");
    Value   items = alg_list();

    for (int32_t i = 0; i < seq->count; i++) seq_append((ObjSeq *)items.obj, seq->items[i]);
    return items;
}

/* ------------------------------------------------------------ properties -- */

static int32_t count_of(Value v) {
    if (is_obj(v, OBJ_MAP))    return ((ObjMap *)v.obj)->count;
    if (is_sequence(v))        return ((ObjSeq *)v.obj)->count;
    if (is_text(v))            return utf8_count(v.string, v.length);

    /* A Buffer's Length is its size in bytes, never its capacity -- see the
     * Buffer section.  as_buffer is what makes Length on a freed one raise
     * rather than answering with a stale count. */
    if (is_obj(v, OBJ_BUFFER)) return (int32_t)as_buffer(v, "Length")->length;

    alg_error("Only a collection or a String has 'Length'.");
    return 0;
}

Value alg_length(Value v)   { return alg_int(count_of(v)); }
Value alg_is_empty(Value v) { return alg_bool(count_of(v) == 0); }

/* Length(X), the FUNCTION -- not the '.Length' property above, which is what
 * alg_length is.
 *
 * ⚠️ The two are spelled alike and are not the same operation, so they cannot
 * be one C function [RT-003].  Length measures TEXT and a collection has a
 * count, so 'Length ([10, 20, 30])' answered 12 here -- the length of the
 * rendering -- where '[10, 20, 30].Length' is 3.  A plausible NUMBER rather
 * than an error, and the two are never equal: a List of n one-digit numbers
 * renders as 3n characters.  LengthNative refuses it and this did not.
 *
 * Anything else is stringified, as LengthNative's 'Length (Str (...))' does, so
 * 'Length (42)' is 2. */
Value alg_text_length(Value v) {
    if (is_sequence(v) || is_obj(v, OBJ_MAP))
        alg_error("Length expects text; use .Length for a collection.");

    Value text = is_text(v) ? v : alg_str(v);

    return alg_int(utf8_count(text.string, text.length));
}

/* ------------------------------------------------------------- subscript -- */

Value alg_subscript_get(Value target, Value index) {
    if (is_obj(target, OBJ_MAP)) return alg_get(target, index);

    /* A byte, as an Integer 0..255 -- not a Char.  A Buffer is raw memory, and
     * the VM will index it to read opcodes; Text is how the text face is
     * reached, and it is the only thing here that produces a String. */
    if (is_obj(target, OBJ_BUFFER)) {
        ObjBuffer *buffer = as_buffer(target, "[]");
        return alg_int((unsigned char)buffer->bytes[buffer_offset(buffer, index, 1)]);
    }

    /* ⚠️ A Set has no positions, so it reports as though it were not a
     * collection at all -- it falls through to the same complaint anything
     * else without a subscript path gets, which is what ObjCollection.At does.
     * is_sequence covers it, so 'Set ([1, 2])[0]' answered 1 here. */
    if (is_obj(target, OBJ_SET)) alg_error("Subscript target should be an ordinal.");

    if (is_sequence(target)) {
        ObjSeq *seq = (ObjSeq *)target.obj;
        return seq->items[bounded(index, seq->count, false)];
    }
    if (is_text(target)) {
        /* ⚠️ Bounded in CHARACTERS and indexed in characters [SRC-004].  This
         * used to hand back one byte, so 'café'[3] was the first half of a
         * two-byte sequence rather than 'é'. */
        int32_t at = bounded(index, utf8_count(target.string, target.length), false);

        return alg_char_value(utf8_decode(target.string
                                          + utf8_offset(target.string, target.length, at)));
    }

    /* ⚠️ [TYP-010] pins this wording, and it is the interpreter's.  The text
     * here was 'Only a collection or a String can be subscripted.', which reads
     * better -- Annex D is where that argument belongs, not the runtime. */
    alg_error("Subscript target should be an ordinal.");
    return alg_nil();
}

Value alg_subscript_set(Value target, Value index, Value value) {
    if (is_obj(target, OBJ_MAP)) {
        map_put((ObjMap *)target.obj, index, value);
        return value;
    }
    if (is_obj(target, OBJ_BUFFER)) {
        ObjBuffer *buffer = as_buffer(target, "[]");
        size_t     at     = buffer_offset(buffer, index, 1);

        int32_t byte = as_integer(value, "A Buffer holds bytes, so the value must be an Integer.");
        if (byte < 0 || byte > 255) alg_error("A byte must be in 0..255.");

        buffer->bytes[at] = (char)byte;
        return value;
    }
    /* A Set has no positions on this side either -- see alg_subscript_get. */
    if (is_obj(target, OBJ_SET)) alg_error("Subscript target should be an ordinal.");

    if (is_sequence(target)) {
        ObjSeq *seq = (ObjSeq *)target.obj;

        seq->items[bounded(index, seq->count, false)] = value;
        return value;
    }

    /* ⚠️ A String is subscriptable and not assignable, and says so.  This
     * answered 'Only a collection can be subscripted.', which is false of the
     * receiver in front of it; VisitSetSubscriptExpr separates the two cases
     * for the same reason. */
    if (is_text(target)) alg_error("Strings are immutable.");

    alg_error("Subscript target should be an ordinal.");
    return alg_nil();
}

Value alg_in(Value needle, Value haystack) {
    if (is_obj(haystack, OBJ_MAP) || is_sequence(haystack)) return alg_contains(haystack, needle);

    if (is_text(haystack)) {
        if (!is_text(needle)) alg_error("Can only test a String against a String.");
        return alg_bool(strstr(as_text(haystack), as_text(needle)) != NULL);
    }

    if (has_method(haystack, "Contains", 1)) {
        return alg_bool(alg_truthy(alg_invoke(haystack, "Contains", &needle, 1)));
    }

    alg_error("Right operand of 'in' must be a collection or a String.");
    return alg_nil();
}

/* ------------------------------------------------------------- iteration --
 *
 * The collection is copied first, so mutating it inside the loop cannot change
 * what the loop walks -- the interpreter copies for the same reason.  A Map
 * yields its keys; a Stack yields bottom to top.
 */
Value alg_iterable(Value v) {
    if (is_obj(v, OBJ_MAP)) return alg_keys(v);

    if (is_obj(v, OBJ_ENUM_TYPE)) {
        ObjEnumType *type     = (ObjEnumType *)v.obj;
        Value        snapshot = alg_list();

        /* Declaration order. */
        for (int32_t i = 0; i < type->count; i++) seq_append((ObjSeq *)snapshot.obj, type->members[i]);
        return snapshot;
    }

    Value snapshot = alg_list();

    if (is_sequence(v)) {
        ObjSeq *seq = (ObjSeq *)v.obj;
        for (int32_t i = 0; i < seq->count; i++) seq_append((ObjSeq *)snapshot.obj, seq->items[i]);

        return snapshot;
    }
    if (is_text(v)) {
        for (const char *p = v.string; *p != '\0'; p++) {
            seq_append((ObjSeq *)snapshot.obj, alg_char_value((unsigned char)*p));
        }
        return snapshot;
    }

    /* Structural, not declared: any class with an Elements() method is
     * iterable.  Asked once, and the result walked -- never asked again of the
     * result, which is what stops a List whose Elements() returns a List from
     * recursing forever. */
    if (has_method(v, "Elements", 0)) {
        return alg_iterable(alg_invoke(v, "Elements", NULL, 0));
    }

    alg_error("Can only iterate a collection or a String.");
    return alg_nil();
}

int32_t alg_iterable_count(Value snapshot) {
    return ((ObjSeq *)snapshot.obj)->count;
}

Value alg_iterable_at(Value snapshot, int32_t index) {
    return ((ObjSeq *)snapshot.obj)->items[index];
}


/* ----------------------------------------------------------------- classes --
 *
 * A class is a name, an optional superclass, its own field names, its methods,
 * and a function that applies its field initializers.  Instances hold a flat
 * array of slots covering inherited fields first, then their own -- so a
 * subclass's slots sit above its parent's and a parent method reaches the same
 * index whichever subclass it is running on.
 */
typedef struct {
    const char *name;
    AlgMethod   fn;
    int32_t     arity;

    /* Declared parameter types, one per parameter, "Any" where none was
     * written -- NULL when the class was registered without them.  Selection
     * is on the whole signature, not on arity, so two methods of one name may
     * take one argument each and differ only in what kind. */
    const char **types;

    /* ⚠️ The name's hash, so the scan compares an int before it compares a
     * string.  find_method walks every method of every class in the chain --
     * 15.2 entries on average in algc, 2.2 BILLION strcmp calls for one
     * fib(30) -- and a strcmp is a call through the PLT where this is a load
     * and a compare.  Worth about a quarter of that program's run.
     *
     * ⚠️ Not an index, deliberately.  A per-class hash table was built and
     * measured: it cut the average scan from 15.2 entries to 1.00 and bought
     * 0.5%, because at that size a predictable walk over a contiguous int
     * array is already free.  The strings were the cost, not the search. */
    uint32_t    hash;
} MethodEntry;

typedef struct ObjClass {
    Obj obj;

    const char      *name;
    struct ObjClass *super;

    const char **fields;
    int32_t      field_count;

    /* Inherited fields included, so this is the size of an instance.
     *
     * ⚠️ Computed on first use and cached, NOT maintained as fields are added.
     * A class may be linked to a parent whose own fields are not registered yet
     * -- 'class Puppy (Hound);' written above 'class Hound;' [DCL-006] -- so
     * there is no moment during setup at which running totals would all be
     * right.  -1 means "not yet asked".  Safe because nothing instantiates a
     * class until every init_<Unit>() has run. */
    int32_t total_fields;

    MethodEntry *methods;
    int32_t      method_count;
    int32_t      method_capacity;

    AlgMethod initializer;

    /* An 'object' declaration.  The instance is built on first reference, not at
     * registration, so one object may name another declared later. */
    bool  is_object;
    bool  built;
    Value instance;
} ObjClass;

typedef struct {
    Obj       obj;
    ObjClass *klass;
    Value    *slots;
} ObjInstance;

static ObjClass *as_class(Value v, const char *what) {
    if (!is_obj(v, OBJ_CLASS)) alg_error(what);
    return (ObjClass *)v.obj;
}

Value alg_class(const char *name, Value super) {
    ObjClass *klass = arena_alloc(sizeof(ObjClass));

    klass->obj.type        = OBJ_CLASS;
    klass->name            = name;
    klass->super           = super.type == VAL_NIL ? NULL : as_class(super, "Superclass must be a class.");
    klass->fields          = NULL;
    klass->field_count     = 0;
    klass->methods         = NULL;
    klass->method_count    = 0;
    klass->method_capacity = 0;
    klass->initializer     = NULL;
    klass->is_object       = false;
    klass->built           = false;
    klass->total_fields    = -1;

    return object((Obj *)klass);
}

/* Links a class to its parent, after both shells exist.
 *
 * ⚠️ Separate from alg_class because a class may inherit from one declared
 * BELOW it [DCL-006]: the interpreter binds every class as an empty shell and
 * fills it in where its declaration stands, so the child holds the finished
 * parent because it is the same object.  The emitter now does the same -- every
 * shell first, then the links, then the fields and methods -- and passing the
 * parent to alg_class could only ever see a handle that was still nil. */
/* That the name a class inherits from is bound yet.
 *
 * ⚠️ A handle is nil until its own shell runs, and a module's shells run when
 * its 'uses' does [INI-003] -- so a class inheriting from a module named BELOW
 * it is linked to nothing, which is exactly the program the interpreter refuses
 * with 'Undefined variable'.  Separate from alg_class_super so that this
 * reports the NAME the program wrote: a nil handle knows nothing about itself.
 *
 * ⚠️ The interpreter refuses the same program for the same reason.  Hoist
 * builds a class ahead of the statements only when its parent is absent or is
 * another class of the same file; one inheriting from anything else is left
 * where it stands, and there the name is simply not bound yet. */
void alg_class_declared(Value klass, const char *name) {
    if (klass.type != VAL_NIL) return;

    char message[256];
    snprintf(message, sizeof message, "Undefined variable '%s'.", name);

    alg_error(message);
}

void alg_class_super(Value value, Value super) {
    ObjClass *klass = as_class(value, "Expected a class.");

    klass->super        = as_class(super, "Superclass must be a class.");
    klass->total_fields = -1;
}

/* Instance size: this class's fields and every ancestor's.  Memoized -- see the
 * note on the field. */
static int32_t total_fields(ObjClass *klass) {
    if (klass->total_fields < 0)
        klass->total_fields = klass->field_count
                            + (klass->super == NULL ? 0 : total_fields(klass->super));

    return klass->total_fields;
}

void alg_class_field(Value value, const char *name) {
    ObjClass *klass = as_class(value, "Expected a class.");

    /* ⚠️ Does NOT invalidate total_fields, and deliberately: a partial
     * invalidation would not be enough anyway -- a child's cached total would
     * still be stale after its PARENT gained a field -- and would read as a
     * guarantee this does not make.  What makes the cache safe is that setup
     * finishes before anything is instantiated, not anything done here.
     *
     * Field lists are short and fixed at startup, so this grows by one rather
     * than doubling. */
    const char **fields = arena_alloc((size_t)(klass->field_count + 1) * sizeof(char *));
    if (klass->field_count > 0) {
        memcpy(fields, klass->fields, (size_t)klass->field_count * sizeof(char *));
    }
    fields[klass->field_count] = name;

    klass->fields = fields;
    klass->field_count++;
}

void alg_class_method(Value value, const char *name, AlgMethod fn, int32_t arity,
                      const char **types) {
    ObjClass *klass = as_class(value, "Expected a class.");

    if (klass->method_count == klass->method_capacity) {
        int32_t      capacity = klass->method_capacity < 8 ? 8 : klass->method_capacity * 2;
        MethodEntry *methods  = arena_alloc((size_t)capacity * sizeof(MethodEntry));

        if (klass->method_count > 0) {
            memcpy(methods, klass->methods, (size_t)klass->method_count * sizeof(MethodEntry));
        }
        klass->methods         = methods;
        klass->method_capacity = capacity;
    }
    klass->methods[klass->method_count].name  = name;
    klass->methods[klass->method_count].fn    = fn;
    klass->methods[klass->method_count].arity = arity;
    klass->methods[klass->method_count].types = types;
    klass->methods[klass->method_count].hash  = hash_folded(name);
    klass->method_count++;
}

void alg_class_is_object(Value value) {
    as_class(value, "Expected a class.")->is_object = true;
}

void alg_class_initializer(Value value, AlgMethod fn) {
    as_class(value, "Expected a class.")->initializer = fn;
}

/* Slot of a field name, or -1.  Own fields sit above inherited ones, and a
 * subclass redeclaring a name shadows the parent's slot -- searching from the
 * top down finds the subclass's first, which is what the interpreter does when
 * it applies inherited initializers before its own. */
static int32_t field_slot(ObjClass *klass, const char *name) {
    for (ObjClass *at = klass; at != NULL; at = at->super) {
        int32_t base = at->super == NULL ? 0 : total_fields(at->super);

        for (int32_t i = 0; i < at->field_count; i++) {
            /* ⚠️ Compared WITHOUT REGARD TO CASE [SRC-011].  The first-byte
             * skip that used to open this could not survive the fold -- 'V' and
             * 'v' differ as bytes and name one field -- so the whole comparison
             * goes through alg_stricmp, which stops at the first difference
             * anyway.  Field lists average 1.8 entries. */
            if (alg_stricmp(at->fields[i], name) == 0) return base + i;
        }
    }
    return -1;
}

/* Methods overload on arity, so the count selects between two of the same name.
 * A name-only match is kept as a fallback purely so the caller can report a
 * wrong-argument-count error rather than an undefined method. */
/* Whether a value is an instance whose class answers to this name and arity.
 * The protocols are structural -- Algol-24 has no interfaces, so conforming is
 * a matter of having the method, not of declaring anything. */
static bool has_method(Value v, const char *name, int32_t arity);

static MethodEntry *find_method(ObjClass *klass, const char *name, int32_t arity, Value *args, bool strict);
static Value alg_bound(Value receiver, MethodEntry *method);
static const char *type_name(Value v);

/* One row of a member table: the member's canonical spelling and how many
 * arguments it takes.  See member_of. */
typedef struct {
    const char *name;
    int32_t     arity;
} Member;

/* A built-in member and the callable a bare read of one binds to -- see the
 * notes on their definitions. */
static const Member *member_of(Value receiver, const char *name);
static Value builtin_bound(Value receiver, const char *name, int32_t arity);

static bool has_method(Value v, const char *name, int32_t arity) {
    if (!is_obj(v, OBJ_INSTANCE)) return false;

    return find_method(((ObjInstance *)v.obj)->klass, name, arity, NULL, false) != NULL;
}

/* Whether a value stands where a class of this name is declared -- itself, or
 * anything that inherits from it. */
static bool is_a(Value v, const char *name) {
    if (!is_obj(v, OBJ_INSTANCE)) return false;

    for (ObjClass *at = ((ObjInstance *)v.obj)->klass; at != NULL; at = at->super) {
        if (alg_stricmp(at->name, name) == 0) return true;
    }
    return false;
}

/* Whether these arguments fit a method's declared parameter types.
 *
 * The rule is PascalFunction.isMatch's, and has to stay that way: 'Any' means
 * "not known" and is compatible in BOTH directions, nil inhabits every type,
 * and a subclass stands where its parent is declared.  Every parameter is
 * checked, against the argument in its own position.
 *
 * ⚠️ Allocates nothing.  This runs on every call to an overloaded method, and
 * the runtime has no collector -- anything allocated here would accumulate for
 * the life of the process.  type_name hands back a static string or a class's
 * own name, and the scan is over the method table that already exists. */
/* Whether an argument of this type may be passed where 'declared' is written,
 * by WIDENING [VAR-004] -- an Integer where a Double is asked for, a Char where
 * a String is.  A parameter is an assignment context [VAR-017]. */
/* A subrange: a name with a low and a high bound [TYP-015], [TYP-016].
 *
 * ⚠️ A subrange is a CONSTRAINT on an Integer, not a type of its own.  Nothing
 * is ever "a Byte" at run time -- type_name still answers "Integer" -- so the
 * name appears only where a type is WRITTEN, and the bounds are checked there.
 *
 * ⚠️ There is NO predefined table here, and there used to be one holding Byte,
 * Word and Short.  It was a second copy of Token.a24's, kept in step by nothing
 * but a conformance case -- so the emitter registers all of them instead, the
 * built-in three by exactly the route a program's own take.  Deleting a copy
 * beats checking a copy.
 *
 * ⚠️ The bounds are VALUES, not int64s, so a bound may be any Integer [LEX-018].
 * They arrive as decimal TEXT for the same reason a wide literal does: C cannot
 * spell one past its own width, and alg_integer rebuilds it through the
 * arithmetic that promotes. */
typedef struct {
    const char *name;
    Value       low;
    Value       high;
} Subrange;

/* Fixed capacity rather than growable: this is filled once at startup, before
 * any statement runs, and a program with 64 subrange declarations is not the
 * program this language is for. */
#define ALG_SUBRANGE_MAX 64

static Subrange declared_subranges[ALG_SUBRANGE_MAX];
static int32_t  declared_count = 0;

void alg_subrange(const char *name, const char *low, const char *high) {
    Value from = alg_integer(low);
    Value to   = alg_integer(high);

    for (int32_t i = 0; i < declared_count; i++)
        if (alg_stricmp(name, declared_subranges[i].name) == 0) {
            declared_subranges[i].low  = from;
            declared_subranges[i].high = to;
            return;
        }

    if (declared_count == ALG_SUBRANGE_MAX) alg_error("Too many subrange declarations.");

    declared_subranges[declared_count].name = name;
    declared_subranges[declared_count].low  = from;
    declared_subranges[declared_count].high = to;
    declared_count++;
}

static const Subrange *subrange_of(const char *name) {
    if (name == NULL) return NULL;

    for (int32_t i = 0; i < declared_count; i++)
        if (alg_stricmp(name, declared_subranges[i].name) == 0) return &declared_subranges[i];

    return NULL;
}

/* ⚠️ Only an Integer lies within one, and the comparison is the language's own
 * -- so a bound past the machine's width works exactly as any other Integer
 * does.  Comparing int64s here would have made every value past 2^63 fall
 * outside every subrange, whatever its bounds said. */
static bool in_subrange(Value v, const Subrange *range) {
    if (!is_integer(v)) return false;

    return alg_truthy(alg_greater_equal(v, range->low))
        && alg_truthy(alg_less_equal(v, range->high));
}

/* The type a written name stands for once a subrange is seen through.
 *
 * ⚠️ A subrange is an Integer for every question about TYPE and keeps its own
 * name for the question about RANGE, which is why this is not the same as
 * replacing an alias -- collapsing the two would lose the bounds. */
static const char *underlying_type(const char *name) {
    return subrange_of(name) != NULL ? "Integer" : name;
}

_Noreturn static void out_of_subrange(Value v, const char *name) {
    char message[128];
    snprintf(message, sizeof message, "%s is not in %s.", as_text(v), name);

    alg_error(message);
}

static bool widens_to(const char *actual, const char *declared) {
    if (alg_stricmp(declared, "Double") == 0 && alg_stricmp(actual, "Integer") == 0) return true;
    if (alg_stricmp(declared, "String") == 0 && alg_stricmp(actual, "Char") == 0)    return true;

    return false;
}

/* Binds one argument to a declared parameter type: raises where it does not fit,
 * and CONVERTS where it fits by widening.
 *
 * ⚠️ In the callee, not at the call site, which is what lets one place answer
 * both faults.  A compiled call to a top-level subprogram checked the argument
 * COUNT and nothing else (C-24), and an argument that fitted by widening was
 * passed unconverted, so a parameter declared Double held an Integer (C-25).
 *
 * ⚠️ An untyped parameter, 'Any', and a nil argument all pass untouched, which
 * is the gradual half of the language [VAR-005], [VAR-006]. */
/* CONVERTS and nothing else: a value that does not fit is handed back
 * untouched.
 *
 * ⚠️ The two jobs are separate, and conflating them broke the bootstrap.  The
 * interpreter's Widen only converts; the CHECK lives at overload selection and
 * in the TypeChecker.  A constructor's signature is deliberately unchecked
 * [see find_method's 'strict'], so a String reaching a field declared 'Expr' is
 * a shape real programs use -- refusing it here made the compiler unable to
 * build itself. */
Value alg_widen(Value argument, const char *declared) {
    if (declared == NULL || *declared == '\0') return argument;

    /* ⚠️ A subrange CHECKS here, where nothing else in this function refuses
     * anything -- and that is safe for a reason worth stating.  Making this
     * refuse on a TYPE mismatch broke the compiler twice (C-24, C-25), because
     * a String reaching a field declared 'Expr' is a shape real programs use.
     * A RANGE check cannot fire on that shape: it applies only when the
     * declared name is a subrange and the value is already an Integer. */
    const Subrange *range = subrange_of(declared);
    if (range != NULL) {
        if (argument.type == VAL_INT && !in_subrange(argument, range))
            out_of_subrange(argument, declared);

        return argument;
    }

    const char *actual = type_name(argument);
    if (!widens_to(actual, declared)) return argument;

    if (alg_stricmp(declared, "Double") == 0) return alg_double((double)argument.integer);

    /* A Char already holds its text; widening is the tag. */
    Value widened = argument;
    widened.type  = VAL_STRING;
    return widened;
}

/* Widens, and REFUSES what does not fit.
 *
 * ⚠️ Only a top-level subprogram's parameters go through this.  A method's are
 * checked when the overload is selected, and a constructor's are deliberately
 * not checked at all; a top-level subprogram has no selection step, so the
 * check has nowhere else to live [FUN-006]. */
Value alg_param(Value argument, const char *declared) {
    if (declared == NULL || *declared == '\0') return argument;
    if (alg_stricmp(declared, "Any") == 0)      return argument;

    /* Seen through for the TYPE question and checked for the RANGE one. */
    if (subrange_of(declared) != NULL) return alg_widen(argument, declared);

    const char *actual = type_name(argument);
    if (alg_stricmp(actual, "nil") == 0) return argument;
    if (alg_stricmp(actual, "Any") == 0) return argument;
    if (alg_stricmp(actual, declared) == 0) return argument;

    if (widens_to(actual, declared)) return alg_widen(argument, declared);
    if (is_a(argument, declared)) return argument;

    alg_error("No matching signature for function.");
}

/* ⚠️ 'widening' is what separates the two passes of overload selection.  An
 * exact match is PREFERRED [EXP-014], so a Char argument takes a Char overload
 * rather than a String one however they are declared; admitting the widening in
 * a single pass would let declaration order decide.  The interpreter's Fits
 * takes the same flag for the same reason. */
/* Whether these arguments fit these declared parameter types.
 *
 * ⚠️ Takes the type array rather than a MethodEntry, because a top-level
 * subprogram overloads on the whole signature too [FUN-013] and selection is
 * one rule -- 'never on arity, and everywhere the same'.  It carries the types
 * in an ObjOverloads entry instead of a method table, and asks this. */
/* Splits a declared type into its base and its element type: "List of Integer"
 * gives "List" in 'base' and a pointer to "Integer".  A type with no element
 * type is copied whole and NULL comes back.
 *
 * ⚠️ The element type travels INSIDE the declared type string [FUN-005], which
 * is what let alg_overload and alg_class_method keep their signatures and every
 * emitted call site keep its shape.  The price is that everything comparing a
 * declared type has to stop at " of ", so nothing may compare types[i] raw. */
/* The parameter name a declaration carries -- the "Level" of
 * "Level : List of Integer" -- or NULL when it carries none.
 *
 * ⚠️ A parameter's NAME travels inside the declared type string, beside its
 * element type, so the array alg_overload and alg_class_method take is simply
 * the parameter list as the source writes it.  Neither had to grow an argument
 * for names any more than it did for element types [EXP-013]. */
static const char *param_name(const char *declared, char *out, size_t size) {
    if (declared == NULL) return NULL;

    const char *colon = strstr(declared, " : ");
    if (colon == NULL) return NULL;

    size_t head = (size_t)(colon - declared);
    if (head >= size) head = size - 1;

    memcpy(out, declared, head);
    out[head] = '\0';

    return out;
}

/* The type half of a parameter declaration, past any name it carries. */
static const char *type_part(const char *declared) {
    if (declared == NULL) return NULL;

    const char *colon = strstr(declared, " : ");

    return (colon != NULL) ? colon + 3 : declared;
}

static const char *split_type(const char *declared, char *base, size_t size) {
    declared = type_part(declared);

    if (declared == NULL) {
        base[0] = '\0';
        return NULL;
    }

    const char *of = strstr(declared, " of ");
    size_t head = (of != NULL) ? (size_t)(of - declared) : strlen(declared);

    if (head >= size) head = size - 1;

    memcpy(base, declared, head);
    base[head] = '\0';

    return (of != NULL) ? of + 4 : NULL;
}

/* Whether one argument stands where a parameter of this type is declared.
 *
 * ⚠️ Lifted out of types_match so that ABSORPTION asks the same question of a
 * gathered argument that selection asks of a positional one -- the interpreter's
 * ObjFunction.FitsAt, which this has to keep agreeing with. */
static bool type_fits(const char *declared, Value argument, bool widening) {
    /* ⚠️ Seen through, so selection IGNORES a subrange's bounds [FUN-013].
     * Consulting them would send 'Take (200)' and 'Take (300)' to different
     * subprograms, and would let ADDING an overload steal calls from one that
     * was already there. */
    const char *wanted = underlying_type(declared);
    if (wanted == NULL || alg_stricmp(wanted, "Any") == 0) return true;

    const char *actual = type_name(argument);
    if (alg_stricmp(actual, "Any") == 0) return true;
    if (alg_stricmp(actual, "nil") == 0) return true;
    if (alg_stricmp(wanted, actual) == 0) return true;

    if (is_a(argument, wanted)) return true;

    return widening && widens_to(actual, wanted);
}

static bool types_match(const char **types, Value *args, int32_t count, bool widening) {
    if (args == NULL || types == NULL) return true;

    for (int32_t i = 0; i < count; i++) {
        char base[64];

        split_type(types[i], base, sizeof base);
        if (!type_fits(base, args[i], widening)) return false;
    }
    return true;
}

/* The element type of a last parameter that may gather trailing arguments, or
 * NULL when the signature has none [FUN-005].
 *
 * ⚠️ An ELEMENT TYPE is what makes a parameter absorbing, so a bare "List" does
 * not absorb: there would be nothing to check the gathered arguments against,
 * and it leaves "List" as the spelling for a parameter that wants the list
 * itself and nothing else. */
static const char *variadic_element(const char **types, int32_t arity) {
    if (types == NULL || arity <= 0) return NULL;

    static char base[64];
    const char *element = split_type(types[arity - 1], base, sizeof base);

    if (element == NULL) return NULL;
    if (alg_stricmp(base, "List") != 0) return NULL;

    return element;
}

/* Whether these arguments fit by gathering the trailing ones [FUN-005].
 *
 * ⚠️ The element type replaces the arity check and is STRICTER than it:
 * 'Log ("warn", 1, 2, "red")' is still refused against 'List of Integer'. */
static bool types_absorb(const char **types, int32_t arity, Value *args, int32_t count) {
    const char *element = variadic_element(types, arity);
    if (element == NULL) return false;

    int32_t fixed = arity - 1;
    if (count < fixed) return false;

    if (!types_match(types, args, fixed, true)) return false;

    for (int32_t i = fixed; i < count; i++)
        if (!type_fits(element, args[i], true)) return false;

    return true;
}

/* Whether any argument named the parameter it fills [EXP-013].
 *
 * ⚠️ Asked FIRST everywhere, because nothing is named in the overwhelming
 * majority of calls and that case must cost nothing. */
static bool any_named(const char **names, int32_t count) {
    if (names == NULL) return false;

    for (int32_t i = 0; i < count; i++)
        if (names[i] != NULL && names[i][0] != '\0') return true;

    return false;
}

/* The position of the parameter of this name, or -1.
 *
 * ⚠️ Folded [SRC-011].  A parameter is a name like any other, so 'F (level: 1)'
 * and 'F (Level: 1)' fill the same one. */
static int32_t parameter_at(const char **types, int32_t arity, const char *name) {
    if (types == NULL) return -1;

    for (int32_t i = 0; i < arity; i++) {
        char declared[64];

        if (param_name(types[i], declared, sizeof declared) == NULL) continue;
        if (alg_stricmp(declared, name) == 0) return i;
    }

    return -1;
}

/* The arguments in declaration order, or NULL when the names do not fit this
 * signature [EXP-013].  Mirrors ObjFunction.Arrange, which it has to agree
 * with exactly.
 *
 * ⚠️ NULL rather than an error, because with an overload set a name that fits
 * no candidate here may fit the next one.  Selection asks each candidate and
 * the CALL reports the failure. */
static Value *arrange_args(const char **types, int32_t arity,
                           Value *args, int32_t count, const char **names) {
    if (arity < 0 || arity > 255) return NULL;

    Value *slots  = arena_alloc((size_t)(arity > 0 ? arity : 1) * sizeof(Value));
    bool   filled[256];

    for (int32_t i = 0; i < arity; i++) filled[i] = false;

    for (int32_t i = 0; i < count; i++) {
        const char *name = (names != NULL) ? names[i] : NULL;

        /* ⚠️ A positional argument goes to slot i, and that is correct only
         * because positional arguments come FIRST [EXP-013] -- they fill
         * 0..k-1 in order, and naming begins after them. */
        int32_t at = i;
        if (name != NULL && name[0] != '\0') at = parameter_at(types, arity, name);

        if (at < 0 || at >= arity) return NULL;
        if (filled[at]) return NULL;

        slots[at]  = args[i];
        filled[at] = true;
    }

    for (int32_t i = 0; i < arity; i++)
        if (!filled[i]) return NULL;

    return slots;
}

/* Mirrors ObjFunction.Absorb: the earlier passes are asked again, so a call
 * that fits WITHOUT gathering is left alone [EXP-014]. */
static bool should_absorb(const char **types, int32_t arity, Value *args, int32_t count) {
    if (arity == count && types_match(types, args, count, true)) return false;

    return types_absorb(types, arity, args, count);
}

/* The arguments with the trailing ones gathered into a List [FUN-005].
 *
 * ⚠️ Gathering NOTHING yields the empty list, which is what makes 'WriteLn ()'
 * an ordinary call rather than a special case.  The list is STRUCTURAL and not
 * a default: gathering none gives [] by the same rule that gathering three
 * gives a list of three. */
static Value *absorb_args(int32_t arity, Value *args, int32_t count) {
    Value  *gathered = arena_alloc((size_t)arity * sizeof(Value));
    int32_t fixed    = arity - 1;

    for (int32_t i = 0; i < fixed; i++) gathered[i] = args[i];

    Value rest = alg_list();
    for (int32_t i = fixed; i < count; i++) rest = alg_list_keep(rest, args[i]);

    gathered[fixed] = rest;

    return gathered;
}

static bool signature_matches(MethodEntry *entry, Value *args, int32_t count, bool widening) {
    return types_match(entry->types, args, count, widening);
}

/* Selects a method by name, then by signature.
 *
 * Three answers in descending order of confidence: the signature that fits, any
 * method of the right arity, and failing both a method of that name at all --
 * kept only so a wrong-argument-count error reads better than "undefined
 * property".
 *
 * The class chain is walked outermost-first, so a subclass override is found
 * before the parent's.  Within one class the scan runs forwards, so when two
 * overloads both fit the FIRST declared wins -- which is what the interpreter
 * does, where the first declaration is the PascalFunction and later ones are
 * its overloads. */
static MethodEntry *find_method(ObjClass *klass, const char *name, int32_t arity, Value *args, bool strict) {
    MethodEntry *named    = NULL;
    MethodEntry *by_arity = NULL;

    uint32_t want = hash_folded(name);

    /* ⚠️ THREE PASSES over the WHOLE chain, exact then widening then absorbing
     * [EXP-014].  An exact match on a parent must beat a widened match on a
     * child, or adding an overload to a subclass would silently capture calls
     * the parent was answering exactly.  One pass admitting widening would also
     * let declaration order decide which overload a Char reaches, and one
     * admitting absorption would let a variadic signature take a call a
     * fixed-arity one answers exactly. */
    for (int pass = 0; pass < 3; pass++) {
        for (ObjClass *at = klass; at != NULL; at = at->super) {
            for (int32_t i = 0; i < at->method_count; i++) {
                if (at->methods[i].hash != want) continue;
                if (alg_stricmp(at->methods[i].name, name) != 0) continue;

                /* ⚠️ The absorbing pass does not test the arity, because an
                 * absorbing call has a different one by design -- that is what
                 * it is.  Its rule is the element type instead. */
                if (pass == 2) {
                    if (types_absorb(at->methods[i].types, at->methods[i].arity, args, arity))
                        return &at->methods[i];

                    continue;
                }

                if (at->methods[i].arity == arity) {
                    if (signature_matches(&at->methods[i], args, arity, pass == 1)) {
                        return &at->methods[i];
                    }
                    if (by_arity == NULL) by_arity = &at->methods[i];
                }
                if (named == NULL) named = &at->methods[i];
            }
        }
    }
    /* ⚠️ Arity matched and no signature did.  Handing back the arity match runs
     * a body the interpreter refuses to run: 'Show(Integer)' beside
     * 'Show(String)' called with 3.5 printed "Integer branch: 3.5" compiled and
     * raised "No matching signature for function." interpreted.  It is not only
     * the two-overload case -- with ONE method it is every argument whose type
     * does not match, so 'TakesDouble(3)' and 'TakesString('c')' were refused
     * interpreted and accepted compiled.
     *
     * ⚠️ 'strict' is FALSE for a constructor, and that asymmetry belongs to the
     * language rather than to this function.  A METHOD's signature is checked
     * and a CONSTRUCTOR's is not: 'Holder('a string')' against
     * 'Init(V : Base)' is accepted, while 'H.Take('a string')' against
     * 'Take(V : Base)' is refused.  Programs depend on it: a 'LiteralExpr'
     * declaring 'Init(Value : Expr)' and constructed with a String at every
     * literal is the shape that made this unconditional check fail.
     *
     * ⚠️ The rung BELOW this one, 'named', is a different thing and is kept.
     * Its comment -- "so a wrong-argument-count error reads better than
     * 'undefined property'" -- justifies improving a MESSAGE for a call that
     * fails either way.  It does not justify making a failing call succeed,
     * which is what this rung did. */
    if (by_arity != NULL) {
        if (strict) alg_error("No matching signature for function.");

        return by_arity;
    }

    return named;
}

/* [EXP-011]'s wording, in the one place that builds it.
 *
 * ⚠️ Two different failures, and they are not interchangeable.  A subprogram
 * with ONE signature reports the counts, because there is nothing to select
 * between and the count is the whole story.  A METHOD reports 'No matching
 * signature for function.', because arity is only part of what it selects on
 * and a wrong count is simply one way for nothing to fit -- the interpreter
 * reaches that message through FindOverload answering nothing. */
_Noreturn static void arity_error(int32_t expected, int32_t got) {
    char message[64];
    snprintf(message, sizeof message, "Expected %d arguments but got %d.", (int)expected, (int)got);

    alg_error(message);
}

void alg_arity(int32_t got, int32_t expected) {
    if (got != expected) arity_error(expected, got);
}

/* A file-scope variable read before its declaration has run [DCL-016].
 *
 * ⚠️ A variable is NOT hoisted, and a function, class and enum are [DCL-006].
 * One mechanism served all four here -- every top-level name is a C file-scope
 * symbol, so it exists from the start of the program -- which made this back
 * end right about three kinds of declaration and wrong about the fourth.  A
 * variable simply held nil until its initializer ran, so the program continued
 * with a VALUE where the language has a diagnostic.
 *
 * ⚠️ The flag is a bool rather than a sentinel Value, so nothing the language
 * can hold ever means "not yet declared".  A sentinel could be printed,
 * compared or widened by any read the emitter failed to guard; the worst a
 * missed guard can do here is what the emitter already did. */
void alg_declared(bool defined, const char *name) {
    if (defined) return;

    char message[256];
    snprintf(message, sizeof message, "Undefined variable '%s'.", name);

    alg_error(message);
}

/* Applies declared field values, inherited ones first, so a subclass
 * redeclaring a field wins. */
static void initialize_fields(ObjClass *klass, Value self) {
    if (klass->super != NULL) initialize_fields(klass->super, self);

    if (klass->initializer != NULL) klass->initializer(self, NULL, 0);
}

Value alg_new(Value value, Value *args, int32_t count) {
    ObjClass *klass = as_class(value, "Can only construct a class.");

    ObjInstance *instance = arena_alloc(sizeof(ObjInstance));
    instance->obj.type = OBJ_INSTANCE;
    instance->klass    = klass;
    int32_t slots = total_fields(klass);

    instance->slots = slots == 0 ? NULL : arena_alloc((size_t)slots * sizeof(Value));

    /* A field declared without a value is nil rather than absent, so reading it
     * is not an error. */
    for (int32_t i = 0; i < slots; i++) instance->slots[i] = alg_nil();

    Value self = object((Obj *)instance);

    initialize_fields(klass, self);

    MethodEntry *init = find_method(klass, "Init", count, args, false);
    if (init != NULL) {
        /* ⚠️ [EXP-011]'s wording here too.  This said 'Wrong number of
         * arguments to Init.', which names the constructor helpfully and is a
         * message the interpreter cannot produce -- construction reports the
         * counts like any other call. */
        alg_arity(count, init->arity);
        init->fn(self, args, count);
    }
    else if (count != 0) {
        /* A class with no constructor takes none, so the expected count is
         * zero. */
        arity_error(0, count);
    }
    return self;
}

Value alg_singleton(Value value) {
    ObjClass *klass = as_class(value, "Expected an object.");

    if (!klass->built) {
        /* Marked built before constructing, so an object whose own initializer
         * reaches back to it sees the same instance rather than recursing. */
        klass->built    = true;
        klass->instance = alg_new(value, NULL, 0);
    }
    return klass->instance;
}

/* -------------------------------------------------------------- enums -- */

Value alg_enum_type(const char *name) {
    ObjEnumType *type = arena_alloc(sizeof(ObjEnumType));

    type->obj.type = OBJ_ENUM_TYPE;
    type->name     = name;
    type->members  = NULL;
    type->count    = 0;
    type->capacity = 0;

    return object((Obj *)type);
}

Value alg_enum_member(Value value, const char *name) {
    if (!is_obj(value, OBJ_ENUM_TYPE)) alg_error("Expected an enum type.");

    ObjEnumType *type = (ObjEnumType *)value.obj;

    ObjEnum *member = arena_alloc(sizeof(ObjEnum));
    member->obj.type = OBJ_ENUM;
    member->type     = type->name;
    member->name     = name;
    member->ordinal  = type->count;

    if (type->count == type->capacity) {
        int32_t capacity = type->capacity < 8 ? 8 : type->capacity * 2;
        Value  *members  = arena_alloc((size_t)capacity * sizeof(Value));

        if (type->count > 0) memcpy(members, type->members, (size_t)type->count * sizeof(Value));

        type->members  = members;
        type->capacity = capacity;
    }

    /* Interned: the qualified form hands back the very object the bare name is
     * bound to, so comparing them by identity succeeds. */
    Value bound = object((Obj *)member);
    type->members[type->count++] = bound;

    return bound;
}

/* ---------------------------------------------------------------- files --
 *
 * Turbo Pascal's text-file API, with the handle as the receiver.  See algol.h.
 *
 * The messages are part of the language rather than diagnostics: a failure
 * inside a 'try' is catchable as a String, so every one of these has to read
 * exactly as the interpreter's does.
 */
typedef struct ObjFile {
    Obj obj;

    const char *name;     /* assigned name; "" until Assign */
    FILE       *handle;
    bool        reading;

    /* Every file ever made, so alg_shutdown can close the ones a program left
     * open.  Threaded rather than tracked separately because an ObjFile is
     * arena-allocated and outlives every close anyway. */
    struct ObjFile *next;

    /* One line of lookahead, so Eof can answer before ReadLn is called.  Turbo
     * Pascal's Eof is a position query and must be true *at* the end rather
     * than after a failed read, which a line reader cannot know without having
     * looked. */
    char       *lookahead;
    bool        looked;
} ObjFile;

static ObjFile *all_files = NULL;

Value alg_text_file(void) {
    ObjFile *file = arena_alloc(sizeof(ObjFile));

    file->obj.type  = OBJ_FILE;
    file->name      = "";
    file->handle    = NULL;
    file->reading   = false;
    file->lookahead = NULL;
    file->looked    = false;

    file->next  = all_files;
    all_files   = file;

    return object((Obj *)file);
}

/* Closes anything a program left open.  Not an error: a program is allowed to
 * end without closing, and the process is still expected to give the handle
 * back. */
static void close_open_files(void) {
    for (ObjFile *file = all_files; file != NULL; file = file->next) {
        if (file->handle != NULL) {
            fclose(file->handle);
            file->handle = NULL;
        }
    }
    all_files = NULL;
}

/* "Reset failed: cannot open 'x'." and friends, built where the name varies. */
_Noreturn static void file_error(const char *what, const char *detail, const char *name) {
    char message[512];
    snprintf(message, sizeof message, "%s failed: %s'%s'.", what, detail, name);
    alg_error(message);
}

static void file_closed(ObjFile *file, const char *what) {
    if (file->handle != NULL) {
        char message[128];
        snprintf(message, sizeof message, "%s failed: the file is already open.", what);
        alg_error(message);
    }
}

static void file_named(ObjFile *file, const char *what) {
    if (file->name[0] == '\0') {
        char message[128];
        snprintf(message, sizeof message, "%s failed: no file has been assigned.", what);
        alg_error(message);
    }
}

static void file_reading(ObjFile *file, const char *what) {
    if (file->handle == NULL || !file->reading) {
        char message[128];
        snprintf(message, sizeof message, "%s failed: the file is not open for reading.", what);
        alg_error(message);
    }
}

static void file_writing(ObjFile *file, const char *what) {
    if (file->handle == NULL || file->reading) {
        char message[128];
        snprintf(message, sizeof message, "%s failed: the file is not open for writing.", what);
        alg_error(message);
    }
}

static void file_open(ObjFile *file, const char *what, const char *mode, bool reading) {
    file_closed(file, what);
    file_named(file, what);

    file->handle = fopen(file->name, mode);
    if (file->handle == NULL) file_error(what, "cannot open ", file->name);

    file->reading   = reading;
    file->lookahead = NULL;
    file->looked    = false;
}

/* The next line, or NULL at end of file.
 *
 * A line ends at '\n', which is not returned.  A '\r' immediately before it is
 * the other half of a CRLF pair and comes off with it; any other '\r' is
 * ordinary text.  That is the rule the scanner follows too -- #13 is
 * whitespace there and only #10 advances the line count -- rather than a
 * reader that also ends a line at a lone '\r', which would put the two halves
 * of the language at odds about one character. */
static char *file_read_line(ObjFile *file) {
    size_t capacity = 128;
    size_t length   = 0;
    char  *line     = arena_alloc(capacity);

    bool any = false;
    int  c;

    while ((c = fgetc(file->handle)) != EOF) {
        any = true;

        if (c == '\n') break;

        if (length + 1 >= capacity) {
            /* The arena does not resize, so growing copies into a fresh block
             * and abandons this one -- the same trade the collections make. */
            size_t bigger = capacity * 2;
            char  *moved  = arena_alloc(bigger);

            memcpy(moved, line, length);
            line     = moved;
            capacity = bigger;
        }
        line[length++] = (char)c;
    }

    if (!any) return NULL;

    if (length > 0 && line[length - 1] == '\r') length--;

    line[length] = '\0';
    return line;
}

static char *file_peek(ObjFile *file) {
    if (!file->looked) {
        file->lookahead = file_read_line(file);
        file->looked    = true;
    }
    return file->lookahead;
}

/* Eof, reached through alg_property because it is written without parentheses. */
static Value file_eof(ObjFile *file) {
    /* On an output file this is always true, as it is in Turbo Pascal: the
     * position is always the end. */
    if (file->handle != NULL && !file->reading) return alg_bool(true);

    file_reading(file, "Eof");
    return alg_bool(file_peek(file) == NULL);
}

static const char *file_name_argument(Value value) {
    if (value.type != VAL_STRING && value.type != VAL_CHAR) {
        alg_error("A file name must be a String.");
    }
    return value.string;
}

/* Methods, reached by name.  Kept beside the collections' table for the same
 * reason: only the receiver says whether 'Close' is a file's or a class's. */
static bool file_method(Value receiver, const char *name, Value *args, int32_t count, Value *result) {
    if (!is_obj(receiver, OBJ_FILE)) return false;

    ObjFile *file = (ObjFile *)receiver.obj;
    (void)count;

    if (alg_stricmp(name, "Assign") == 0) {
        file_closed(file, "Assign");
        file->name = file_name_argument(args[0]);
        *result = alg_nil();
        return true;
    }
    if (alg_stricmp(name, "Reset") == 0) {
        file_open(file, "Reset", "r", true);
        *result = alg_nil();
        return true;
    }
    if (alg_stricmp(name, "Rewrite") == 0) {
        file_open(file, "Rewrite", "w", false);
        *result = alg_nil();
        return true;
    }
    if (alg_stricmp(name, "Append") == 0) {
        file_open(file, "Append", "a", false);
        *result = alg_nil();
        return true;
    }
    if (alg_stricmp(name, "Close") == 0) {
        /* Closing a file that is not open is a no-op rather than an error, so a
         * handler can close on the way out without working out how far Reset
         * got. */
        if (file->handle != NULL && fclose(file->handle) != 0) {
            file->handle = NULL;
            file_error("Close", "", file->name);
        }
        file->handle    = NULL;
        file->lookahead = NULL;
        file->looked    = false;

        *result = alg_nil();
        return true;
    }
    if (alg_stricmp(name, "ReadLn") == 0) {
        file_reading(file, "ReadLn");

        char *line = file_peek(file);
        if (line == NULL) alg_error("ReadLn failed: at end of file.");

        file->lookahead = NULL;
        file->looked    = false;

        *result = alg_string(line);
        return true;
    }
    if (alg_stricmp(name, "Write") == 0) {
        file_writing(file, "Write");
        fputs(as_text(alg_str(args[0])), file->handle);

        *result = alg_nil();
        return true;
    }
    if (alg_stricmp(name, "WriteLn") == 0) {
        file_writing(file, "WriteLn");
        fputs(as_text(alg_str(args[0])), file->handle);
        fputc('\n', file->handle);

        *result = alg_nil();
        return true;
    }
    if (alg_stricmp(name, "Flush") == 0) {
        file_writing(file, "Flush");
        if (fflush(file->handle) != 0) file_error("Flush", "", file->name);

        *result = alg_nil();
        return true;
    }
    if (alg_stricmp(name, "Erase") == 0) {
        file_closed(file, "Erase");
        file_named(file, "Erase");

        if (remove(file->name) != 0) file_error("Erase", "cannot delete ", file->name);

        *result = alg_nil();
        return true;
    }
    if (alg_stricmp(name, "Rename") == 0) {
        file_closed(file, "Rename");
        file_named(file, "Rename");

        const char *to = file_name_argument(args[0]);
        if (rename(file->name, to) != 0) {
            char message[512];
            snprintf(message, sizeof message,
                     "Rename failed: cannot rename '%s' to '%s'.", file->name, to);
            alg_error(message);
        }

        /* Turbo Pascal leaves the handle assigned to the new name. */
        file->name = to;

        *result = alg_nil();
        return true;
    }

    undefined("property", name);
    return false;
}

/* X is T.
 *
 * True when the value's runtime type is T, or inherits from it.  nil is never
 * anything, matching the interpreter: a value that is not there has no type to
 * test.
 *
 * is_a already walks the class chain -- it was written for overload selection,
 * and this is the same question asked in the language rather than by the
 * dispatcher. */
Value alg_is(Value v, const char *name) {
    /* ⚠️ A subrange is a RANGE TEST, and that is not the value-dependence the
     * language otherwise refuses: 'is' is the program asking, explicitly, where
     * it wrote the question.  What must never depend on a value is SELECTION,
     * which happens behind the programmer's back. */
    const Subrange *range = subrange_of(name);
    if (range != NULL) return alg_bool(in_subrange(v, range));

    if (v.type == VAL_NIL) return alg_bool(false);

    if (alg_stricmp(type_name(v), name) == 0) return alg_bool(true);

    return alg_bool(is_a(v, name));
}

/* 'X as T' -- a CHECKED conversion [VAL-007], and the same question 'is' asks.
 *
 * ⚠️ It is the only way a value crosses from untyped into typed [VAR-006], so
 * the strictness there is reasonable only if the crossing is verified.  This
 * was not checked at all: the emitter recorded the cast and nothing tested it,
 * which left a compiled program with no verified boundary anywhere -- a value
 * of the wrong type passed into a declared type and nothing said so.
 *
 * ⚠️ nil satisfies every type [VAR-005] and therefore passes every cast, which
 * is where this parts company with alg_is: nil 'is' nothing and casts to
 * anything. */
Value alg_cast(Value v, const char *name) {
    if (v.type == VAL_NIL) return v;

    /* 'as' asks the same question 'is' does, made a requirement. */
    const Subrange *range = subrange_of(name);
    if (range != NULL) {
        if (in_subrange(v, range)) return v;

        char message[128];
        snprintf(message, sizeof message, "Cannot cast %s to %s.", type_name(v), name);

        alg_error(message);
    }


    if (alg_stricmp(type_name(v), name) == 0) return v;
    if (is_a(v, name)) return v;

    char message[256];
    snprintf(message, sizeof message, "Cannot cast %s to %s.", type_name(v), name);

    alg_error(message);
    return alg_nil();
}

Value alg_file_exists(Value name) {
    const char *path = file_name_argument(name);

    FILE *probe = fopen(path, "r");
    if (probe == NULL) return alg_bool(false);

    fclose(probe);
    return alg_bool(true);
}

/* ----------------------------------------------------------- arguments -- */

static int    argument_count  = 0;
static char **argument_values = NULL;

void alg_set_arguments(int argc, char **argv) {
    argument_count  = argc;
    argument_values = argv;

    /* Emitted main calls this first and always, which makes it the one place
     * guaranteed to run before anything allocates.  atexit rather than a call
     * at the end of main, so a program that stops early -- alg_error exits 70
     * -- still gives its memory back. */
    atexit(alg_shutdown);
}

Value alg_param_count(void) {
    /* The program itself is index 0 and is not counted, as in Turbo Pascal. */
    return alg_int(argument_count > 0 ? argument_count - 1 : 0);
}

Value alg_param_str(Value index) {
    int32_t at = as_integer(index, "ParamStr expects an Integer.");

    /* Past the end is empty rather than an error, so walking 1..ParamCount is
     * always safe -- Turbo Pascal does the same. */
    if (at < 0 || at >= argument_count) return alg_string("");

    return alg_string(argument_values[at]);
}

/* --------------------------------------------------- property and method -- */

/* "Undefined property 'X'." -- named, because the interpreter names it and a
 * runtime error inside a 'try' is catchable as a String.  An unnamed message
 * is also nearly useless in a program the size of a compiler. */
_Noreturn static void undefined(const char *what, const char *name) {
    char message[256];
    snprintf(message, sizeof message, "Undefined %s '%s'.", what, name);
    alg_error(message);
}

/* A member read without being called, for a receiver whose members are the
 * runtime's rather than a class's.
 *
 * ⚠️ Every member a kind has is a VALUE before it is a call [COL-005], exactly
 * as a method of an instance is -- the branch below this one binds one of
 * those, and these three receivers were left out.  Only Length and IsEmpty
 * answered here, so of the 41 kind/member pairs [COL-003] records a compiled
 * program could read 10, and 'var Sort := L.Sort;' was 'Undefined property'.
 *
 * ⚠️ Nothing in the compiler's own sources reads a built-in member without
 * calling it, which is why this went unnoticed: the only program exercising it
 * was spec/members.a24, a source for spec/spec.sh rather than a conformance
 * case, so nothing ever compiled it. */
static Value builtin_member(Value receiver, const char *name) {
    const Member *found = member_of(receiver, name);
    if (found == NULL) undefined("property", name);

    return builtin_bound(receiver, name, found->arity);
}

Value alg_property(Value receiver, const char *name) {
    if (is_obj(receiver, OBJ_FILE)) {
        if (alg_stricmp(name, "Eof") == 0) return file_eof((ObjFile *)receiver.obj);

        return builtin_member(receiver, name);
    }

    /* Text is a property, like Length and IsEmpty: a zero-argument query reads
     * better without parentheses, which is the rule for the whole language. */
    if (is_obj(receiver, OBJ_BUFFER)) {
        if (alg_stricmp(name, "Text") == 0) return buffer_text(as_buffer(receiver, "Text"));

        if (alg_stricmp(name, "Length") == 0)  return alg_length(receiver);
        if (alg_stricmp(name, "IsEmpty") == 0) return alg_is_empty(receiver);

        return builtin_member(receiver, name);
    }

    if (is_obj(receiver, OBJ_INSTANCE)) {
        ObjInstance *instance = (ObjInstance *)receiver.obj;

        /* Every instance answers to ClassName, as the interpreter does, and
         * ahead of the fields for the same reason: the name is
         * the language's, not the class's, so a field of that name cannot take
         * it.  Matched case-insensitively like the interpreter's, though the
         * fields below are case-sensitive -- which is also what it does.
         *
         * Not provided: GetClass, which would need a class-wrapper object, and
         * HasProperty.  Nothing reaches for either yet. */
        if (alg_stricmp(name, "ClassName") == 0) return alg_string(instance->klass->name);

        int32_t slot = field_slot(instance->klass, name);
        if (slot >= 0) return instance->slots[slot];

        /* ⚠️ A method reached without calling it binds to the receiver, as the
         * interpreter does.  Only fields were looked at here, so
         * 'var M := B.Hello;' raised 'Undefined property' compiled while
         * working interpreted -- and algc's own IsCallable asks every value
         * for its Arity, so a compiled algc could not call anything at all.
         *
         * The first method of that name, whatever its arity: the interpreter
         * does the same, and re-selects on the whole signature at the call. */
        MethodEntry *method = find_method(instance->klass, name, -1, NULL, false);
        if (method == NULL) undefined("property", name);

        return alg_bound(receiver, method);
    }

    /* ⚠️ A MEMBER answers exactly one property: its zero-based position
     * [ENU-010].  The ordinal was already carried here -- truthiness reads it,
     * so the first member of every enumeration is falsey [ENU-009] -- and a
     * compiled program had no way to read it, so it could discover whether a
     * member was falsey only by testing it for truth.  This fell through to
     * 'Only instances have properties.' (C-17). */
    if (is_obj(receiver, OBJ_ENUM)) {
        if (alg_stricmp(name, "Ordinal") == 0) return alg_int(((ObjEnum *)receiver.obj)->ordinal);

        undefined("property", name);
    }

    if (is_obj(receiver, OBJ_ENUM_TYPE)) {
        ObjEnumType *type = (ObjEnumType *)receiver.obj;

        for (int32_t i = 0; i < type->count; i++) {
            /* Folded [SRC-011], as every other member lookup here is. */
            if (alg_stricmp(((ObjEnum *)type->members[i].obj)->name, name) == 0)
                return type->members[i];
        }
        undefined("enum member", name);
    }

    /* Collections answer to Length and IsEmpty, case-insensitively. */
    if (alg_stricmp(name, "Length") == 0)  return alg_length(receiver);
    if (alg_stricmp(name, "IsEmpty") == 0) return alg_is_empty(receiver);

    /* A number's members bind like any other, so '5.ToString' reads as
     * something callable [COL-005]. */
    if (is_number(receiver)) return builtin_member(receiver, name);

    /* ⚠️ A COLLECTION names the property it does not have [TYP-009], as the
     * interpreter does -- 'List ().ClassName' is 'Undefined property
     * ''ClassName''.'  This said 'Only instances have properties.', which is
     * true of an instance and unhelpful about a List, and is the message a
     * non-object receiver still gets below. */
    if (is_sequence(receiver) || is_obj(receiver, OBJ_MAP))
        return builtin_member(receiver, name);

    alg_error("Only instances have properties.");
    return alg_nil();
}

Value alg_set_property(Value receiver, const char *name, Value value) {
    if (!is_obj(receiver, OBJ_INSTANCE)) alg_error("Only instances have fields.");

    ObjInstance *instance = (ObjInstance *)receiver.obj;

    int32_t slot = field_slot(instance->klass, name);

    /* Fields are a closed set, so assigning to one the class never declared is
     * an error rather than creating it. */
    if (slot < 0) undefined("property", name);

    instance->slots[slot] = value;
    return value;
}

/* Buffer methods.  Tried before the collections' table for the same reason the
 * files' is: 'Append' means one thing to a file and another to a Buffer, and
 * only the receiver says which. */
static bool buffer_method(Value receiver, const char *name, Value *args, int32_t count, Value *result) {
    if (!is_obj(receiver, OBJ_BUFFER)) return false;
    (void)count;

    /* Free is the one method that may be called on a freed Buffer, and is a
     * no-op the second time -- the same bargain Close makes for a file, so a
     * handler can free on the way out without knowing how far it got. */
    if (alg_stricmp(name, "Free") == 0) {
        ObjBuffer *buffer = (ObjBuffer *)receiver.obj;

        free(buffer->bytes);
        buffer->bytes    = NULL;
        buffer->length   = 0;
        buffer->capacity = 0;
        buffer->freed    = true;

        *result = alg_nil();
        return true;
    }

    if (alg_stricmp(name, "Append") == 0) {
        ObjBuffer  *buffer = as_buffer(receiver, "Append");
        const char *text   = as_text(args[0]);

        buffer_append(buffer, text, strlen(text));

        *result = alg_nil();
        return true;
    }
    if (alg_stricmp(name, "PutInt") == 0) {
        ObjBuffer *buffer = as_buffer(receiver, "PutInt");
        size_t     at     = buffer_offset(buffer, args[0], 4);

        buffer_put_int(buffer, at, as_integer(args[1], "PutInt takes an Integer."));

        *result = alg_nil();
        return true;
    }
    if (alg_stricmp(name, "GetInt") == 0) {
        ObjBuffer *buffer = as_buffer(receiver, "GetInt");

        *result = alg_int(buffer_get_int(buffer, buffer_offset(buffer, args[0], 4)));
        return true;
    }
    if (alg_stricmp(name, "Resize") == 0) {
        ObjBuffer *buffer = as_buffer(receiver, "Resize");

        buffer_resize(buffer, as_integer(args[0], "A Buffer's size must be an Integer."));

        *result = alg_nil();
        return true;
    }

    undefined("property", name);
    return false;
}

/* Collection methods, reached by name.  Kept here rather than in the emitter
 * because a class may declare a method called Add, and only the receiver says
 * which is meant. */
/* A member's row in a table, or NULL if the table does not have it.  Folded
 * [SRC-011].  The table ends with a NULL name. */
static const Member *row_in(const char *name, const Member *members) {
    for (int32_t i = 0; members[i].name != NULL; i++)
        if (alg_stricmp(name, members[i].name) == 0) return &members[i];

    return NULL;
}

/* This receiver's row for this member, or NULL if its kind has no such member.
 *
 * ⚠️ The member table is PER KIND, which is why this asks the receiver's type
 * before the name.  A flat table answers every name for every kind, so
 * 'Stack ().Get (0)' ran and handed back an element [COL-005], where the
 * interpreter refuses it -- the compiler accepting a program the language
 * refuses, which is the direction that matters.
 *
 * ⚠️ The ARITY is carried, not just the membership, because a member read
 * without being called binds to something callable that has to know its own
 * -- ObjCollection.Get, ObjBuffer.Get and ObjFile.Get all pass an arity into
 * the wrapper they hand back, and those three are the tables this mirrors.
 * All four have to be read together. */
static const Member *member_of(Value receiver, const char *name) {
    static const Member list[]  = { {"Get", 1}, {"Add", 1}, {"Insert", 2}, {"RemoveAt", 1},
                                    {"IndexOf", 1}, {"Sort", 0}, {"Clear", 0}, {NULL, 0} };
    static const Member array[] = { {"Get", 1}, {"Set", 2}, {"Fill", 1},
                                    {"IndexOf", 1}, {"Sort", 0}, {NULL, 0} };
    static const Member map[]   = { {"Get", 1}, {"Put", 2}, {"Remove", 1},
                                    {"Keys", 0}, {"Values", 0}, {"Clear", 0}, {NULL, 0} };
    static const Member set[]   = { {"Add", 1}, {"Remove", 1}, {"ToList", 0},
                                    {"Clear", 0}, {NULL, 0} };
    static const Member stack[] = { {"Push", 1}, {"Pop", 0}, {"Peek", 0},
                                    {"Clear", 0}, {NULL, 0} };

    static const Member buffer[] = { {"Append", 1}, {"PutInt", 2}, {"GetInt", 1},
                                     {"Resize", 1}, {"Free", 0}, {NULL, 0} };
    static const Member file[]   = { {"Assign", 1}, {"Reset", 0}, {"Rewrite", 0},
                                     {"Append", 0}, {"ReadLn", 0}, {"Write", 1},
                                     {"WriteLn", 1}, {"Flush", 0}, {"Close", 0},
                                     {"Erase", 0}, {"Rename", 1}, {NULL, 0} };

    /* Shared by every collection kind, and by no other receiver. */
    static const Member shared[] = { {"Contains", 1}, {NULL, 0} };

    /* ⚠️ A NUMBER answers members too, and it is the C# arrangement rather than
     * Java's: '5.ToString ()' works because an Integer is a type with members,
     * not because a box wraps a primitive.  There is no second kind of thing to
     * compare wrongly with '=', and no null to unbox. */
    static const Member number[] = { {"ToString", 0}, {NULL, 0} };

    if (is_number(receiver) && !is_bigint(receiver)) return row_in(name, number);

    if (receiver.type != VAL_OBJ) return NULL;

    if (is_bigint(receiver)) return row_in(name, number);

    if (is_sequence(receiver) || is_obj(receiver, OBJ_MAP)) {
        const Member *found = row_in(name, shared);
        if (found != NULL) return found;
    }

    switch (receiver.obj->type) {
        case OBJ_LIST:   return row_in(name, list);
        case OBJ_ARRAY:  return row_in(name, array);
        case OBJ_MAP:    return row_in(name, map);
        case OBJ_SET:    return row_in(name, set);
        case OBJ_STACK:  return row_in(name, stack);
        case OBJ_BUFFER: return row_in(name, buffer);
        case OBJ_FILE:   return row_in(name, file);

        default: return NULL;
    }
}

/* A number's members.  ToString is the only one, and it is Str by another
 * spelling -- one rendering, so the two cannot disagree. */
static bool number_method(Value receiver, const char *name, Value *args, int32_t count, Value *result) {
    (void)args;
    (void)count;

    if (!is_number(receiver)) return false;

    if (member_of(receiver, name) == NULL) undefined("property", name);

    *result = alg_string(as_text(receiver));
    return true;
}

static bool collection_method(Value receiver, const char *name, Value *args, int32_t count, Value *result) {
    (void)count;

    if (!is_sequence(receiver) && !is_obj(receiver, OBJ_MAP)) return false;

    /* Named by the receiver's kind, so what runs below is a member that kind
     * actually has.  'Undefined property' is the interpreter's wording, and a
     * collection names the member it does not have [TYP-009]. */
    if (member_of(receiver, name) == NULL) undefined("property", name);

    if (alg_stricmp(name, "Add") == 0)       { *result = alg_add_item(receiver, args[0]); return true; }
    if (alg_stricmp(name, "Put") == 0)       { *result = alg_put(receiver, args[0], args[1]); return true; }
    if (alg_stricmp(name, "Get") == 0)       { *result = alg_get(receiver, args[0]); return true; }
    if (alg_stricmp(name, "Set") == 0)       { *result = alg_set_at(receiver, args[0], args[1]); return true; }
    if (alg_stricmp(name, "Remove") == 0)    { *result = alg_remove(receiver, args[0]); return true; }
    if (alg_stricmp(name, "RemoveAt") == 0)  { *result = alg_remove_at(receiver, args[0]); return true; }
    if (alg_stricmp(name, "Insert") == 0)    { *result = alg_insert(receiver, args[0], args[1]); return true; }
    if (alg_stricmp(name, "Contains") == 0)  { *result = alg_contains(receiver, args[0]); return true; }
    if (alg_stricmp(name, "IndexOf") == 0)   { *result = alg_index_of(receiver, args[0]); return true; }
    if (alg_stricmp(name, "Clear") == 0)     { *result = alg_clear(receiver); return true; }
    if (alg_stricmp(name, "Fill") == 0)      { *result = alg_fill(receiver, args[0]); return true; }
    if (alg_stricmp(name, "Push") == 0)      { *result = alg_push(receiver, args[0]); return true; }
    if (alg_stricmp(name, "Pop") == 0)       { *result = alg_pop(receiver); return true; }
    if (alg_stricmp(name, "Peek") == 0)      { *result = alg_peek(receiver); return true; }
    if (alg_stricmp(name, "Sort") == 0)      { *result = alg_sort(receiver); return true; }
    if (alg_stricmp(name, "Keys") == 0)      { *result = alg_keys(receiver); return true; }
    if (alg_stricmp(name, "Values") == 0)    { *result = alg_values(receiver); return true; }
    if (alg_stricmp(name, "ToList") == 0)    { *result = alg_to_list(receiver); return true; }

    return false;
}

static Value invoke_found(MethodEntry *method, Value receiver, Value *args, int32_t count) {
    /* ⚠️ Reached only with the 'named' fallback in hand -- find_method kept a
     * method of this name that no arity matched, so the call fits nothing.
     * That is what the interpreter calls 'No matching signature for function.',
     * and a method selects on the whole signature rather than on arity, so the
     * counts are not the story to tell.  This said 'Wrong number of
     * arguments.', which no interpreted run produces. */
    /* ⚠️ Absorption happens HERE, at the one gate every method call passes
     * through, which is where the interpreter does it too -- ObjFunction.Call.
     * Selection above only decided WHICH method; reshaping the arguments once,
     * here, spares find_method and every caller from knowing that absorption
     * exists [FUN-005]. */
    if (should_absorb(method->types, method->arity, args, count))
        return method->fn(receiver, absorb_args(method->arity, args, count), method->arity);

    if (method->arity != count) alg_error("No matching signature for function.");

    return method->fn(receiver, args, count);
}

Value alg_invoke(Value receiver, const char *name, Value *args, int32_t count) {
    if (is_obj(receiver, OBJ_INSTANCE)) {
        ObjInstance *instance = (ObjInstance *)receiver.obj;

        MethodEntry *method = find_method(instance->klass, name, count, args, true);
        if (method == NULL) undefined("property", name);

        return invoke_found(method, receiver, args, count);
    }

    Value result;
    if (number_method(receiver, name, args, count, &result)) return result;
    if (file_method(receiver, name, args, count, &result)) return result;
    if (buffer_method(receiver, name, args, count, &result)) return result;
    if (collection_method(receiver, name, args, count, &result)) return result;

    alg_error("Only instances have properties.");
    return alg_nil();
}

/* 'super.M' read without calling it.
 *
 * ⚠️ The same search alg_invoke_from makes -- above the class that DECLARED the
 * running method, not above the receiver's own -- so an override does not find
 * itself.  Binding it is the only way a program can hold the implementation an
 * override replaced, and the emitter refused the spelling outright until now.
 *
 * ⚠️ The FIRST method of that name, whatever its arity, exactly as alg_property
 * does for a receiver's own: the interpreter re-selects on the whole signature
 * when the value is finally called. */
Value alg_bound_from(Value value, Value receiver, const char *name) {
    ObjClass *klass = as_class(value, "Expected a class.");

    if (klass->super == NULL) alg_error("No superclass.");

    MethodEntry *method = find_method(klass->super, name, -1, NULL, false);
    if (method == NULL) alg_error("Undefined method on the superclass.");

    return alg_bound(receiver, method);
}

Value alg_invoke_from(Value value, Value receiver, const char *name, Value *args, int32_t count) {
    ObjClass *klass = as_class(value, "Expected a class.");

    if (klass->super == NULL) alg_error("No superclass.");

    MethodEntry *method = find_method(klass->super, name, count, args, true);
    if (method == NULL) alg_error("Undefined method on the superclass.");

    return invoke_found(method, receiver, args, count);
}

/* --------------------------------------------------------- bound methods -- */

typedef struct {
    Obj obj;

    Value        receiver;
    MethodEntry *method;
} ObjBound;

/* A built-in member with its receiver attached -- 'L.Sort' without the call.
 * There is no MethodEntry to point at, so the name and arity are carried and
 * the call goes back through alg_invoke. */
typedef struct {
    Obj obj;

    Value       receiver;
    const char *name;
    int32_t     arity;
} ObjBuiltinBound;

static Value alg_bound(Value receiver, MethodEntry *method) {
    ObjBound *bound = arena_alloc(sizeof(ObjBound));

    bound->obj.type = OBJ_BOUND;
    bound->receiver = receiver;
    bound->method   = method;

    return object((Obj *)bound);
}

/* The same, for a member the RUNTIME provides rather than a class.
 *
 * ⚠️ The name is the CALL SITE's spelling.  A built-in member has no
 * declaration in the language to take a canonical spelling from -- a bound
 * method prints the name its declaration used [TYP-012], and the table here is
 * not one -- so the only spelling both processors can agree on is the one the
 * program wrote.  Storing it is safe: it is a string literal in the emitted C,
 * with the lifetime of the program. */
static Value builtin_bound(Value receiver, const char *name, int32_t arity) {
    ObjBuiltinBound *bound = arena_alloc(sizeof(ObjBuiltinBound));

    bound->obj.type = OBJ_BUILTIN_BOUND;
    bound->receiver = receiver;
    bound->name     = name;
    bound->arity    = arity;

    return object((Obj *)bound);
}

/* -------------------------------------------------------------- closures -- */

typedef struct {
    Obj obj;

    const char *name;
    AlgFunction fn;
    Value     **cells;
    int32_t     cell_count;
    int32_t     arity;

    /* The parameter list as written -- "Level : String" -- or NULL.  A function
     * held in a variable is still called by the names of its parameters
     * [EXP-013], and without this a closure was the one callable in the runtime
     * that had forgotten them. */
    const char **types;
} ObjClosure;

/* A captured variable is one of these rather than a C local, so it survives the
 * call that declared it and stays shared with every closure that took it. */
Value *alg_cell(Value initial) {
    Value *cell = arena_alloc(sizeof(Value));
    *cell = initial;

    return cell;
}

Value alg_closure(const char *name, AlgFunction fn, Value **cells, int32_t cell_count, int32_t arity,
                  const char **types) {
    ObjClosure *closure = arena_alloc(sizeof(ObjClosure));

    closure->obj.type   = OBJ_CLOSURE;
    closure->name       = name;
    closure->fn         = fn;
    closure->arity      = arity;
    closure->cell_count = cell_count;
    closure->types      = types;

    /* Copied, because the array the caller built is a compound literal whose
     * lifetime ends with the enclosing block. */
    if (cell_count == 0) {
        closure->cells = NULL;
    }
    else {
        closure->cells = arena_alloc((size_t)cell_count * sizeof(Value *));
        memcpy(closure->cells, cells, (size_t)cell_count * sizeof(Value *));
    }
    return object((Obj *)closure);
}

/* ------------------------------------------------------------- overloads -- */

/* A top-level subprogram overloads [FUN-013], and selection is on the whole
 * signature from the values actually passed -- the same rule methods use, and
 * for the same reason: a declared type may be Any, so no static rule can always
 * reach the right candidate.
 *
 * ⚠️ ONE object per overloaded NAME, not one symbol per declaration reached by
 * a call site that guessed.  The call site cannot know which candidate it wants
 * until it has its arguments, exactly as a method call cannot, so it hands them
 * all to this and lets it choose. */
typedef struct {
    AlgFunction  fn;
    int32_t      arity;
    const char **types;
} OverloadEntry;

typedef struct {
    Obj obj;

    const char    *name;
    OverloadEntry *entries;
    int32_t        count;
    int32_t        capacity;
} ObjOverloads;

Value alg_overloads(const char *name) {
    ObjOverloads *set = arena_alloc(sizeof(ObjOverloads));

    set->obj.type = OBJ_OVERLOADS;
    set->name     = name;
    set->entries  = NULL;
    set->count    = 0;
    set->capacity = 0;

    return object((Obj *)set);
}

void alg_overload(Value value, AlgFunction fn, int32_t arity, const char **types) {
    if (!is_obj(value, OBJ_OVERLOADS)) alg_error("Expected an overload set.");

    ObjOverloads *set = (ObjOverloads *)value.obj;

    /* Fixed at startup and short, so this grows by one rather than doubling --
     * the same bargain alg_class_field makes. */
    OverloadEntry *entries = arena_alloc((size_t)(set->count + 1) * sizeof(OverloadEntry));
    if (set->count > 0) memcpy(entries, set->entries, (size_t)set->count * sizeof(OverloadEntry));

    entries[set->count].fn    = fn;
    entries[set->count].arity = arity;
    entries[set->count].types = types;

    set->entries = entries;
    set->count++;
    set->capacity = set->count;
}

/* ⚠️ THREE PASSES, exact then widening then absorbing [EXP-014], as find_method
 * does and for the same reason: one pass admitting widening lets declaration
 * order decide which candidate a Char reaches, which is a silent wrong answer,
 * and one admitting absorption lets a variadic candidate take a call a
 * fixed-arity one answers exactly.  Within a pass the scan runs forwards, so
 * when two both fit the first declared wins. */
static Value call_overload(ObjOverloads *set, Value *args, int32_t count) {
    for (int pass = 0; pass < 3; pass++)
        for (int32_t i = 0; i < set->count; i++) {
            OverloadEntry *entry = &set->entries[i];

            /* ⚠️ The absorbing pass does not test the arity -- an absorbing
             * call has a different one by design, and the element type is its
             * rule instead. */
            if (pass == 2) {
                if (types_absorb(entry->types, entry->arity, args, count))
                    return entry->fn(NULL, absorb_args(entry->arity, args, count), entry->arity);

                continue;
            }

            if (entry->arity == count && types_match(entry->types, args, count, pass == 1))
                return entry->fn(NULL, args, count);
        }

    /* ⚠️ ONE message for both failures, which is what the interpreter gives: a
     * wrong count and a wrong type are both "nothing fitted" here, and there is
     * no single expected arity to name when the candidates disagree about it. */
    alg_error("No matching signature for function.");
    return alg_nil();
}

Value alg_call(Value callee, Value *args, int32_t count) {
    /* A class is callable: naming one constructs an instance. */
    if (is_obj(callee, OBJ_CLASS)) return alg_new(callee, args, count);

    /* A method held as a value carries its receiver with it. */
    if (is_obj(callee, OBJ_BOUND)) {
        ObjBound *bound = (ObjBound *)callee.obj;

        return invoke_found(bound->method, bound->receiver, args, count);
    }

    /* A name with more than one subprogram behind it picks one from the
     * arguments -- see call_overload. */
    if (is_obj(callee, OBJ_OVERLOADS))
        return call_overload((ObjOverloads *)callee.obj, args, count);

    /* And so does a built-in member.  One signature, so the counts are the
     * whole story -- CollectionMethod, BufferMethod and FileMethod each carry
     * an arity for exactly this check. */
    if (is_obj(callee, OBJ_BUILTIN_BOUND)) {
        ObjBuiltinBound *bound = (ObjBuiltinBound *)callee.obj;

        alg_arity(count, bound->arity);
        return alg_invoke(bound->receiver, bound->name, args, count);
    }

    if (!is_obj(callee, OBJ_CLOSURE)) alg_error("Can only call functions and classes.");

    ObjClosure *closure = (ObjClosure *)callee.obj;

    /* ⚠️ Absorption before the count is judged, for the reason invoke_found
     * gives: an absorbing call has a different count by design [FUN-005]. */
    if (should_absorb(closure->types, closure->arity, args, count))
        return closure->fn(closure->cells, absorb_args(closure->arity, args, count), closure->arity);

    /* One signature, so the counts are the whole story -- see arity_error. */
    alg_arity(count, closure->arity);

    return closure->fn(closure->cells, args, count);
}

/* ------------------------------------------------------- named arguments -- */

/* An argument may name the parameter it fills [EXP-013].  These three mirror
 * the interpreter's Arranged: the arguments are put in DECLARATION ORDER once,
 * before anything else sees them, so selection, absorption and binding all go
 * on working positionally and none of them learns that a name can appear.
 *
 * ⚠️ THE NAMES SELECT THE SIGNATURE, which is the point of the feature.
 * Selection is otherwise from the values actually passed [FUN-013] -- right for
 * a gradually typed language, and unchanged -- but a programmer who knows which
 * overload they mean had no way to say so.  A name identifies one signature
 * where values only describe something several might accept.
 *
 * ⚠️ Emitted only where a name was actually written, so a call without one
 * still emits alg_call, alg_invoke or alg_new and costs nothing. */
Value alg_call_named(Value callee, Value *args, int32_t count, const char **names) {
    if (!any_named(names, count)) return alg_call(callee, args, count);

    if (is_obj(callee, OBJ_CLASS)) return alg_new_named(callee, args, count, names);

    if (is_obj(callee, OBJ_OVERLOADS)) {
        ObjOverloads *set = (ObjOverloads *)callee.obj;

        for (int32_t i = 0; i < set->count; i++) {
            OverloadEntry *entry = &set->entries[i];
            Value *arranged = arrange_args(entry->types, entry->arity, args, count, names);

            if (arranged != NULL) return alg_call(callee, arranged, entry->arity);
        }

        alg_error("No matching signature for function.");
    }

    if (is_obj(callee, OBJ_CLOSURE)) {
        ObjClosure *closure = (ObjClosure *)callee.obj;
        Value *arranged = arrange_args(closure->types, closure->arity, args, count, names);

        if (arranged == NULL) alg_error("No matching signature for function.");

        return alg_call(callee, arranged, closure->arity);
    }

    /* ⚠️ A BUILT-IN has no named parameters, and this is where that is said.
     * Its parameters are not declared in this language at all -- they exist
     * only as a count -- so there is no name to write. */
    alg_error("A built-in has no named parameters.");
    return alg_nil();
}

Value alg_invoke_named(Value receiver, const char *name, Value *args, int32_t count,
                       const char **names) {
    if (!any_named(names, count)) return alg_invoke(receiver, name, args, count);

    if (is_obj(receiver, OBJ_INSTANCE)) {
        ObjInstance *instance = (ObjInstance *)receiver.obj;

        /* ⚠️ The whole chain, outermost first, exactly as find_method walks it
         * -- an override is reached before the method it replaced. */
        for (ObjClass *at = instance->klass; at != NULL; at = at->super) {
            for (int32_t i = 0; i < at->method_count; i++) {
                if (alg_stricmp(at->methods[i].name, name) != 0) continue;

                Value *arranged = arrange_args(at->methods[i].types, at->methods[i].arity,
                                               args, count, names);

                if (arranged != NULL)
                    return alg_invoke(receiver, name, arranged, at->methods[i].arity);
            }
        }

        alg_error("No matching signature for function.");
    }

    alg_error("A built-in has no named parameters.");
    return alg_nil();
}

Value alg_new_named(Value klass, Value *args, int32_t count, const char **names) {
    if (!any_named(names, count)) return alg_new(klass, args, count);

    if (!is_obj(klass, OBJ_CLASS)) alg_error("Can only call functions and classes.");

    /* Constructing an instance is a call to the constructor, so its parameters
     * are named the same way [CLS-002].
     *
     * ⚠️ The chain is walked HERE rather than through find_method, which
     * selects on a count -- and a named call has no meaningful count until the
     * arguments have been arranged, which is what this is doing. */
    for (ObjClass *at = (ObjClass *)klass.obj; at != NULL; at = at->super) {
        for (int32_t i = 0; i < at->method_count; i++) {
            if (alg_stricmp(at->methods[i].name, "init") != 0) continue;

            Value *arranged = arrange_args(at->methods[i].types, at->methods[i].arity,
                                           args, count, names);

            if (arranged != NULL) return alg_new(klass, arranged, at->methods[i].arity);
        }
    }

    alg_error("No matching signature for function.");
    return alg_nil();
}

/* ----------------------------------------------------------------- errors -- */

static AlgFrame *frames = NULL;

void alg_push_frame(AlgFrame *frame) {
    frame->previous = frames;
    frame->raised   = alg_nil();
    frames          = frame;
}

void alg_pop_frame(void) {
    if (frames != NULL) frames = frames->previous;
}

_Noreturn void alg_raise(Value value) {
    if (frames == NULL) {
        fprintf(stderr, "Uncaught: %s\n", as_text(value));
        exit(70);
    }

    /* Popped before the jump, so a handler that raises again reaches the frame
     * outside this one rather than itself. */
    AlgFrame *frame = frames;
    frames = frame->previous;

    frame->raised = value;
    ALG_LONGJMP(frame->jump, 1);
}

_Noreturn void alg_error(const char *message) {
    /* A runtime error inside a 'try' is catchable, and arrives as a String --
     * which is what the interpreter does with its own errors. */
    if (frames != NULL) {
        /* Copied, because the message is usually a stack buffer in the caller
         * -- alg_copy formats one with snprintf -- and alg_string only keeps
         * the pointer.  The longjmp below unwinds that frame, so the handler
         * would otherwise read whatever came to occupy it: the caught text
         * printed as garbage compiled and correctly interpreted, which is
         * exactly the kind of divergence the two implementations exist to
         * catch in each other. */
        size_t size = strlen(message) + 1;
        char  *kept = arena_alloc(size);
        memcpy(kept, message, size);

        alg_raise(alg_string(kept));
    }

    /* ⚠️ 'Uncaught: ', as alg_raise prints and as the interpreter's driver does
     * for a runtime error [ERR-008].  This printed the bare message, so every
     * uncaught runtime error read differently compiled -- twelve conformance
     * cases differed on this line alone, which is what C-8 recorded. */
    fprintf(stderr, "Uncaught: %s\n", message);
    exit(70);
}

/* The name a handler matches on. */
static const char *type_name(Value v) {
    switch (v.type) {
        case VAL_NIL:    return "nil";
        case VAL_BOOL:   return "Boolean";
        case VAL_INT:    return "Integer";
        case VAL_DOUBLE: return "Double";
        case VAL_STRING: return "String";
        case VAL_CHAR:   return "Char";
        case VAL_OBJ:    break;
    }
    switch (v.obj->type) {
        case OBJ_INSTANCE: return ((ObjInstance *)v.obj)->klass->name;

        /* An enum member answers with its type, so 'Red is Colour' is true --
         * the interpreter's type() returns enumName for the same reason. */
        case OBJ_ENUM:     return ((ObjEnum *)v.obj)->type;

        /* The collections named none of themselves here and only two of
         * themselves in the interpreter, so 'X is List' and 'X is Map'
         * disagreed both between the back ends and with each other. */
        /* A big Integer is an Integer.  The representation is the runtime's
         * business and the language has one name for the type. */
        case OBJ_BIGINT:   return "Integer";

        case OBJ_LIST:     return "List";
        case OBJ_SET:      return "Set";
        case OBJ_STACK:    return "Stack";
        case OBJ_ARRAY:    return "Array";
        case OBJ_MAP:      return "Map";
        case OBJ_FILE:     return "TextFile";
        case OBJ_BUFFER:   return "Buffer";

        default: break;
    }
    return "Any";
}

int32_t alg_handler(Value raised, const char **names, int32_t count) {
    /* Walks the value's own class chain and asks which handler matches at each
     * level, so the most derived wins however the handlers were written.  A
     * non-class value has no hierarchy and matches its name exactly. */
    if (raised.type == VAL_OBJ && raised.obj->type == OBJ_INSTANCE) {
        for (ObjClass *at = ((ObjInstance *)raised.obj)->klass; at != NULL; at = at->super) {
            for (int32_t i = 0; i < count; i++) {
                if (strcmp(names[i], at->name) == 0) return i;
            }
        }
        return -1;
    }

    const char *name = type_name(raised);
    for (int32_t i = 0; i < count; i++) {
        if (strcmp(names[i], name) == 0) return i;
    }
    return -1;
}

/* ----------------------------------------------------------- constructors -- */

Value alg_nil(void)              { Value v; v.type = VAL_NIL;    v.length = 0; v.integer = 0; return v; }
Value alg_bool(bool b)           { Value v; v.type = VAL_BOOL;   v.length = 0; v.boolean = b; return v; }
Value alg_int(int64_t i)         { Value v; v.type = VAL_INT;    v.length = 0; v.integer = i; return v; }

/* An Integer from its decimal text, for a literal too wide for C to spell.
 *
 * ⚠️ Built by the same arithmetic a program would use -- multiply by ten and
 * add -- so the promotion path is the one already there rather than a second
 * way of making a big integer.  The scanner accumulates a literal exactly this
 * way, which is why the two cannot disagree about what the digits mean. */
Value alg_integer(const char *digits) {
    Value       value = alg_int(0);
    const char *at    = digits;
    bool        negative = false;

    if (*at == '-') {
        negative = true;
        at++;
    }

    for (; *at != '\0'; at++)
        value = alg_add(alg_multiply(value, alg_int(10)), alg_int(*at - '0'));

    return negative ? alg_negate(value) : value;
}
Value alg_double(double d)       { Value v; v.type = VAL_DOUBLE; v.length = 0; v.number  = d; return v; }

Value alg_string_n(const char *s, int32_t n) {
    Value v;
    v.type   = VAL_STRING;
    v.length = n;
    v.string = s;
    return v;
}

/* What a C literal wants.  A String built from bytes that may hold a zero
 * character goes through alg_string_n instead. */
Value alg_string(const char *s)  { return alg_string_n(s, (int32_t)strlen(s)); }

Value alg_char_value(int32_t code) {
    /* ⚠️ Four bytes and a terminator: a Char is a Unicode code point [LEX-025]
     * and is held as its UTF-8 encoding, so it is a String of one CHARACTER and
     * possibly several bytes.  The range is checked where the literal is read,
     * which is where the line number is. */
    /* ⚠️ The ASCII case keeps its two bytes.  This is the hottest allocation in
     * the runtime -- the scanner's Peek builds a Char for every character of
     * every source file -- and taking five bytes for all of them put 2.5x the
     * traffic through the arena for no gain. */
    char *one;
    int   span;

    if (code < 0x80) { one = arena_alloc(2); one[0] = (char)code; span = 1; }
    else             { one = arena_alloc(5); span = utf8_encode(code, one); }

    one[span] = '\0';

    Value v;
    v.type   = VAL_CHAR;
    v.length = span;
    v.string = one;
    return v;
}

/* ------------------------------------------------------------- arithmetic -- */

static bool is_number(Value v) {
    return v.type == VAL_INT || v.type == VAL_DOUBLE || is_obj(v, OBJ_BIGINT);
}

/* A Char is text for concatenation, substring search and sorting -- it is only
 * equality that keeps it apart from a String. */
static bool is_text(Value v) {
    return v.type == VAL_STRING || v.type == VAL_CHAR;
}

/* ------------------------------------------------------------------ utf8 --
 *
 * Text is CHARACTERS, not bytes [SRC-004].  Length('café') is 4, 'café'[3] is
 * 'é', and Copy, Pos and Ord count and index the same way.  Source is UTF-8
 * [SRC-001] and a String holds it unchanged; only the counting changed.
 *
 * ⚠️ Strings stay NUL-terminated, and may, because #0 is REFUSED where it is
 * read [LEX-032] -- so no String can contain a zero byte.  Giving a String an
 * explicit length is a separate change, wanted for a different reason: it is
 * what would make an in-place append safe and '+' affordable (Annex G.2).
 */

/* Bytes in the sequence this lead byte opens.  A continuation byte or a
 * malformed lead answers 1, so a bad string still advances and cannot loop. */
static int utf8_span(unsigned char lead) {
    if (lead < 0x80)           return 1;
    if ((lead & 0xE0) == 0xC0) return 2;
    if ((lead & 0xF0) == 0xE0) return 3;
    if ((lead & 0xF8) == 0xF0) return 4;
    return 1;
}

static int32_t utf8_decode(const char *at) {
    const unsigned char *p = (const unsigned char *)at;
    int span = utf8_span(*p);

    if (span == 1) return *p;
    if (span == 2) return ((p[0] & 0x1F) << 6)  |  (p[1] & 0x3F);
    if (span == 3) return ((p[0] & 0x0F) << 12) | ((p[1] & 0x3F) << 6)  |  (p[2] & 0x3F);

    return ((p[0] & 0x07) << 18) | ((p[1] & 0x3F) << 12) | ((p[2] & 0x3F) << 6) | (p[3] & 0x3F);
}

/* Writes the code point and answers how many bytes it took.  The caller
 * supplies at least 4 bytes; the range is checked where the literal is READ. */
static int utf8_encode(int32_t code, char *out) {
    if (code < 0x80)    { out[0] = (char)code; return 1; }

    if (code < 0x800)   { out[0] = (char)(0xC0 | (code >> 6));
                          out[1] = (char)(0x80 | (code & 0x3F)); return 2; }

    if (code < 0x10000) { out[0] = (char)(0xE0 | (code >> 12));
                          out[1] = (char)(0x80 | ((code >> 6) & 0x3F));
                          out[2] = (char)(0x80 | (code & 0x3F)); return 3; }

    out[0] = (char)(0xF0 | (code >> 18));
    out[1] = (char)(0x80 | ((code >> 12) & 0x3F));
    out[2] = (char)(0x80 | ((code >> 6) & 0x3F));
    out[3] = (char)(0x80 | (code & 0x3F));
    return 4;
}

/* ⚠️ WITHOUT A CACHE THIS IS QUADRATIC, and that is the whole reason it exists.
 * Indexing by character means finding the Nth character's byte, which is a walk
 * from the start -- and the scanner reads its source one character at a time,
 * so 'Source[I]' in a loop over a 100 KB file would walk 100 KB every step.
 *
 * Two things make it cheap.  An all-ASCII string needs no walk at all, because
 * the character index IS the byte index, and every source file this compiler
 * has ever read is one.  A string that does need walking keeps a cursor, so
 * reading it in order costs one step per character rather than one walk.
 *
 * ⚠️ Keyed by POINTER, which is sound only because a String is immutable and
 * the arena never frees -- so a pointer identifies its contents for the life of
 * the process.  Direct-mapped rather than one entry, because two strings are
 * routinely measured in alternation and a single entry would thrash. */
typedef struct {
    const char *text;

    /* ⚠️ Part of the KEY, not just payload.  Two Strings may share a pointer and
     * differ in length -- a prefix of another -- so a cache keyed on the pointer
     * alone would answer with the longer one's count. */
    int32_t     bytes;

    int32_t     chars;
    int         ascii;

    /* Where the last walk stopped, so reading in order does not restart. */
    int32_t     at_char;
    int32_t     at_byte;
} TextInfo;

#define TEXT_CACHE_SLOTS 64
static TextInfo text_cache[TEXT_CACHE_SLOTS];

static TextInfo *text_info(const char *text, int32_t bytes) {
    size_t    slot  = ((uintptr_t)text >> 4) & (TEXT_CACHE_SLOTS - 1);
    TextInfo *entry = &text_cache[slot];

    if (entry->text == text && entry->bytes == bytes) return entry;

    /* strlen first, then a WORD-AT-A-TIME test for a high bit, because the ASCII
     * answer is the one that has to be cheap: strlen is vectorised and a byte
     * loop counting code points is not.
     *
     * ⚠️ Measured, three runs each of './test.sh': 20.1 s with this section
     * against 21.2 s without it.  Counting characters came out FASTER than
     * counting bytes did, which is not the direction it looks.  The reason is
     * the cache above rather than anything here -- subscripting text used to
     * call strlen on the whole string for every character, so the scanner's
     * Peek walked its entire source once per character read.  That was
     * quadratic and nothing had noticed. */
    int ascii = 1;

    const unsigned char *p = (const unsigned char *)text;
    size_t at = 0;

    for (; at + 8 <= (size_t)bytes; at += 8) {
        uint64_t chunk;
        memcpy(&chunk, p + at, 8);

        if (chunk & 0x8080808080808080ULL) { ascii = 0; break; }
    }
    if (ascii) {
        for (; at < (size_t)bytes; at++) if (p[at] >= 0x80) { ascii = 0; break; }
    }

    int32_t chars;

    if (ascii) chars = bytes;
    else {
        chars = 0;
        for (size_t i = 0; i < (size_t)bytes; chars++) i += (size_t)utf8_span(p[i]);
    }

    entry->text    = text;
    entry->bytes   = bytes;
    entry->chars   = chars;
    entry->ascii   = ascii;
    entry->at_char = 0;
    entry->at_byte = 0;
    return entry;
}

static int32_t utf8_count(const char *text, int32_t bytes) {
    return text_info(text, bytes)->chars;
}

/* The byte offset of character 'index', which must be in range. */
static int32_t utf8_offset(const char *text, int32_t bytes, int32_t index) {
    TextInfo *entry = text_info(text, bytes);

    if (entry->ascii) return index;

    if (index < entry->at_char) { entry->at_char = 0; entry->at_byte = 0; }

    while (entry->at_char < index) {
        entry->at_byte += utf8_span((unsigned char)text[entry->at_byte]);
        entry->at_char++;
    }
    return entry->at_byte;
}

/* Characters in the first 'bytes' bytes -- what turns a byte offset that
 * strstr found back into the character index a program asked for. */
static int32_t utf8_chars_in(const char *text, int32_t bytes) {
    if (text_info(text, bytes)->ascii) return bytes;

    int32_t chars = 0;
    for (int32_t at = 0; at < bytes; chars++) at += utf8_span((unsigned char)text[at]);

    return chars;
}

static bool is_double_arithmetic(Value a, Value b) {
    return a.type == VAL_DOUBLE || b.type == VAL_DOUBLE;
}

static double as_double(Value v) {
    if (is_obj(v, OBJ_BIGINT)) return big_to_double((ObjBigInt *)v.obj);

    return v.type == VAL_DOUBLE ? v.number : (double)v.integer;
}

static const char *as_text(Value v);

/* as_text with the length as well.  A String and a Char answer their own, which
 * is the whole point -- either may hold a zero character.  Everything else
 * answers strlen of the text as_text built, which cannot. */
static const char *as_text_len(Value v, int32_t *length) {
    if (is_text(v)) { *length = v.length; return v.string; }

    const char *text = as_text(v);
    *length = (int32_t)strlen(text);
    return text;
}

static Value concat(Value a, Value b) {
    int32_t left_len, right_len;

    const char *left  = as_text_len(a, &left_len);
    const char *right = as_text_len(b, &right_len);

    int32_t need = left_len + right_len;

    /* ⚠️ APPENDED IN PLACE into room RESERVED IN ADVANCE, which is what makes
     * 'S := S + ''x''' in a loop linear instead of quadratic.  Copying both
     * operands every time retains every intermediate and nothing here is ever
     * freed: 807 MB for 40,000 appends compiled, against 17 MB through a
     * Buffer.  It is an allocation-VOLUME problem, so a collector would not
     * have helped.
     *
     * ⚠️ The reservation is the point, and the first version went without it.
     * Asking only whether the left operand was the arena's most recent
     * allocation never fired: 'S + ''x''' allocates the Char first, so
     * something always sat between the string and the free space.  Doubling
     * the allocation puts the slack INSIDE this string's own block, where no
     * later allocation can take it.
     *
     * ⚠️ Safe only because a String carries its own length.  The append
     * overwrites the terminator an alias of the shorter view was relying on,
     * and that alias reads its own length everywhere that measures, compares or
     * prints -- as_text hands the rest a terminated copy.  That is why these
     * two changes had to land in this order.
     *
     * ⚠️ IDENTITY, not merely a fitting capacity.  The left operand must BE the
     * string this tail describes, pointer and length together.  Without the
     * length, two appends from one base both fit and the second overwrote the
     * first:
     *
     *     var A := 'x';   var B := A + 'y';   var C := A + 'z';
     *
     * left B reading 'xz'.  It was the test suite's own coloured output that
     * showed it, as corrupted ANSI escapes -- Console builds its tags by
     * concatenating shared constants, so a shared operand was appended twice. */
    if (is_text(a) && left_len > 0
        && a.string == arena_tail_text
        && a.length == arena_tail_len
        && need + 1 <= arena_tail_cap) {

        char *end = (char *)a.string + left_len;

        memcpy(end, right, (size_t)right_len);
        end[right_len] = '\0';

        arena_tail_len = need;
        return alg_string_n(a.string, need);
    }

    /* Doubling, with a floor, so a string built a piece at a time reaches its
     * size in a logarithmic number of copies rather than one per piece. */
    int32_t capacity = need + 1 < 64 ? 64 : (need + 1) * 2;

    char *result = arena_alloc((size_t)capacity);
    memcpy(result, left, (size_t)left_len);
    memcpy(result + left_len, right, (size_t)right_len);
    result[need] = '\0';

    arena_tail_text = result;
    arena_tail_len  = need;
    arena_tail_cap  = capacity;

    return alg_string_n(result, need);
}

/* -------------------------------------------------------------- integer -- 
 *
 * An Integer is UNBOUNDED [LEX-018].  Arithmetic that leaves the machine width
 * promotes into a big integer rather than raising, and demotes again the moment
 * a result fits -- see the big-integer section above.
 *
 * ⚠️ Signed overflow in C is UNDEFINED BEHAVIOUR, not a wrap, and at this
 * project's own -O2 the optimiser exploits it: 'x + 1 > x' folds to true.  The
 * arithmetic here goes through the builtins for that reason, and always did;
 * what changed is only what happens on the overflow they report.
 *
 * ⚠️ There is no switch to turn this off, and the one that existed is gone.
 * '-DALG_NO_OVERFLOW_CHECK' skipped a RANGE CHECK, leaving the two's-complement
 * wrap that had been there before -- a build that did not conform but did still
 * compute something.  The same branch now decides whether to promote, so
 * skipping it would not be a faster conforming build, it would be wrong
 * answers.  A check that can be turned off and a promotion that cannot are the
 * same line of C and a different bargain.
 */

Value alg_add(Value a, Value b) {
    if (is_text(a) || is_text(b)) return concat(a, b);

    if (is_number(a) && is_number(b)) {
        if (is_double_arithmetic(a, b)) return alg_double(as_double(a) + as_double(b));

        if (is_bigint(a) || is_bigint(b))
            return big_value(big_add_signed(as_big(a), as_big(b)));

        /* ⚠️ The builtin is the PROMOTION trigger now, not a range check.  It
         * was one until [LEX-018] made an Integer unbounded; the branch is the
         * same and what follows it is not. */
        int64_t result;
        if (__builtin_add_overflow(a.integer, b.integer, &result))
            return big_value(big_add_signed(as_big(a), as_big(b)));

        return alg_int(result);
    }
    alg_error("Operands must be two numbers, or two strings.");
    return alg_nil();
}

Value alg_subtract(Value a, Value b) {
    if (!is_number(a) || !is_number(b)) alg_error("Operands must be numbers.");
    if (is_double_arithmetic(a, b)) return alg_double(as_double(a) - as_double(b));

    if (is_bigint(a) || is_bigint(b))
        return big_value(big_sub_signed(as_big(a), as_big(b)));

    int64_t result;
    if (__builtin_sub_overflow(a.integer, b.integer, &result))
        return big_value(big_sub_signed(as_big(a), as_big(b)));

    return alg_int(result);
}

Value alg_multiply(Value a, Value b) {
    if (!is_number(a) || !is_number(b)) alg_error("Operands must be numbers.");
    if (is_double_arithmetic(a, b)) return alg_double(as_double(a) * as_double(b));

    if (is_bigint(a) || is_bigint(b))
        return big_value(big_mul(as_big(a), as_big(b)));

    int64_t result;
    if (__builtin_mul_overflow(a.integer, b.integer, &result))
        return big_value(big_mul(as_big(a), as_big(b)));

    return alg_int(result);
}

Value alg_divide(Value a, Value b) {
    if (!is_number(a) || !is_number(b)) alg_error("Operands must be numbers.");
    if (is_double_arithmetic(a, b)) return alg_double(as_double(a) / as_double(b));

    if (is_bigint(a) || is_bigint(b)) {
        ObjBigInt *x = as_big(a);
        ObjBigInt *y = as_big(b);

        if (y->count == 0) alg_error("Division by zero.");

        ObjBigInt *quotient;
        ObjBigInt *remainder;
        mag_divmod(x, y, &quotient, &remainder);

        /* Truncated toward zero [EXP-004]: magnitude division does that by
         * construction, so only the sign has to be put back. */
        quotient->negative = x->negative != y->negative;
        return big_value(quotient);
    }

    if (b.integer == 0) alg_error("Division by zero.");

    /* ⚠️ INT_MIN / -1 is the one division whose quotient does not fit, and it
     * must be caught EXPLICITLY: dividing would TRAP on some targets rather
     * than yielding a value to test afterwards. */
    if (a.integer == INT64_MIN && b.integer == -1)
        return big_value(big_negate_of(as_big(a)));

    return alg_int(a.integer / b.integer);
}

/* 'A div B' -- integer division, said deliberately [EXP-008].
 *
 * ⚠️ Refuses a Double rather than truncating it.  '/' is integer division on
 * two Integers and real division as soon as a Double reaches it, so 'X / Y'
 * cannot be read where X is 'Any'; 'div' always truncates, and a programmer
 * who writes it has said the operands are Integers.  The same bargain alg_mod
 * already makes. */
Value alg_div_int(Value a, Value b) {
    if (!is_integer(a) || !is_integer(b)) alg_error("div expects Integers.");

    return alg_divide(a, b);
}

Value alg_negate(Value a) {
    if (is_bigint(a)) return big_value(big_negate_of(as_big(a)));

    if (a.type == VAL_INT) {
        /* -INT_MIN is one past the largest Integer, so it promotes. */
        int64_t result;
        if (__builtin_sub_overflow(0, a.integer, &result))
            return big_value(big_negate_of(as_big(a)));

        return alg_int(result);
    }
    if (a.type == VAL_DOUBLE) return alg_double(-a.number);

    alg_error("Operand must be a number.");
    return alg_nil();
}

/* ------------------------------------------------------------- comparison -- */

/* Chars compare by code point.  The interpreter keys this off the *left*
 * operand -- 'if (left instanceof Character)' -- and then casts the right, so
 * that is the rule reproduced here rather than the tidier "both are Chars".
 * Scanner.pas leans on it: C >= 'a' and C <= 'z'. */
static bool compares_as_char(Value a) {
    return a.type == VAL_CHAR;
}

static int char_order(Value a, Value b) {
    if (b.type != VAL_CHAR) alg_error("Operands must be numbers.");

    unsigned char left  = (unsigned char)a.string[0];
    unsigned char right = (unsigned char)b.string[0];

    return left < right ? -1 : (left > right ? 1 : 0);
}

Value alg_greater(Value a, Value b) {
    if (compares_as_char(a)) return alg_bool(char_order(a, b) > 0);

    if (!is_number(a) || !is_number(b)) alg_error("Operands must be numbers.");
    if (is_double_arithmetic(a, b)) return alg_bool(as_double(a) > as_double(b));
    if (is_bigint(a) || is_bigint(b)) return alg_bool(big_compare(a, b) > 0);
    return alg_bool(a.integer > b.integer);
}

Value alg_greater_equal(Value a, Value b) {
    if (compares_as_char(a)) return alg_bool(char_order(a, b) >= 0);

    if (!is_number(a) || !is_number(b)) alg_error("Operands must be numbers.");
    if (is_double_arithmetic(a, b)) return alg_bool(as_double(a) >= as_double(b));
    if (is_bigint(a) || is_bigint(b)) return alg_bool(big_compare(a, b) >= 0);
    return alg_bool(a.integer >= b.integer);
}

Value alg_less(Value a, Value b) {
    if (compares_as_char(a)) return alg_bool(char_order(a, b) < 0);

    if (!is_number(a) || !is_number(b)) alg_error("Operands must be numbers.");
    if (is_double_arithmetic(a, b)) return alg_bool(as_double(a) < as_double(b));
    if (is_bigint(a) || is_bigint(b)) return alg_bool(big_compare(a, b) < 0);
    return alg_bool(a.integer < b.integer);
}

Value alg_less_equal(Value a, Value b) {
    if (compares_as_char(a)) return alg_bool(char_order(a, b) <= 0);

    if (!is_number(a) || !is_number(b)) alg_error("Operands must be numbers.");
    if (is_double_arithmetic(a, b)) return alg_bool(as_double(a) <= as_double(b));
    if (is_bigint(a) || is_bigint(b)) return alg_bool(big_compare(a, b) <= 0);
    return alg_bool(a.integer <= b.integer);
}

static bool equals(Value a, Value b) {
    if (is_number(a) && is_number(b)) {
        if (is_double_arithmetic(a, b)) return as_double(a) == as_double(b);
        if (is_bigint(a) || is_bigint(b)) return big_compare(a, b) == 0;
        return a.integer == b.integer;
    }
    if (a.type != b.type) return false;

    switch (a.type) {
        case VAL_NIL:    return true;
        case VAL_BOOL:   return a.boolean == b.boolean;
        case VAL_STRING:
        case VAL_CHAR:   return a.length == b.length
                             && memcmp(a.string, b.string, (size_t)a.length) == 0;

        /* Collections compare by identity, as they do on the JVM: two Lists with
         * the same contents are not equal, and a List is equal to itself. */
        case VAL_OBJ:    return a.obj == b.obj;
        default:         return false;
    }
}

/* Membership and Map keys compare *strictly*: an Integer never matches a Double,
 * so 1 is not in [1.0] even though 1 = 1.0.  That is what the interpreter does --
 * '=' promotes numerically while membership and hash lookup do not -- and the
 * compiler has to agree with it rather than with what is tidier.
 * ⚠️ That '=' and membership disagree at all is a rough edge in the language,
 * not something either implementation should quietly smooth over.
 *
 * ⚠️ A Double compares by its BITS here, not with '=='.  Two values behave
 * differently under the two rules, and both of them broke this:
 *
 *   - NaN is not equal to itself under '==', so a NaN key could be stored and
 *     then never found again.  A hash table cannot be built over a relation
 *     where a value is not equal to itself -- no hash function repairs that,
 *     because the defect is in the equality, not in the hashing.
 *   - '-0.0 == 0.0' is true, so they were one key.
 *
 * The interpreter has always done it this way: its Map, List and Set all key
 * on a bit comparison of the Double.  So this CLOSES
 * a divergence rather than opening one, and it does so for Set and List too,
 * since seq_index_of comes through here as well.
 *
 * ⚠️ The '=' OPERATOR is unaffected: it goes through equals(), where NaN = NaN
 * stays false and -0.0 = 0.0 stays true, as IEEE says.  Only membership and key
 * identity changed, which is the trade every hashed language makes. */
/* The relation behind 'in', Contains and Map key lookup.
 *
 * ⚠️ It PROMOTES, because membership and equality are one relation [VAL-013]:
 * if X = Y then a collection holding Y contains X, so a Map keyed 1 is found by
 * 1.0.  This used to compare strictly, which meant a program could hold two
 * values it called equal and find only one of them.  Both halves were
 * defensible alone -- '=' promotes because arithmetic does, and membership was
 * strict because a hash table cannot be built over a relation that promotes.
 * The second is a statement about the implementation, and it is the one that
 * gave way: hash_value now brings an Integer and a Double of one value to the
 * same slot.
 *
 * ⚠️ NaN is the single departure from 'equals', and [VAL-013] permits it: the
 * rule is an IMPLICATION, so a pair that is not equal is unconstrained by it.
 * All NaNs are one KEY -- what doubleToLongBits does -- because a Map that
 * cannot find a key it holds is broken in a way no rule asks for. */
static bool strict_equals(Value a, Value b) {
    if (is_number(a) && is_number(b)) {
        if (a.type == VAL_DOUBLE && b.type == VAL_DOUBLE
            && isnan(a.number) && isnan(b.number)) return true;

        return equals(a, b);
    }

    if (a.type != b.type) return false;

    switch (a.type) {
        case VAL_NIL:    return true;
        case VAL_BOOL:   return a.boolean == b.boolean;
        case VAL_INT:
        case VAL_DOUBLE: return false;   /* handled above; both are numbers */
        case VAL_STRING:
        case VAL_CHAR:   return a.length == b.length
                             && memcmp(a.string, b.string, (size_t)a.length) == 0;
        case VAL_OBJ:    return a.obj == b.obj;
    }
    return false;
}

Value alg_equal(Value a, Value b)     { return alg_bool(equals(a, b)); }
Value alg_not_equal(Value a, Value b) { return alg_bool(!equals(a, b)); }
Value alg_not(Value a)                { return alg_bool(!alg_truthy(a)); }

bool alg_truthy(Value v) {
    /* Matches Interpreter.isTruthy, which defines the language.  Note this is
     * *not* Lox's rule, which this comment used to claim: an Integer 0 is
     * falsey, and so is the first member of any enum, because its ordinal is 0.
     * A Double 0.0, a Char and an empty String are all truthy -- the
     * interpreter special-cases Integer and enum and nothing else. */
    if (v.type == VAL_NIL)  return false;
    if (v.type == VAL_BOOL) return v.boolean;
    if (v.type == VAL_INT)  return v.integer != 0;

    if (is_obj(v, OBJ_ENUM)) return ((ObjEnum *)v.obj)->ordinal != 0;

    return true;
}

/* ----------------------------------------------------------------- output --
 *
 * Doubles render in Algol-24's specified format, not printf's: the shortest
 * digit string that parses back to the same value, positional between 10^-3 and
 * 10^7 and scientific outside it, always with a digit after the point so an
 * integral Double reads as '100.0' rather than '100'.
 *
 * This is the twin of the interpreter's own renderer.  The two must agree
 * exactly -- the compiler
 * is verified by comparing stdout against the interpreter -- so they run the
 * same naive algorithm rather than one using printf and the other Ryu.
 */
#define POSITIONAL_MIN (-3)
#define POSITIONAL_MAX 7

/* Re-renders "d.ddde±XX".  The scientific form is produced and then rewritten
 * rather than using '%g' directly, because '%g' picks positional versus
 * scientific on its own terms and would print 100.0 as '1e+02'. */
static const char *render_double(const char *scientific) {
    bool negative = (*scientific == '-');
    if (negative) scientific++;

    const char *marker = strchr(scientific, 'e');
    if (marker == NULL) alg_error("Malformed double.");

    /* %.17e yields at most 18 significant digits. */
    char digits[24];
    size_t count = 0;
    for (const char *p = scientific; p < marker; p++) {
        if (*p != '.') digits[count++] = *p;
    }
    digits[count] = '\0';

    int exponent = atoi(marker + 1);

    char out[64];
    size_t i = 0;
    if (negative) out[i++] = '-';

    if (exponent >= POSITIONAL_MIN && exponent < POSITIONAL_MAX) {
        if (exponent < 0) {
            /* 0.00ddd -- a leading zero, the gap, then every digit. */
            out[i++] = '0';
            out[i++] = '.';
            for (int zero = 0; zero < -exponent - 1; zero++) out[i++] = '0';

            memcpy(out + i, digits, count);
            i += count;
        }
        else {
            size_t whole = (size_t)exponent + 1;

            if (count <= whole) {
                /* Fewer digits than places: pad, and there is no fraction left
                 * to print, so add the '.0' that keeps it visibly a Double. */
                memcpy(out + i, digits, count);
                i += count;

                for (size_t zero = count; zero < whole; zero++) out[i++] = '0';

                out[i++] = '.';
                out[i++] = '0';
            }
            else {
                memcpy(out + i, digits, whole);
                i += whole;

                out[i++] = '.';
                memcpy(out + i, digits + whole, count - whole);
                i += count - whole;
            }
        }
    }
    else {
        out[i++] = digits[0];
        out[i++] = '.';

        if (count > 1) {
            memcpy(out + i, digits + 1, count - 1);
            i += count - 1;
        }
        else {
            out[i++] = '0';
        }
        i += (size_t)snprintf(out + i, sizeof out - i, "E%d", exponent);
    }
    out[i] = '\0';

    char *result = arena_alloc(i + 1);
    memcpy(result, out, i + 1);

    return result;
}

static const char *alg_double_text(double value) {
    if (isnan(value)) return "NaN";
    if (isinf(value)) return value < 0 ? "-Infinity" : "Infinity";

    /* Raise the precision until the text parses back to the value.  Deliberately
     * the naive algorithm rather than Ryu: a dozen lines, obviously correct,
     * costs only what printing costs, and writable the same way in Algol-24
     * itself later on. */
    char scientific[40];
    snprintf(scientific, sizeof scientific, "%.0e", value);

    for (int precision = 1; precision <= 17; precision++) {
        if (strtod(scientific, NULL) == value) break;
        snprintf(scientific, sizeof scientific, "%.*e", precision, value);
    }
    return render_double(scientific);
}

/* A growable text buffer over the arena.  Growing abandons the old allocation,
 * which is the arena's whole bargain. */
typedef struct {
    char   *text;
    size_t  length;
    size_t  capacity;
} Builder;

static void builder_append(Builder *b, const char *text) {
    size_t added = strlen(text);

    if (b->length + added + 1 > b->capacity) {
        size_t capacity = b->capacity < 32 ? 32 : b->capacity;
        while (b->length + added + 1 > capacity) capacity *= 2;

        char *grown = arena_alloc(capacity);
        if (b->length > 0) memcpy(grown, b->text, b->length);

        b->text     = grown;
        b->capacity = capacity;
    }
    memcpy(b->text + b->length, text, added + 1);
    b->length += added;
}

/* Collections print in the shape of their literals -- '[1, 2, 3]' and
 * '[a:1, b:2]'.  The Map form is specified rather than inherited from whatever
 * a host map happens to print: the interpreter used to hand one back that
 * spells it '{a=1}' using braces and '=', neither of which is Algol-24
 * syntax. */
/* ⚠️ NOT A CATCH-ALL, though as_text used it as one.  Anything that is not a
 * Map was cast to ObjSeq* and its count read, so a heap object of any other
 * kind reaching here crashed rather than saying anything -- which is how a
 * missing OBJ_BOUND case in as_text became a SIGSEGV.  A kind this does not
 * know is an error naming itself now, not a wild read. */
static const char *collection_text(Value v) {
    Builder b = { NULL, 0, 0 };

    if (!is_sequence(v) && v.obj->type != OBJ_MAP) {
        char message[64];
        snprintf(message, sizeof message,
                 "A value of object kind %d has no text form.", (int)v.obj->type);

        alg_error(message);
    }

    builder_append(&b, "[");

    if (v.obj->type != OBJ_MAP) {
        ObjSeq *seq = (ObjSeq *)v.obj;

        for (int32_t i = 0; i < seq->count; i++) {
            if (i > 0) builder_append(&b, ", ");
            builder_append(&b, as_text(seq->items[i]));
        }
    }
    else {
        ObjMap *map = (ObjMap *)v.obj;

        for (int32_t i = 0; i < map->count; i++) {
            if (i > 0) builder_append(&b, ", ");

            builder_append(&b, as_text(map->entries[i].key));
            builder_append(&b, ":");
            builder_append(&b, as_text(map->entries[i].value));
        }
    }
    builder_append(&b, "]");

    return b.text;
}

static const char *as_text(Value v) {
    switch (v.type) {
        case VAL_NIL:    return "nil";
        case VAL_BOOL:   return v.boolean ? "true" : "false";

        /* ⚠️ NUL-TERMINATED for the caller, which is what the twenty-odd
         * strlen-based consumers of this function need -- every one of them
         * builds a diagnostic.
         *
         * Almost always it already is, and the check is one byte.  An in-place
         * append in concat is the only thing that can leave a String without
         * one: the appended text overwrites the terminator that an ALIAS of the
         * shorter view was relying on.  That alias reads its own length
         * everywhere that matters, and gets a terminated copy here.
         *
         * ⚠️ Reading v.string[v.length] is always in bounds.  Either the byte is
         * this String's own terminator, or an append has written text there. */
        case VAL_STRING:
        case VAL_CHAR: {
            if (v.string[v.length] == '\0') return v.string;

            char *terminated = arena_alloc((size_t)v.length + 1);
            memcpy(terminated, v.string, (size_t)v.length);
            terminated[v.length] = '\0';

            return terminated;
        }
        case VAL_OBJ:
            if (v.obj->type == OBJ_CLOSURE) {
                Builder b = { NULL, 0, 0 };
                builder_append(&b, "<fn ");
                builder_append(&b, ((ObjClosure *)v.obj)->name);
                builder_append(&b, ">");
                return b.text;
            }
            /* A big Integer prints as the number it is -- the representation
             * is the runtime's business, not the program's. */
            if (v.obj->type == OBJ_BIGINT)    return big_to_text((ObjBigInt *)v.obj);

            if (v.obj->type == OBJ_ENUM)      return ((ObjEnum *)v.obj)->name;
            if (v.obj->type == OBJ_ENUM_TYPE) return ((ObjEnumType *)v.obj)->name;

            /* ⚠️ A METHOD READ WITHOUT CALLING IT, which had no case here and
             * fell through to collection_text -- which casts anything that is
             * not a Map to ObjSeq* and reads a count out of it.  'WriteLn
             * (B.Length)' on a class with a Length method died of SIGSEGV with
             * no output at all, the earlier lines lost with the buffer.
             *
             * Prints as the interpreter's does: '<fn Name>' [TYP-012]. */
            if (v.obj->type == OBJ_BOUND) {
                Builder b = { NULL, 0, 0 };
                builder_append(&b, "<fn ");
                builder_append(&b, ((ObjBound *)v.obj)->method->name);
                builder_append(&b, ">");
                return b.text;
            }

            /* ⚠️ A BUILT-IN member read without calling it prints the same way,
             * because it is the same kind of thing.  The interpreter printed
             * 'CollectionMethod instance' here, naming a class that exists only
             * inside algc; it prints '<fn Sort>' now, from the same spelling
             * this uses -- the one the program wrote. */
            if (v.obj->type == OBJ_BUILTIN_BOUND) {
                Builder b = { NULL, 0, 0 };
                builder_append(&b, "<fn ");
                builder_append(&b, ((ObjBuiltinBound *)v.obj)->name);
                builder_append(&b, ">");
                return b.text;
            }

            if (v.obj->type == OBJ_INSTANCE) {
                ObjClass *klass = ((ObjInstance *)v.obj)->klass;

                /* A class with a ToString() decides how it prints. */
                if (has_method(v, "ToString", 0)) {
                    return as_text(alg_invoke(v, "ToString", NULL, 0));
                }

                /* An object is named, not described: it prints as 'Counter'
                 * where a class instance prints as 'Counter instance'. */
                if (klass->is_object) return klass->name;

                Builder b = { NULL, 0, 0 };
                builder_append(&b, klass->name);
                builder_append(&b, " instance");
                return b.text;
            }
            if (v.obj->type == OBJ_CLASS) return ((ObjClass *)v.obj)->name;

            /* ⚠️ Its SIZE, not its contents and not its capacity.  Capacity is
             * a function of allocation history and printing it would make the
             * emitted C depend on how the compiler grew its buffers, which the
             * fixed-point check would catch and no one would enjoy diagnosing.
             * Contents are left out for a plainer reason: a Buffer is bytes,
             * which may not be text at all, and a compiler's is 700 KB of it.
             * Text is the way to ask for the contents, and it is explicit. */
            if (v.obj->type == OBJ_BUFFER) {
                ObjBuffer *buffer = (ObjBuffer *)v.obj;
                if (buffer->freed) return "Buffer(freed)";

                char *text = arena_alloc(32);
                snprintf(text, 32, "Buffer(%d)", (int32_t)buffer->length);
                return text;
            }
            return collection_text(v);

        case VAL_INT: {
            /* ⚠️ 24, not 12.  An Integer is 64 bits wide before it promotes, so
             * the longest is 20 characters and a sign -- it was 12 while an
             * Integer was 32 bits, and widening the type without widening this
             * wrote past the allocation into whatever the arena handed out
             * next.  The string itself read back correctly, so the damage
             * showed up in an unrelated value. */
            char *buffer = arena_alloc(24);
            snprintf(buffer, 24, "%lld", (long long)v.integer);
            return buffer;
        }

        case VAL_DOUBLE:
            return alg_double_text(v.number);
    }
    return "";
}

/* ------------------------------------------------------------ test runner -- */

static int32_t tests_passed = 0;
static int32_t tests_failed = 0;

/* True while --test is running, so a test body's output is swallowed rather
 * than interleaved with the report.  See alg_test_begin. */
static bool in_tests = false;

/* The report's colours, which are Console.a24's and must stay its byte for
 * byte: the two reports are compared as text, so a code that differs is a
 * difference like any other.
 *
 * ⚠️ Emitted UNCONDITIONALLY, exactly as the interpreter emits them.  Testing
 * isatty here would be the usual courtesy and is the wrong thing: the
 * interpreter has no way to ask -- there is no such builtin in the language --
 * so the compiled report would lose its colour down a pipe while the
 * interpreted one kept it, and the two would no longer be comparable in the one
 * place a harness actually looks at them.  Anything reading these strips first;
 * see the ANSI pattern in the VS Code extension and in test.sh. */
#define ANSI_RESET "\033[0m"
#define ANSI_RED   "\033[31m"
#define ANSI_GREEN "\033[32m"
#define ANSI_BLUE  "\033[34m"
#define ANSI_CYAN  "\033[36m"
#define ANSI_WHITE "\033[37m"

/* '[INFO] ' -- the tag every report line opens with, trailing space included. */
#define INFO_TAG ANSI_WHITE "[" ANSI_BLUE "INFO" ANSI_WHITE "] " ANSI_RESET

/* '[ERROR] ' -- the same shape, for the line a failing test prints.  Must match
 * Console.a24's ERROR_TAG byte for byte: the two reports are compared. */
#define ERROR_TAG ANSI_WHITE "[" ANSI_RED "ERROR" ANSI_WHITE "] " ANSI_RESET

/* The file the run was started from.  ⚠️ Not the file a failing test lives in:
 * the interpreter reports the ROOT for every failure, because SourceCode is one
 * global keyed by line number, and the two reports have to agree. */
static const char *test_root = "";

void alg_test_begin(int32_t count, const char *file) {
    test_root = file;
    /* The interpreter flips Screen to Buffer mode for the duration of a test
     * run, which prints nothing, so a test body's own Write and WriteLn stay
     * out of the report.  Compiled code has to do the same or the two reports
     * differ by exactly the lines the program chose to print. */
    in_tests = true;

    printf(INFO_TAG "Running %d tests...\n", count);
}

/* Files report in the order their tests were first met, which for 'uses' is
 * load order.  Each file's block ends with a blank line, including the last. */
void alg_test_file(const char *file) {
    printf(INFO_TAG "< " ANSI_CYAN "%s" ANSI_RESET " >\n", file);
}

void alg_test_end_file(void) {
    printf(INFO_TAG "\n");
}

/* An assertion failure raises, so a frame here turns it into a FAIL rather than
 * ending the process -- the same shape as the interpreter catching RuntimeError
 * around each test. */
void alg_test_run(const char *name, AlgFunction body) {
    AlgFrame frame;
    alg_push_frame(&frame);

    bool ok;
    if (ALG_SETJMP(frame.jump) == 0) {
        body(NULL, NULL, 0);
        alg_pop_frame();
        ok = true;
    }
    else {
        ok = false;
    }

    if (ok) tests_passed++; else tests_failed++;

    /* The dot leader is clamped, so a name longer than the banner cannot ask for
     * a negative repeat.
     *
     * ⚠️ Measured on the NAME alone, before any colour joins it.  An escape is
     * bytes with no width, so counting them would pad every line by the length
     * of a code and the leaders would not line up. */
    int leader = 55 - (int)strlen(name);
    if (leader < 1) leader = 1;

    printf(INFO_TAG "Test: %s ", name);
    for (int i = 0; i < leader; i++) putchar('.');
    printf(" [ %s%s" ANSI_RESET " ]\n", ok ? ANSI_GREEN : ANSI_RED,
                                        ok ? "PASS" : "FAIL");

    /* ⚠️ WHY it failed, which this used to throw away.  The frame carries the
     * raised value and nothing read it, so a compiled suite reported that a
     * test failed and never what -- and that is why the two processors could
     * disagree about AssertTrue's wording for as long as they did, since
     * nothing comparing the two reports ever looked at this line.
     *
     * ⚠️ The interpreter prints exactly one line here, not three.  Console.Error
     * adds a source line and a caret, but a test failure does not go through
     * it, so there is nothing compiled code cannot reproduce. */
    if (!ok) printf(ERROR_TAG "%s: %s\n", test_root, as_text(frame.raised));
}

int alg_test_summary(void) {
    if (tests_failed == 0) {
        printf(INFO_TAG ANSI_GREEN "All %d tests passed." ANSI_RESET "\n", tests_passed);
        return 0;
    }
    printf(INFO_TAG ANSI_RED "%d of %d tests failed." ANSI_RESET "\n",
           tests_failed, tests_passed + tests_failed);

    return 70;
}

void alg_assert_true(Value value) {
    if (alg_truthy(value)) return;

    /* ⚠️ Names the value that was false [TST-012].  This said 'Assertion
     * failed.' and nothing else, where the interpreter said 'Assertion
     * ''left = right'' failed.' -- so the two processors disagreed on the
     * message a programmer reads most often, and nothing caught it, because a
     * report comparison drops the [ERROR] lines an assertion failure prints. */
    char message[512];
    snprintf(message, sizeof message,
             "Assertion failed.  Expected true but got '%s'.", as_text(alg_str(value)));

    alg_error(message);
}

void alg_assert_equal(Value expected, Value actual) {
    if (equals(expected, actual)) return;

    /* The values were missing here entirely, where the interpreter has always
     * shown them -- invisible because a report comparison drops the [ERROR]
     * lines an assertion failure prints.  Both implementations have to produce
     * the same sentence. */
    const char *left  = as_text(alg_str(expected));
    const char *right = as_text(alg_str(actual));

    char message[512];

    /* Types named only when the printed forms match, which is the case that
     * otherwise reads as nonsense: a Char and a String both print as 3. */
    if (strcmp(left, right) == 0) {
        snprintf(message, sizeof message,
                 "Assertion failed.  Expected %s '%s' but got %s '%s'.",
                 type_name(expected), left, type_name(actual), right);
    }
    else {
        snprintf(message, sizeof message,
                 "Assertion failed.  Expected '%s' but got '%s'.", left, right);
    }
    alg_error(message);
}

void alg_assert_fail(Value message) {
    char text[512];
    snprintf(text, sizeof text, "Failed.  %s", as_text(alg_str(message)));
    alg_error(text);
}

/* ---------------------------------------------------------------- strings --
 *
 * The messages here match the interpreter's, which were rewritten to stop
 * naming host exception classes -- 'Mod failed: ArithmeticException' is not
 * something a second implementation can reproduce.
 */
static const char *as_string(Value v, const char *what) {
    if (!is_text(v)) alg_error(what);

    /* Through as_text, so an alias left un-terminated by an in-place append is
     * terminated here too -- Pos searches with strstr. */
    return as_text(v);
}

/* An Integer narrowed to the machine width the caller needs.
 *
 * ⚠️ CHECKED, not cast.  An Integer is wider than a size, an offset or a code
 * point, so every place that needs a machine integer asks here and gets a
 * diagnostic rather than a truncation.  One honest gate beats a silent wrap in
 * several places -- and there are several: a Buffer's size and offset, a byte,
 * ParamStr's index, Copy's start and count, Char's code point, Halt's status.
 *
 * ⚠️ Arithmetic does NOT come through here.  '+' and its neighbours work at the
 * Integer's own width; this is only for crossing into C's. */
static int32_t as_integer(Value v, const char *what) {
    if (v.type != VAL_INT) alg_error(what);

    if (v.integer < INT32_MIN || v.integer > INT32_MAX) {
        char message[96];
        snprintf(message, sizeof message, "Integer %lld is too large to use here.",
                 (long long)v.integer);
        alg_error(message);
    }
    return (int32_t)v.integer;
}

Value alg_copy(Value text, Value begin, Value length) {
    const char *from  = as_string(text, "Copy expects a String.");
    int32_t     start = as_integer(begin, "Copy expects an Integer start.");
    int32_t     count = as_integer(length, "Copy expects an Integer length.");

    /* ⚠️ Start and count are in CHARACTERS [SRC-004]; the copy itself is in
     * bytes, so both ends are converted. */
    int32_t size = utf8_count(from, text.length);

    if (start < 0 || start > size) {
        char message[80];
        snprintf(message, sizeof message, "Copy failed: Start %d out of range 0..%d.", start, size);
        alg_error(message);
    }
    if (count < 0) alg_error("Copy failed: Length cannot be negative.");

    /* The end is clamped rather than checked, so asking for more than remains
     * yields what is there. */
    int32_t end = start + count;
    if (end > size) end = size;

    int32_t from_byte = utf8_offset(from, text.length, start);
    int32_t to_byte   = utf8_offset(from, text.length, end);

    int32_t taken  = to_byte - from_byte;
    char   *result = arena_alloc((size_t)taken + 1);

    memcpy(result, from + from_byte, (size_t)taken);
    result[taken] = '\0';

    return alg_string_n(result, taken);
}

Value alg_pos(Value text, Value part) {
    const char *haystack = as_string(text, "Pos expects a String.");
    const char *needle   = as_string(part, "Pos expects a String.");

    const char *found = strstr(haystack, needle);

    /* -1 rather than 0 when absent, so position 0 is usable.
     *
     * ⚠️ strstr answers a BYTE offset and a program counts characters
     * [SRC-004], so the answer is converted.  A UTF-8 sequence cannot occur
     * inside another one, so a byte match is always a character match. */
    if (found == NULL) return alg_int(-1);

    return alg_int(utf8_chars_in(haystack, (int32_t)(found - haystack)));
}

Value alg_char(Value code) {
    int32_t point = as_integer(code, "Char expects an Integer.");

    /* ⚠️ A Unicode code point [LEX-025], less the surrogates D800..DFFF, which
     * encode no character.
     *
     * This used to be 0..127, on the grounds that anything above would 'have to
     * encode UTF-8 to agree with the interpreter'.  It does encode UTF-8 now --
     * alg_char_value is the single place that does it, so the two agree by
     * construction rather than by both being restricted.
     *
     * ⚠️ ZERO IS STILL ADMITTED HERE, and only the LITERAL '#0' is refused, in
     * the scanner [LEX-032].  [LEX-025] puts a Char at 0..10FFFF and refusing
     * the literal is what that rule asks for -- 'when the program is read'.
     * The scanner's own end-of-input sentinel is Char(0), so refusing it here
     * would leave this compiler unable to scan anything, including itself. */
    if (point < 0 || point > 0x10FFFF || (point >= 0xD800 && point <= 0xDFFF)) {
        alg_error("Char is limited to 0..10FFFF, excluding D800..DFFF.");
    }

    return alg_char_value(point);
}

/* Parses a number out of text.  This was called alg_ord, and the comment here
 * used to apologise for the name -- it is Turbo Pascal's Val, and Ord is now
 * what its own name says. */
Value alg_val(Value v) {
    if (v.type == VAL_NIL) return alg_double(-1.0);

    const char *text = as_text(v);

    char  *rest;
    double parsed = strtod(text, &rest);

    if (rest == text || *rest != '\0') {
        Builder b = { NULL, 0, 0 };
        builder_append(&b, "Val failed: '");
        builder_append(&b, text);
        builder_append(&b, "' is not a number.");

        alg_error(b.text);
    }
    Value as_double = alg_double(parsed);

    /* ⚠️ An INTEGER where the text is one [RT-009], reading the same characters
     * the literal rules do [LEX-015].  This answered a Double always, so
     * 'Val("42")' was 42.0 -- and the result could not then be passed to Max,
     * which took Integers only.  The two were individually defensible and
     * jointly unusable: 'Max(Val(A), Val(B))' failed for EVERY input.
     *
     * ⚠️ The digits are accumulated through alg_multiply and alg_add rather
     * than converted from the double, and not because of precision: those carry
     * the range check [LEX-018], so 'Val("99999999999")' raises
     * 'Integer overflow: 999999999 * 10.' exactly as the interpreter's does.
     * A cast would answer a wrong number quietly, and there is no narrowing
     * conversion in the language to write instead. */
    const char *digits = text;
    int32_t     sign   = 1;

    if (*digits == '-') {
        sign = -1;
        digits++;
    }

    /* Nothing but a sign is not an integer; strtod already refused text that is
     * no number at all, so what reaches here is a Double. */
    if (*digits == '\0') return as_double;

    Value result = alg_int(0);
    for (const char *at = digits; *at != '\0'; at++) {
        if (*at < '0' || *at > '9') return as_double;

        result = alg_add(alg_multiply(result, alg_int(10)), alg_int(*at - '0'));
    }
    return alg_multiply(alg_int(sign), result);
}

/* The ordinal value of an ordinal-typed value, as in Turbo Pascal.
 *
 * A Char gives its code point -- the inverse of Char(n) -- a Boolean gives 0 or
 * 1, an enum member gives its position in its own type, and an Integer is
 * already an ordinal.  Nothing else has one: a Double is not an ordinal type
 * and neither is a String, and 'Ord("65")' being 65 is exactly the confusion
 * this separation exists to end. */
Value alg_ord(Value v) {
    /* A Char is held as a one-character C string rather than a number, so the
     * code point is that character -- unsigned, or a high byte would sign-extend
     * to a negative ordinal. */
    if (v.type == VAL_CHAR) return alg_int(utf8_decode(v.string));

    if (v.type == VAL_BOOL) return alg_int(v.boolean ? 1 : 0);
    if (v.type == VAL_INT)  return alg_int(v.integer);

    if (v.type == VAL_OBJ && v.obj->type == OBJ_ENUM) {
        return alg_int(((ObjEnum *)v.obj)->ordinal);
    }

    Builder b = { NULL, 0, 0 };
    builder_append(&b, "Ord failed: '");
    builder_append(&b, as_text(v));
    builder_append(&b, "' has no ordinal.");

    alg_error(b.text);
    return alg_nil();
}

Value alg_clock(void) {
    struct timeval now;
    gettimeofday(&now, NULL);

    /* Milliseconds first, then divided, so the value has the same granularity
     * as the interpreter's rather than a finer one. */
    long long millis = (long long)now.tv_sec * 1000 + now.tv_usec / 1000;

    return alg_double((double)millis / 1000.0);
}

/* ⚠️ Any two NUMBERS, promoting as every other numeric operator does [EXP-005]
 * and answering the argument itself, so 'Max(3.5, 2)' is the Double 3.5.  This
 * took Integers only, which with Val always yielding a Double left
 * 'Max(Val(A), Val(B))' failing for every input [RT-010]. */
Value alg_max(Value a, Value b) {
    bool numbers = (a.type == VAL_INT || a.type == VAL_DOUBLE)
                && (b.type == VAL_INT || b.type == VAL_DOUBLE);

    if (!numbers) alg_error("Max expects numbers.");

    return alg_truthy(alg_greater(a, b)) ? a : b;
}

Value alg_mod(Value a, Value b) {
    /* At the Integer's own width: Mod is arithmetic, not a crossing into C. */
    if (!is_integer(a)) alg_error("Mod expects Integers.");
    if (!is_integer(b)) alg_error("Mod expects Integers.");

    if (is_bigint(a) || is_bigint(b)) {
        ObjBigInt *x = as_big(a);
        ObjBigInt *y = as_big(b);

        if (y->count == 0) alg_error("Mod failed: Division by zero.");

        ObjBigInt *quotient;
        ObjBigInt *remainder;
        mag_divmod(x, y, &quotient, &remainder);

        /* C's sign rule, which the Integer path also follows: the remainder
         * takes the sign of the dividend. */
        remainder->negative = x->negative;
        return big_value(remainder);
    }

    int64_t left  = a.integer;
    int64_t right = b.integer;

    if (right == 0) alg_error("Mod failed: Division by zero.");

    /* INT_MIN % -1 overflows on some targets; the JVM yields 0. */
    if (left == INT64_MIN && right == -1) return alg_int(0);

    return alg_int(left % right);
}

/* ⚠️ fwrite with the length, not fputs.  A String may hold a zero character and
 * fputs would stop at it -- which is the truncation this change exists to end. */
void alg_write(Value v) {
    if (in_tests) return;

    int32_t     length;
    const char *text = as_text_len(v, &length);

    fwrite(text, 1, (size_t)length, stdout);
}

void alg_writeln(Value v) {
    alg_write(v);
    if (in_tests) return;

    fputc('\n', stdout);
}

/* 'WriteLn ()' -- the newline on its own.
 *
 * ⚠️ WriteLn takes nothing OR one value, and only the one-value form had a
 * mapping here, so a bare 'WriteLn ()' was refused by name -- a valid program
 * with no compiled form (C-36).  The emitter's table is keyed by name AND
 * arity, which is what let one of the two forms go missing unnoticed. */
void alg_writeln_blank(void) {
    alg_writeln(alg_string(""));
}

/* ⚠️ Flushes first.  stdout is block-buffered when it is not a terminal, and
 * exit() would otherwise discard whatever the report had written -- so a test
 * run that halted printed nothing at all when piped. */
void alg_halt(Value status) {
    int32_t code = as_integer(status, "Halt expects an Integer.");

    fflush(stdout);
    fflush(stderr);

    exit(code);
}

Value alg_str(Value v) {
    int32_t     length;
    const char *text = as_text_len(v, &length);

    return alg_string_n(text, length);
}
