#include "algol.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <unistd.h>

#if defined(__APPLE__)
#include <mach-o/dyld.h>
#endif

#define ARENA_CHUNK (1024 * 1024)

typedef struct ArenaChunk {
    struct ArenaChunk *previous;
} ArenaChunk;

#define ARENA_HEADER ((sizeof(ArenaChunk) + 7u) & ~(size_t)7u)

static ArenaChunk *arena_chunks = NULL;
static char       *arena_next   = NULL;
static size_t      arena_left   = 0;

static const char *arena_tail_text = NULL;
static int32_t     arena_tail_len  = 0;
static int32_t     arena_tail_cap  = 0;

static void close_open_files(void);

static void free_all_buffers(void);

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

    int32_t  *index;
    int32_t   index_mask;
} ObjMap;

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

    int32_t     ordinal;
} ObjEnum;

static bool equals(Value a, Value b);
static bool strict_equals(Value a, Value b);
static const char *as_text(Value v);
static const char *as_text_len(Value v, int32_t *length);
static bool is_number(Value v);
static bool is_text(Value v);
static int32_t as_integer(Value v, const char *message);

static int32_t utf8_count(const char *text, int32_t bytes);
static int32_t utf8_offset(const char *text, int32_t bytes, int32_t index);
static int32_t utf8_chars_in(const char *text, int32_t bytes);
static int32_t utf8_decode(const char *at);
static int     utf8_span(unsigned char lead);
static int     text_order(Value a, Value b);
static int     method_order(Value a, Value b);
static int utf8_encode(int32_t code, char *out);
_Noreturn static void undefined(const char *what, const char *name);

static bool has_method(Value v, const char *name, int32_t arity);
static double as_double(Value v);

static bool is_obj(Value v, ObjType type) {
    return v.type == VAL_OBJ && v.obj->type == type;
}

static Value object(Obj *obj);

typedef struct {
    Obj obj;

    bool      negative;
    int32_t   count;
    uint32_t *limbs;
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

static void big_trim(ObjBigInt *b) {
    while (b->count > 0 && b->limbs[b->count - 1] == 0) b->count--;
    if (b->count == 0) b->negative = false;
}

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

static const char *big_to_text(const ObjBigInt *value) {
    if (value->count == 0) return "0";

    ObjBigInt *work   = big_copy(value);
    int32_t    room   = value->count * 2 + 2;
    uint32_t  *chunk  = arena_alloc((size_t)room * sizeof(uint32_t));
    int32_t    chunks = 0;

    while (work->count > 0 && chunks < room)
        chunk[chunks++] = mag_divmod_small(work, 1000000000u);

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

static bool is_integer(Value v) { return v.type == VAL_INT || is_bigint(v); }

static ObjBigInt *as_big(Value v) {
    return v.type == VAL_INT ? big_of_i64(v.integer) : (ObjBigInt *)v.obj;
}

static int big_compare(Value a, Value b) {
    ObjBigInt *x = as_big(a);
    ObjBigInt *y = as_big(b);

    if (x->negative != y->negative) return x->negative ? -1 : 1;

    int c = mag_cmp(x, y);
    return x->negative ? -c : c;
}

static bool is_sequence(Value v) {
    if (v.type != VAL_OBJ) return false;

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

typedef struct ObjBuffer {
    Obj obj;

    char  *bytes;
    size_t length;
    size_t capacity;
    bool   freed;

    struct ObjBuffer *next;
} ObjBuffer;

static ObjBuffer *all_buffers = NULL;

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

static Value buffer_text(ObjBuffer *buffer) {
    for (size_t i = 0; i < buffer->length; i++) {
        if (buffer->bytes[i] == '\0') alg_error("A Buffer holding a zero byte has no Text.");
    }

    char *text = arena_alloc(buffer->length + 1);

    if (buffer->length > 0) memcpy(text, buffer->bytes, buffer->length);
    text[buffer->length] = '\0';

    return alg_string(text);
}

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

    for (int64_t i = 0; i < size.integer; i++) seq_append(seq, alg_nil());

    return value;
}

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

#define MAP_INDEX_AT   8
#define MAP_INDEX_SLOTS 32

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

    ValueType tag = v.type;

    if (tag == VAL_INT || is_bigint(v)) tag = VAL_DOUBLE;

    uint32_t hash = hash_bytes(2166136261u, &tag, sizeof tag);

    switch (v.type) {
        case VAL_NIL:    return hash;
        case VAL_BOOL:   return hash_bytes(hash, &v.boolean, sizeof v.boolean);

        case VAL_POINTER: return hash_bytes(hash, &v.pointer, sizeof v.pointer);

        case VAL_INT: {
            double widened = (double)v.integer;
            return hash_bytes(hash, &widened, sizeof widened);
        }

        case VAL_DOUBLE: {

            if (isnan(v.number)) return hash_bytes(hash, "NaN", 3);

            double bits = v.number;
            if (bits == 0.0) bits = 0.0;

            return hash_bytes(hash, &bits, sizeof bits);
        }
        case VAL_STRING:
        case VAL_CHAR:   return hash_bytes(hash, v.string, (size_t)v.length);

        case VAL_OBJ: {
            if (v.obj->type == OBJ_BIGINT) {
                double widened = big_to_double((ObjBigInt *)v.obj);
                return hash_bytes(hash, &widened, sizeof widened);
            }

            void *address = v.obj;
            return hash_bytes(hash, &address, sizeof address);
        }
    }
    return hash;
}

static void map_reindex(ObjMap *map, int32_t slots) {

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

    if (map->index == NULL) {
        for (int32_t i = 0; i < map->count; i++) {
            if (strict_equals(map->entries[i].key, key)) return i;
        }
        return -1;
    }

    uint32_t slot = hash_value(key) & (uint32_t)map->index_mask;

    for (;;) {
        int32_t at = map->index[slot];

        if (at == -1) return -1;
        if (strict_equals(map->entries[at].key, key)) return at;

        slot = (slot + 1) & (uint32_t)map->index_mask;
    }
}

static void map_put(ObjMap *map, Value key, Value item) {

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

Value alg_list_keep(Value list, Value item) {
    seq_append(as_sequence(list, "Expected a List."), item);
    return list;
}

Value alg_map_keep(Value map, Value key, Value item) {
    map_put(as_map(map, "Expected a Map."), key, item);
    return map;
}

static int32_t bounded(Value index, int32_t count, bool inclusive) {
    if (index.type != VAL_INT) alg_error("Index must be an Integer.");

    int64_t at    = index.integer;
    int64_t limit = inclusive ? count : count - 1;

    if (at < 0 || at > limit) {

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

        memmove(&map->entries[found], &map->entries[found + 1],
                (size_t)(map->count - found - 1) * sizeof(MapEntry));
        map->count--;

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

    return alg_int(seq_index_of(as_sequence(receiver, "Only a sequence has 'IndexOf'."), item));
}

Value alg_clear(Value receiver) {
    if (is_obj(receiver, OBJ_MAP)) {
        ObjMap *map = (ObjMap *)receiver.obj;

        map->count = 0;

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

static int compare(Value a, Value b) {
    if (is_number(a) && is_number(b)) {
        double left  = as_double(a);
        double right = as_double(b);

        return left < right ? -1 : (left > right ? 1 : 0);
    }

    if (is_text(a) && is_text(b)) return text_order(a, b);

    alg_error("Can only sort numbers against numbers, or text against text.");
    return 0;
}

Value alg_sort(Value receiver) {
    ObjSeq *seq = as_sequence(receiver, "Only a List or an Array has 'Sort'.");

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

static int32_t count_of(Value v) {
    if (is_obj(v, OBJ_MAP))    return ((ObjMap *)v.obj)->count;
    if (is_sequence(v))        return ((ObjSeq *)v.obj)->count;
    if (is_text(v))            return utf8_count(v.string, v.length);

    if (is_obj(v, OBJ_BUFFER)) return (int32_t)as_buffer(v, "Length")->length;

    alg_error("Only a collection or a String has 'Length'.");
    return 0;
}

Value alg_length(Value v)   { return alg_int(count_of(v)); }
Value alg_is_empty(Value v) { return alg_bool(count_of(v) == 0); }

Value alg_text_length(Value v) {
    if (is_sequence(v) || is_obj(v, OBJ_MAP))
        alg_error("Length expects text; use .Length for a collection.");

    Value text = is_text(v) ? v : alg_str(v);

    return alg_int(utf8_count(text.string, text.length));
}

Value alg_subscript_get(Value target, Value index) {
    if (is_obj(target, OBJ_MAP)) return alg_get(target, index);

    if (is_obj(target, OBJ_BUFFER)) {
        ObjBuffer *buffer = as_buffer(target, "[]");
        return alg_int((unsigned char)buffer->bytes[buffer_offset(buffer, index, 1)]);
    }

    if (is_obj(target, OBJ_SET)) alg_error("Subscript target should be an ordinal.");

    if (is_sequence(target)) {
        ObjSeq *seq = (ObjSeq *)target.obj;
        return seq->items[bounded(index, seq->count, false)];
    }
    if (is_text(target)) {

        int32_t at = bounded(index, utf8_count(target.string, target.length), false);

        return alg_char_value(utf8_decode(target.string
                                          + utf8_offset(target.string, target.length, at)));
    }

    if (has_method(target, "Get", 1)) {
        Value args[1];
        args[0] = index;

        return alg_invoke(target, "Get", args, 1);
    }

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

    if (is_obj(target, OBJ_SET)) alg_error("Subscript target should be an ordinal.");

    if (is_sequence(target)) {
        ObjSeq *seq = (ObjSeq *)target.obj;

        seq->items[bounded(index, seq->count, false)] = value;
        return value;
    }

    if (has_method(target, "Put", 2)) {
        Value args[2];
        args[0] = index;
        args[1] = value;

        return alg_invoke(target, "Put", args, 2);
    }

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

Value alg_iterable(Value v) {
    if (is_obj(v, OBJ_MAP)) return alg_keys(v);

    if (is_obj(v, OBJ_ENUM_TYPE)) {
        ObjEnumType *type     = (ObjEnumType *)v.obj;
        Value        snapshot = alg_list();

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
        /* By CHARACTER, not by byte. Walking bytes made 'for var C in ''café'''
           visit five elements compiled where the interpreter visits four, and
           handed the body the halves of a character rather than the character.
           Bounded by v.length rather than by a NUL, because a String may hold
           a zero byte [RT-008]. */
        for (int32_t at = 0; at < v.length; at += utf8_span((unsigned char)v.string[at]))
            seq_append((ObjSeq *)snapshot.obj, alg_char_value(utf8_decode(v.string + at)));

        return snapshot;
    }

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

typedef struct {
    const char *name;
    AlgMethod   fn;
    int32_t     arity;

    const char **types;

    bool        is_property;

    uint32_t    hash;
} MethodEntry;

typedef struct ObjClass {
    Obj obj;

    const char      *name;
    struct ObjClass *super;

    const char **fields;
    int32_t      field_count;

    int32_t total_fields;

    MethodEntry *methods;
    int32_t      method_count;
    int32_t      method_capacity;

    AlgMethod initializer;

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

static int32_t total_fields(ObjClass *klass) {
    if (klass->total_fields < 0)
        klass->total_fields = klass->field_count
                            + (klass->super == NULL ? 0 : total_fields(klass->super));

    return klass->total_fields;
}

void alg_class_field(Value value, const char *name) {
    ObjClass *klass = as_class(value, "Expected a class.");

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
    klass->methods[klass->method_count].is_property = false;
    klass->method_count++;
}

void alg_class_property(Value value, const char *name, AlgMethod fn) {
    alg_class_method(value, name, fn, 0, NULL);

    ObjClass *klass = as_class(value, "Expected a class.");
    klass->methods[klass->method_count - 1].is_property = true;
}

void alg_class_is_object(Value value) {
    as_class(value, "Expected a class.")->is_object = true;
}

void alg_class_initializer(Value value, AlgMethod fn) {
    as_class(value, "Expected a class.")->initializer = fn;
}

static int32_t field_slot(ObjClass *klass, const char *name) {
    for (ObjClass *at = klass; at != NULL; at = at->super) {
        int32_t base = at->super == NULL ? 0 : total_fields(at->super);

        for (int32_t i = 0; i < at->field_count; i++) {

            if (alg_stricmp(at->fields[i], name) == 0) return base + i;
        }
    }
    return -1;
}

static bool has_method(Value v, const char *name, int32_t arity);

static MethodEntry *find_method(ObjClass *klass, const char *name, int32_t arity, Value *args, bool strict);
static Value alg_bound(Value receiver, MethodEntry *method);
static const char *type_name(Value v);

typedef struct {
    const char *name;
    int32_t     arity;
} Member;

static const Member *member_of(Value receiver, const char *name);
static Value builtin_bound(Value receiver, const char *name, int32_t arity);

static bool has_method(Value v, const char *name, int32_t arity) {
    if (!is_obj(v, OBJ_INSTANCE)) return false;

    for (ObjClass *at = ((ObjInstance *)v.obj)->klass; at != NULL; at = at->super)
        for (int32_t i = 0; i < at->method_count; i++)
            if (at->methods[i].arity == arity
             && alg_stricmp(at->methods[i].name, name) == 0)
                return true;

    return false;
}

static bool is_a(Value v, const char *name) {
    if (!is_obj(v, OBJ_INSTANCE)) return false;

    for (ObjClass *at = ((ObjInstance *)v.obj)->klass; at != NULL; at = at->super) {
        if (alg_stricmp(at->name, name) == 0) return true;
    }
    return false;
}

typedef struct {
    const char *name;
    Value       low;
    Value       high;
} Subrange;

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

static bool in_subrange(Value v, const Subrange *range) {
    if (!is_integer(v)) return false;

    return alg_truthy(alg_greater_equal(v, range->low))
        && alg_truthy(alg_less_equal(v, range->high));
}

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

Value alg_widen(Value argument, const char *declared) {
    if (declared == NULL || *declared == '\0') return argument;

    const Subrange *range = subrange_of(declared);
    if (range != NULL) {
        if (argument.type == VAL_INT && !in_subrange(argument, range))
            out_of_subrange(argument, declared);

        return argument;
    }

    const char *actual = type_name(argument);
    if (!widens_to(actual, declared)) return argument;

    if (alg_stricmp(declared, "Double") == 0) return alg_double((double)argument.integer);

    Value widened = argument;
    widened.type  = VAL_STRING;
    return widened;
}

Value alg_param(Value argument, const char *declared) {
    if (declared == NULL || *declared == '\0') return argument;
    if (alg_stricmp(declared, "Any") == 0)      return argument;

    if (subrange_of(declared) != NULL) return alg_widen(argument, declared);

    const char *actual = type_name(argument);
    if (alg_stricmp(actual, "nil") == 0) return argument;
    if (alg_stricmp(actual, "Any") == 0) return argument;
    if (alg_stricmp(actual, declared) == 0) return argument;

    if (widens_to(actual, declared)) return alg_widen(argument, declared);
    if (is_a(argument, declared)) return argument;

    alg_error("No matching signature for function.");
}

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

static bool type_fits(const char *declared, Value argument, bool widening) {

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

static const char *variadic_element(const char **types, int32_t arity) {
    if (types == NULL || arity <= 0) return NULL;

    static char base[64];
    const char *element = split_type(types[arity - 1], base, sizeof base);

    if (element == NULL) return NULL;
    if (alg_stricmp(base, "List") != 0) return NULL;

    return element;
}

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

static bool any_named(const char **names, int32_t count) {
    if (names == NULL) return false;

    for (int32_t i = 0; i < count; i++)
        if (names[i] != NULL && names[i][0] != '\0') return true;

    return false;
}

static int32_t parameter_at(const char **types, int32_t arity, const char *name) {
    if (types == NULL) return -1;

    for (int32_t i = 0; i < arity; i++) {
        char declared[64];

        if (param_name(types[i], declared, sizeof declared) == NULL) continue;
        if (alg_stricmp(declared, name) == 0) return i;
    }

    return -1;
}

static Value *arrange_args(const char **types, int32_t arity,
                           Value *args, int32_t count, const char **names) {
    if (arity < 0 || arity > 255) return NULL;

    Value *slots  = arena_alloc((size_t)(arity > 0 ? arity : 1) * sizeof(Value));
    bool   filled[256];

    for (int32_t i = 0; i < arity; i++) filled[i] = false;

    for (int32_t i = 0; i < count; i++) {
        const char *name = (names != NULL) ? names[i] : NULL;

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

static bool should_absorb(const char **types, int32_t arity, Value *args, int32_t count) {
    if (arity == count && types_match(types, args, count, true)) return false;

    return types_absorb(types, arity, args, count);
}

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

static MethodEntry *find_method(ObjClass *klass, const char *name, int32_t arity, Value *args, bool strict) {
    MethodEntry *named    = NULL;
    MethodEntry *by_arity = NULL;

    uint32_t want = hash_folded(name);

    for (int pass = 0; pass < 3; pass++) {
        for (ObjClass *at = klass; at != NULL; at = at->super) {
            for (int32_t i = 0; i < at->method_count; i++) {
                if (at->methods[i].hash != want) continue;
                if (alg_stricmp(at->methods[i].name, name) != 0) continue;

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

    if (by_arity != NULL) {
        if (strict) alg_error("No matching signature for function.");

        return by_arity;
    }

    return named;
}

_Noreturn static void arity_error(int32_t expected, int32_t got) {
    char message[64];
    snprintf(message, sizeof message, "Expected %d arguments but got %d.", (int)expected, (int)got);

    alg_error(message);
}

void alg_arity(int32_t got, int32_t expected) {
    if (got != expected) arity_error(expected, got);
}

void alg_declared(bool defined, const char *name) {
    if (defined) return;

    char message[256];
    snprintf(message, sizeof message, "Undefined variable '%s'.", name);

    alg_error(message);
}

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

    for (int32_t i = 0; i < slots; i++) instance->slots[i] = alg_nil();

    Value self = object((Obj *)instance);

    initialize_fields(klass, self);

    MethodEntry *init = find_method(klass, "Init", count, args, false);
    if (init != NULL) {

        alg_arity(count, init->arity);
        init->fn(self, args, count);
    }
    else if (count != 0) {

        arity_error(0, count);
    }
    return self;
}

Value alg_singleton(Value value) {
    ObjClass *klass = as_class(value, "Expected an object.");

    if (!klass->built) {

        klass->built    = true;
        klass->instance = alg_new(value, NULL, 0);
    }
    return klass->instance;
}

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

    Value bound = object((Obj *)member);
    type->members[type->count++] = bound;

    return bound;
}

typedef struct ObjFile {
    Obj obj;

    const char *name;
    FILE       *handle;
    bool        reading;

    struct ObjFile *next;

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

static void close_open_files(void) {
    for (ObjFile *file = all_files; file != NULL; file = file->next) {
        if (file->handle != NULL) {
            fclose(file->handle);
            file->handle = NULL;
        }
    }
    all_files = NULL;
}

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

static Value file_eof(ObjFile *file) {

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

        file->name = to;

        *result = alg_nil();
        return true;
    }

    undefined("property", name);
    return false;
}

Value alg_is(Value v, const char *name) {

    const Subrange *range = subrange_of(name);
    if (range != NULL) return alg_bool(in_subrange(v, range));

    if (v.type == VAL_NIL) return alg_bool(false);

    if (alg_stricmp(type_name(v), name) == 0) return alg_bool(true);

    return alg_bool(is_a(v, name));
}

Value alg_cast(Value v, const char *name) {
    if (v.type == VAL_NIL) return v;

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

/* The four directory built-ins [RT-026]. Each reports through file_error, so a
   directory that cannot be made reads like a file that cannot be opened.
   None of them takes a mode or a recursive flag: MkDir makes ONE directory and
   RmDir removes an empty one, which is what the names say and what keeps RmDir
   from being able to take a tree with it. */
Value alg_mkdir(Value name) {
    const char *path = file_name_argument(name);

    /* 0777 masked by the process umask, as the shell's mkdir does -- so the
       directory lands with whatever permissions the user's environment says,
       rather than with something this runtime picked. */
    if (mkdir(path, 0777) != 0) file_error("MkDir", "cannot create ", path);

    return alg_nil();
}

Value alg_rmdir(Value name) {
    const char *path = file_name_argument(name);

    if (rmdir(path) != 0) file_error("RmDir", "cannot remove ", path);

    return alg_nil();
}

Value alg_chdir(Value name) {
    const char *path = file_name_argument(name);

    if (chdir(path) != 0) file_error("ChDir", "cannot change to ", path);

    return alg_nil();
}

/* Takes nothing. Turbo Pascal's GetDir selects a drive, and this runs where
   there are none -- an argument that could never change the answer would only
   read as though it might. */
Value alg_getdir(void) {
    char here[4096];

    if (getcwd(here, sizeof here) == NULL)
        alg_error("GetDir failed: cannot read the working directory.");

    /* Copied into the arena, because alg_string keeps the POINTER it is handed
       and not the bytes -- and 'here' is gone the moment this returns. */
    size_t size   = strlen(here) + 1;
    char  *result = arena_alloc(size);

    memcpy(result, here, size);

    return alg_string_n(result, (int32_t)(size - 1));
}

Value alg_file_exists(Value name) {
    const char *path = file_name_argument(name);

    FILE *probe = fopen(path, "r");
    if (probe == NULL) return alg_bool(false);

    fclose(probe);
    return alg_bool(true);
}

static int    argument_count  = 0;
static char **argument_values = NULL;
static char  *program_path    = NULL;

static char *resolve_program(char *argv0) {
    char buffer[4096];

#if defined(__APPLE__)
    uint32_t size = (uint32_t)sizeof buffer;
    if (_NSGetExecutablePath(buffer, &size) == 0) {
        char *real = realpath(buffer, NULL);
        if (real != NULL) return real;
    }
#elif defined(__linux__)
    ssize_t used = readlink("/proc/self/exe", buffer, sizeof buffer - 1);
    if (used > 0) {
        buffer[used] = '\0';
        char *real = realpath(buffer, NULL);
        if (real != NULL) return real;
    }
#endif

    if (argv0 != NULL && strchr(argv0, '/') != NULL) {
        char *real = realpath(argv0, NULL);
        if (real != NULL) return real;
    }

    return argv0;
}

void alg_set_arguments(int argc, char **argv) {
    argument_count  = argc;
    argument_values = argv;

    if (argc > 0) program_path = resolve_program(argv[0]);

    atexit(alg_shutdown);
}

Value alg_param_count(void) {

    return alg_int(argument_count > 0 ? argument_count - 1 : 0);
}

Value alg_param_str(Value index) {
    int32_t at = as_integer(index, "ParamStr expects an Integer.");

    if (at < 0 || at >= argument_count) return alg_string("");

    if (at == 0 && program_path != NULL) return alg_string(program_path);

    return alg_string(argument_values[at]);
}

_Noreturn static void undefined(const char *what, const char *name) {
    char message[256];
    snprintf(message, sizeof message, "Undefined %s '%s'.", what, name);
    alg_error(message);
}

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

    if (is_obj(receiver, OBJ_BUFFER)) {
        if (alg_stricmp(name, "Text") == 0) return buffer_text(as_buffer(receiver, "Text"));

        if (alg_stricmp(name, "Address") == 0) {
            ObjBuffer *buffer = as_buffer(receiver, "Address");

            return alg_pointer(buffer->bytes);
        }

        if (alg_stricmp(name, "Length") == 0)  return alg_length(receiver);
        if (alg_stricmp(name, "IsEmpty") == 0) return alg_is_empty(receiver);

        return builtin_member(receiver, name);
    }

    if (is_obj(receiver, OBJ_INSTANCE)) {
        ObjInstance *instance = (ObjInstance *)receiver.obj;

        if (alg_stricmp(name, "ClassName") == 0) return alg_string(instance->klass->name);

        int32_t slot = field_slot(instance->klass, name);
        if (slot >= 0) return instance->slots[slot];

        for (ObjClass *at = instance->klass; at != NULL; at = at->super)
            for (int32_t i = 0; i < at->method_count; i++)
                if (at->methods[i].is_property
                 && alg_stricmp(at->methods[i].name, name) == 0)
                    return at->methods[i].fn(receiver, NULL, 0);

        MethodEntry *method = find_method(instance->klass, name, -1, NULL, false);
        if (method == NULL) undefined("property", name);

        return alg_bound(receiver, method);
    }

    if (is_obj(receiver, OBJ_ENUM)) {
        if (alg_stricmp(name, "Ordinal") == 0) return alg_int(((ObjEnum *)receiver.obj)->ordinal);

        undefined("property", name);
    }

    if (is_obj(receiver, OBJ_ENUM_TYPE)) {
        ObjEnumType *type = (ObjEnumType *)receiver.obj;

        for (int32_t i = 0; i < type->count; i++) {

            if (alg_stricmp(((ObjEnum *)type->members[i].obj)->name, name) == 0)
                return type->members[i];
        }
        undefined("enum member", name);
    }

    /* A String answers 'Length' and nothing else [RT-017]. A Char answers
       nothing at all: a one-character literal is a Char and never a String, so
       it falls through to the message below rather than borrowing a String's
       one property. */
    if (receiver.type == VAL_STRING) {
        if (alg_stricmp(name, "Length") == 0) return alg_length(receiver);

        undefined("property", name);
    }

    /* Only a collection answers both [COL-003]. Asking any other value is a
       question about a property it does not have, not a complaint about
       'Length' in particular -- so it goes through the same two messages every
       other receiver uses. */
    if (is_sequence(receiver) || is_obj(receiver, OBJ_MAP)) {
        if (alg_stricmp(name, "Length") == 0)  return alg_length(receiver);
        if (alg_stricmp(name, "IsEmpty") == 0) return alg_is_empty(receiver);

        return builtin_member(receiver, name);
    }

    if (is_number(receiver)) return builtin_member(receiver, name);

    alg_error("Only instances have properties.");
    return alg_nil();
}

Value alg_set_property(Value receiver, const char *name, Value value) {
    if (!is_obj(receiver, OBJ_INSTANCE)) alg_error("Only instances have fields.");

    ObjInstance *instance = (ObjInstance *)receiver.obj;

    int32_t slot = field_slot(instance->klass, name);

    if (slot < 0) undefined("property", name);

    instance->slots[slot] = value;
    return value;
}

static bool buffer_method(Value receiver, const char *name, Value *args, int32_t count, Value *result) {
    if (!is_obj(receiver, OBJ_BUFFER)) return false;
    (void)count;

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
        int32_t     length;
        const char *text   = as_text_len(args[0], &length);

        buffer_append(buffer, text, (size_t)length);

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

static const Member *row_in(const char *name, const Member *members) {
    for (int32_t i = 0; members[i].name != NULL; i++)
        if (alg_stricmp(name, members[i].name) == 0) return &members[i];

    return NULL;
}

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

    static const Member shared[] = { {"Contains", 1}, {NULL, 0} };

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

    /* A String has no methods at all, only the 'Length' property, so a call
       through one is an undefined property and says so -- the same message
       reading it would give. */
    if (receiver.type == VAL_STRING) undefined("property", name);

    Value result;
    if (number_method(receiver, name, args, count, &result)) return result;
    if (file_method(receiver, name, args, count, &result)) return result;
    if (buffer_method(receiver, name, args, count, &result)) return result;
    if (collection_method(receiver, name, args, count, &result)) return result;

    alg_error("Only instances have properties.");
    return alg_nil();
}

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

typedef struct {
    Obj obj;

    Value        receiver;
    MethodEntry *method;
} ObjBound;

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

static Value builtin_bound(Value receiver, const char *name, int32_t arity) {
    ObjBuiltinBound *bound = arena_alloc(sizeof(ObjBuiltinBound));

    bound->obj.type = OBJ_BUILTIN_BOUND;
    bound->receiver = receiver;
    bound->name     = name;
    bound->arity    = arity;

    return object((Obj *)bound);
}

typedef struct {
    Obj obj;

    const char *name;
    AlgFunction fn;
    Value     **cells;
    int32_t     cell_count;
    int32_t     arity;

    const char **types;
} ObjClosure;

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

    if (cell_count == 0) {
        closure->cells = NULL;
    }
    else {
        closure->cells = arena_alloc((size_t)cell_count * sizeof(Value *));
        memcpy(closure->cells, cells, (size_t)cell_count * sizeof(Value *));
    }
    return object((Obj *)closure);
}

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

    OverloadEntry *entries = arena_alloc((size_t)(set->count + 1) * sizeof(OverloadEntry));
    if (set->count > 0) memcpy(entries, set->entries, (size_t)set->count * sizeof(OverloadEntry));

    entries[set->count].fn    = fn;
    entries[set->count].arity = arity;
    entries[set->count].types = types;

    set->entries = entries;
    set->count++;
    set->capacity = set->count;
}

static Value call_overload(ObjOverloads *set, Value *args, int32_t count) {
    for (int pass = 0; pass < 3; pass++)
        for (int32_t i = 0; i < set->count; i++) {
            OverloadEntry *entry = &set->entries[i];

            if (pass == 2) {
                if (types_absorb(entry->types, entry->arity, args, count))
                    return entry->fn(NULL, absorb_args(entry->arity, args, count), entry->arity);

                continue;
            }

            if (entry->arity == count && types_match(entry->types, args, count, pass == 1))
                return entry->fn(NULL, args, count);
        }

    alg_error("No matching signature for function.");
    return alg_nil();
}

Value alg_call(Value callee, Value *args, int32_t count) {

    if (is_obj(callee, OBJ_CLASS)) return alg_new(callee, args, count);

    if (is_obj(callee, OBJ_BOUND)) {
        ObjBound *bound = (ObjBound *)callee.obj;

        return invoke_found(bound->method, bound->receiver, args, count);
    }

    if (is_obj(callee, OBJ_OVERLOADS))
        return call_overload((ObjOverloads *)callee.obj, args, count);

    if (is_obj(callee, OBJ_BUILTIN_BOUND)) {
        ObjBuiltinBound *bound = (ObjBuiltinBound *)callee.obj;

        alg_arity(count, bound->arity);
        return alg_invoke(bound->receiver, bound->name, args, count);
    }

    if (!is_obj(callee, OBJ_CLOSURE)) alg_error("Can only call functions and classes.");

    ObjClosure *closure = (ObjClosure *)callee.obj;

    if (should_absorb(closure->types, closure->arity, args, count))
        return closure->fn(closure->cells, absorb_args(closure->arity, args, count), closure->arity);

    alg_arity(count, closure->arity);

    return closure->fn(closure->cells, args, count);
}

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

    alg_error("A built-in has no named parameters.");
    return alg_nil();
}

Value alg_invoke_named(Value receiver, const char *name, Value *args, int32_t count,
                       const char **names) {
    if (!any_named(names, count)) return alg_invoke(receiver, name, args, count);

    if (is_obj(receiver, OBJ_INSTANCE)) {
        ObjInstance *instance = (ObjInstance *)receiver.obj;

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

    AlgFrame *frame = frames;
    frames = frame->previous;

    frame->raised = value;
    ALG_LONGJMP(frame->jump, 1);
}

_Noreturn void alg_error(const char *message) {

    if (frames != NULL) {

        size_t size = strlen(message) + 1;
        char  *kept = arena_alloc(size);
        memcpy(kept, message, size);

        alg_raise(alg_string(kept));
    }

    fprintf(stderr, "Uncaught: %s\n", message);
    exit(70);
}

static const char *type_name(Value v) {
    switch (v.type) {
        case VAL_NIL:    return "nil";
        case VAL_BOOL:   return "Boolean";
        case VAL_INT:    return "Integer";
        case VAL_DOUBLE: return "Double";
        case VAL_STRING: return "String";
        case VAL_CHAR:   return "Char";
        case VAL_POINTER: return "Pointer";
        case VAL_OBJ:    break;
    }
    switch (v.obj->type) {
        case OBJ_INSTANCE: return ((ObjInstance *)v.obj)->klass->name;

        case OBJ_ENUM:     return ((ObjEnum *)v.obj)->type;

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

Value alg_nil(void)              { Value v; v.type = VAL_NIL;    v.length = 0; v.integer = 0; return v; }
Value alg_bool(bool b)           { Value v; v.type = VAL_BOOL;   v.length = 0; v.boolean = b; return v; }
Value alg_int(int64_t i)         { Value v; v.type = VAL_INT;    v.length = 0; v.integer = i; return v; }

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

Value alg_pointer(void *address) {
    Value v;
    v.type    = VAL_POINTER;
    v.length  = 0;
    v.pointer = address;
    return v;
}

Value alg_string_n(const char *s, int32_t n) {
    Value v;
    v.type   = VAL_STRING;
    v.length = n;
    v.string = s;
    return v;
}

Value alg_string(const char *s)  { return alg_string_n(s, (int32_t)strlen(s)); }

Value alg_char_value(int32_t code) {

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

static bool is_number(Value v) {
    return v.type == VAL_INT || v.type == VAL_DOUBLE || is_obj(v, OBJ_BIGINT);
}

static bool is_text(Value v) {
    return v.type == VAL_STRING || v.type == VAL_CHAR;
}

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

typedef struct {
    const char *text;

    int32_t     bytes;

    int32_t     chars;
    int         ascii;

    int32_t     at_char;
    int32_t     at_byte;
} TextInfo;

#define TEXT_CACHE_SLOTS 64
static TextInfo text_cache[TEXT_CACHE_SLOTS];

static TextInfo *text_info(const char *text, int32_t bytes) {
    size_t    slot  = ((uintptr_t)text >> 4) & (TEXT_CACHE_SLOTS - 1);
    TextInfo *entry = &text_cache[slot];

    if (entry->text == text && entry->bytes == bytes) return entry;

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

static bool defines_operator(Value a, const char *op) {
    return has_method(a, op, 1);
}

static Value apply_operator(Value a, const char *op, Value b) {
    Value args[1];
    args[0] = b;

    return alg_invoke(a, op, args, 1);
}

Value alg_add(Value a, Value b) {
    if (defines_operator(a, "+")) return apply_operator(a, "+", b);

    if ((a.type == VAL_CHAR && is_number(b)) || (is_number(a) && b.type == VAL_CHAR))
        alg_error("A Char and a number cannot be added; use Succ or Str.");

    if (is_text(a) || is_text(b)) return concat(a, b);

    if (is_number(a) && is_number(b)) {
        if (is_double_arithmetic(a, b)) return alg_double(as_double(a) + as_double(b));

        if (is_bigint(a) || is_bigint(b))
            return big_value(big_add_signed(as_big(a), as_big(b)));

        int64_t result;
        if (__builtin_add_overflow(a.integer, b.integer, &result))
            return big_value(big_add_signed(as_big(a), as_big(b)));

        return alg_int(result);
    }
    alg_error("Operands must be two numbers, or two strings.");
    return alg_nil();
}

Value alg_subtract(Value a, Value b) {
    if (defines_operator(a, "-")) return apply_operator(a, "-", b);

    if (a.type == VAL_CHAR && b.type == VAL_CHAR)
        return alg_int(utf8_decode(a.string) - utf8_decode(b.string));

    if ((a.type == VAL_CHAR && is_number(b)) || (is_number(a) && b.type == VAL_CHAR))
        alg_error("A Char and a number cannot be subtracted; use Pred.");

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
    if (defines_operator(a, "*")) return apply_operator(a, "*", b);

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
    if (defines_operator(a, "/")) return apply_operator(a, "/", b);

    if (!is_number(a) || !is_number(b)) alg_error("Operands must be numbers.");
    if (is_double_arithmetic(a, b)) return alg_double(as_double(a) / as_double(b));

    if (is_bigint(a) || is_bigint(b)) {
        ObjBigInt *x = as_big(a);
        ObjBigInt *y = as_big(b);

        if (y->count == 0) alg_error("Division by zero.");

        ObjBigInt *quotient;
        ObjBigInt *remainder;
        mag_divmod(x, y, &quotient, &remainder);

        quotient->negative = x->negative != y->negative;
        return big_value(quotient);
    }

    if (b.integer == 0) alg_error("Division by zero.");

    if (a.integer == INT64_MIN && b.integer == -1)
        return big_value(big_negate_of(as_big(a)));

    return alg_int(a.integer / b.integer);
}

Value alg_div_int(Value a, Value b) {
    if (defines_operator(a, "div")) return apply_operator(a, "div", b);

    if (!is_integer(a) || !is_integer(b)) alg_error("div expects Integers.");

    return alg_divide(a, b);
}

Value alg_negate(Value a) {

    if (has_method(a, "-", 0)) return alg_invoke(a, "-", NULL, 0);

    if (is_bigint(a)) return big_value(big_negate_of(as_big(a)));

    if (a.type == VAL_INT) {

        int64_t result;
        if (__builtin_sub_overflow(0, a.integer, &result))
            return big_value(big_negate_of(as_big(a)));

        return alg_int(result);
    }
    if (a.type == VAL_DOUBLE) return alg_double(-a.number);

    alg_error("Operand must be a number.");
    return alg_nil();
}

static bool compares_as_char(Value a) {
    return a.type == VAL_CHAR;
}

static int char_order(Value a, Value b) {
    if (b.type != VAL_CHAR) alg_error("Operands must be numbers.");

    int32_t left  = utf8_decode(a.string);
    int32_t right = utf8_decode(b.string);

    return left < right ? -1 : (left > right ? 1 : 0);
}

static bool compares_as_text(Value a, Value b) {
    return is_text(a) && is_text(b) && !(a.type == VAL_CHAR && b.type == VAL_CHAR);
}

static int method_order(Value a, Value b) {
    Value args[1];
    args[0] = b;

    Value answer = alg_invoke(a, "Compare", args, 1);

    if (!is_number(answer)) alg_error("Compare must answer an Integer.");

    if (alg_truthy(alg_less(answer, alg_int(0))))    return -1;
    if (alg_truthy(alg_greater(answer, alg_int(0)))) return  1;

    return 0;
}

static int text_order(Value a, Value b) {
    const char *left  = a.string;
    const char *right = b.string;

    int32_t la = utf8_count(a.string, a.length);
    int32_t lb = utf8_count(b.string, b.length);
    int32_t n  = la < lb ? la : lb;

    for (int32_t i = 0; i < n; i++) {
        int32_t x = utf8_decode(left);
        int32_t y = utf8_decode(right);

        if (x != y) return x < y ? -1 : 1;

        left  += utf8_span((unsigned char)*left);
        right += utf8_span((unsigned char)*right);
    }

    return la < lb ? -1 : (la > lb ? 1 : 0);
}

Value alg_greater(Value a, Value b) {
    if (compares_as_char(a) && b.type == VAL_CHAR)
        return alg_bool(char_order(a, b) > 0);

    if (compares_as_text(a, b)) return alg_bool(text_order(a, b) > 0);

    if (has_method(a, "Compare", 1)) return alg_bool(method_order(a, b) > 0);

    if (compares_as_char(a)) return alg_bool(char_order(a, b) > 0);

    if (!is_number(a) || !is_number(b)) alg_error("Operands must be numbers.");
    if (is_double_arithmetic(a, b)) return alg_bool(as_double(a) > as_double(b));
    if (is_bigint(a) || is_bigint(b)) return alg_bool(big_compare(a, b) > 0);
    return alg_bool(a.integer > b.integer);
}

Value alg_greater_equal(Value a, Value b) {
    if (compares_as_char(a) && b.type == VAL_CHAR)
        return alg_bool(char_order(a, b) >= 0);

    if (compares_as_text(a, b)) return alg_bool(text_order(a, b) >= 0);

    if (has_method(a, "Compare", 1)) return alg_bool(method_order(a, b) >= 0);

    if (compares_as_char(a)) return alg_bool(char_order(a, b) >= 0);

    if (!is_number(a) || !is_number(b)) alg_error("Operands must be numbers.");
    if (is_double_arithmetic(a, b)) return alg_bool(as_double(a) >= as_double(b));
    if (is_bigint(a) || is_bigint(b)) return alg_bool(big_compare(a, b) >= 0);
    return alg_bool(a.integer >= b.integer);
}

Value alg_less(Value a, Value b) {
    if (compares_as_char(a) && b.type == VAL_CHAR)
        return alg_bool(char_order(a, b) < 0);

    if (compares_as_text(a, b)) return alg_bool(text_order(a, b) < 0);

    if (has_method(a, "Compare", 1)) return alg_bool(method_order(a, b) < 0);

    if (compares_as_char(a)) return alg_bool(char_order(a, b) < 0);

    if (!is_number(a) || !is_number(b)) alg_error("Operands must be numbers.");
    if (is_double_arithmetic(a, b)) return alg_bool(as_double(a) < as_double(b));
    if (is_bigint(a) || is_bigint(b)) return alg_bool(big_compare(a, b) < 0);
    return alg_bool(a.integer < b.integer);
}

Value alg_less_equal(Value a, Value b) {
    if (compares_as_char(a) && b.type == VAL_CHAR)
        return alg_bool(char_order(a, b) <= 0);

    if (compares_as_text(a, b)) return alg_bool(text_order(a, b) <= 0);

    if (has_method(a, "Compare", 1)) return alg_bool(method_order(a, b) <= 0);

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
        case VAL_POINTER: return a.pointer == b.pointer;
        case VAL_STRING:
        case VAL_CHAR:   return a.length == b.length
                             && memcmp(a.string, b.string, (size_t)a.length) == 0;

        case VAL_OBJ:    return a.obj == b.obj;
        default:         return false;
    }
}

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
        case VAL_POINTER: return a.pointer == b.pointer;
        case VAL_INT:
        case VAL_DOUBLE: return false;
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

    if (v.type == VAL_NIL)  return false;
    if (v.type == VAL_BOOL) return v.boolean;
    if (v.type == VAL_INT)  return v.integer != 0;

    if (is_obj(v, OBJ_ENUM)) return ((ObjEnum *)v.obj)->ordinal != 0;

    return true;
}

#define POSITIONAL_MIN (-3)
#define POSITIONAL_MAX 7

static const char *render_double(const char *scientific) {
    bool negative = (*scientific == '-');
    if (negative) scientific++;

    const char *marker = strchr(scientific, 'e');
    if (marker == NULL) alg_error("Malformed double.");

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

            out[i++] = '0';
            out[i++] = '.';
            for (int zero = 0; zero < -exponent - 1; zero++) out[i++] = '0';

            memcpy(out + i, digits, count);
            i += count;
        }
        else {
            size_t whole = (size_t)exponent + 1;

            if (count <= whole) {

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

    char scientific[40];
    snprintf(scientific, sizeof scientific, "%.0e", value);

    for (int precision = 1; precision <= 17; precision++) {
        if (strtod(scientific, NULL) == value) break;
        snprintf(scientific, sizeof scientific, "%.*e", precision, value);
    }
    return render_double(scientific);
}

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

        case VAL_POINTER: return v.pointer == NULL ? "<pointer nil>" : "<pointer>";

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

            if (v.obj->type == OBJ_BIGINT)    return big_to_text((ObjBigInt *)v.obj);

            if (v.obj->type == OBJ_ENUM)      return ((ObjEnum *)v.obj)->name;
            if (v.obj->type == OBJ_ENUM_TYPE) return ((ObjEnumType *)v.obj)->name;

            if (v.obj->type == OBJ_BOUND) {
                Builder b = { NULL, 0, 0 };
                builder_append(&b, "<fn ");
                builder_append(&b, ((ObjBound *)v.obj)->method->name);
                builder_append(&b, ">");
                return b.text;
            }

            if (v.obj->type == OBJ_BUILTIN_BOUND) {
                Builder b = { NULL, 0, 0 };
                builder_append(&b, "<fn ");
                builder_append(&b, ((ObjBuiltinBound *)v.obj)->name);
                builder_append(&b, ">");
                return b.text;
            }

            if (v.obj->type == OBJ_INSTANCE) {
                ObjClass *klass = ((ObjInstance *)v.obj)->klass;

                if (has_method(v, "ToString", 0)) {
                    return as_text(alg_invoke(v, "ToString", NULL, 0));
                }

                if (klass->is_object) return klass->name;

                Builder b = { NULL, 0, 0 };
                builder_append(&b, klass->name);
                builder_append(&b, " instance");
                return b.text;
            }
            if (v.obj->type == OBJ_CLASS) return ((ObjClass *)v.obj)->name;

            if (v.obj->type == OBJ_BUFFER) {
                ObjBuffer *buffer = (ObjBuffer *)v.obj;
                if (buffer->freed) return "Buffer(freed)";

                char *text = arena_alloc(32);
                snprintf(text, 32, "Buffer(%d)", (int32_t)buffer->length);
                return text;
            }

            if (v.obj->type == OBJ_FILE) {
                ObjFile *file = (ObjFile *)v.obj;
                Builder  b    = { NULL, 0, 0 };

                builder_append(&b, "TextFile(");
                if (file->name[0] != '\0') {
                    builder_append(&b, "'");
                    builder_append(&b, file->name);
                    builder_append(&b, "'");
                }
                builder_append(&b, ")");
                return b.text;
            }
            return collection_text(v);

        case VAL_INT: {

            char *buffer = arena_alloc(24);
            snprintf(buffer, 24, "%lld", (long long)v.integer);
            return buffer;
        }

        case VAL_DOUBLE:
            return alg_double_text(v.number);
    }
    return "";
}

static int32_t tests_passed = 0;
static int32_t tests_failed = 0;

static bool in_tests = false;

#define ANSI_RESET "\033[0m"
#define ANSI_RED   "\033[31m"
#define ANSI_GREEN "\033[32m"
#define ANSI_BLUE  "\033[34m"
#define ANSI_CYAN  "\033[36m"
#define ANSI_WHITE "\033[37m"

#define INFO_TAG ANSI_WHITE "[" ANSI_BLUE "INFO" ANSI_WHITE "] " ANSI_RESET

#define ERROR_TAG ANSI_WHITE "[" ANSI_RED "ERROR" ANSI_WHITE "] " ANSI_RESET

static const char *test_root = "";

void alg_test_begin(int32_t count, const char *file) {
    test_root = file;

    in_tests = true;

    printf(INFO_TAG "Running %d tests...\n", count);
}

void alg_test_file(const char *file) {
    printf(INFO_TAG "< " ANSI_CYAN "%s" ANSI_RESET " >\n", file);
}

void alg_test_end_file(void) {
    printf(INFO_TAG "\n");
}

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

    int leader = 55 - (int)strlen(name);
    if (leader < 1) leader = 1;

    printf(INFO_TAG "Test: %s ", name);
    for (int i = 0; i < leader; i++) putchar('.');
    printf(" [ %s%s" ANSI_RESET " ]\n", ok ? ANSI_GREEN : ANSI_RED,
                                        ok ? "PASS" : "FAIL");

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

    char message[512];
    snprintf(message, sizeof message,
             "Assertion failed.  Expected true but got '%s'.", as_text(alg_str(value)));

    alg_error(message);
}

void alg_assert_equal(Value expected, Value actual) {
    if (equals(expected, actual)) return;

    const char *left  = as_text(alg_str(expected));
    const char *right = as_text(alg_str(actual));

    char message[512];

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

static const char *as_string(Value v, const char *what) {
    if (!is_text(v)) alg_error(what);

    return as_text(v);
}

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
    /* Rendered first, as the interpreter's arm does with Str: Copy measures
       TEXT, and text is what any value has [RT-003]. Without this,
       'Copy (42, 0, 1)' answered 4 interpreted and refused compiled, and the
       byte length read here belonged to whatever the value really was. */
    text = alg_str(text);

    const char *from  = as_string(text, "Copy expects a String.");
    int32_t     start = as_integer(begin, "Copy expects an Integer start.");
    int32_t     count = as_integer(length, "Copy expects an Integer length.");

    int32_t size = utf8_count(from, text.length);

    if (start < 0 || start > size) {
        char message[80];
        snprintf(message, sizeof message, "Copy failed: Start %d out of range 0..%d.", start, size);
        alg_error(message);
    }
    if (count < 0) alg_error("Copy failed: Length cannot be negative.");

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

/* ToUpper and ToLower fold the ASCII letters and nothing else [RT-025]. That
   is not a shortcut taken here: every case comparison in the language stops at
   A-Z already -- alg_stricmp, hash_folded, and the Annex G.3 mangling that
   lowercases an identifier before escaping it.
   Folding byte by byte is safe for UTF-8 because every byte of a multi-byte
   sequence is >= 0x80 and no fold reaches that far, so a sequence is copied
   through untouched rather than corrupted a byte at a time. */
static bool folds(unsigned char c, bool upper) {
    return upper ? (c >= 'a' && c <= 'z') : (c >= 'A' && c <= 'Z');
}

static Value folded(Value text, const char *what, bool upper) {
    const char *from = as_string(text, what);

    int32_t first = 0;
    while (first < text.length && !folds((unsigned char)from[first], upper)) first++;

    /* Text with nothing to fold is answered as ITSELF, not as a copy of
       itself. FoldCase in compiler/Token.a24 runs this on every identifier
       that becomes a key, and the arena never frees -- so a copy per lookup
       is a cost that accumulates for the whole run rather than one that is
       paid and reclaimed. */
    if (first == text.length) return text;

    char *result = arena_alloc((size_t)text.length + 1);

    memcpy(result, from, (size_t)first);

    for (int32_t i = first; i < text.length; i++) {
        unsigned char c = (unsigned char)from[i];

        if (folds(c, upper)) c = upper ? (unsigned char)(c - 32) : (unsigned char)(c + 32);

        result[i] = (char)c;
    }
    result[text.length] = '\0';

    /* A Char folds to a Char. Case is not a reason to widen, and Str is how
       widening is asked for [TYP-003]. */
    Value v = alg_string_n(result, text.length);
    v.type  = text.type;
    return v;
}

Value alg_to_upper(Value text) { return folded(text, "ToUpper expects text.", true); }
Value alg_to_lower(Value text) { return folded(text, "ToLower expects text.", false); }

/* Both spellings of Pos share this, so the two-argument form cannot drift from
   the three-argument one: searching from zero IS the ordinary search. */
static Value position_from(Value text, Value part, int32_t at) {
    text = alg_str(text);
    part = alg_str(part);

    const char *haystack = as_string(text, "Pos expects a String.");
    const char *needle   = as_string(part, "Pos expects a String.");

    int32_t size = utf8_count(haystack, text.length);

    /* Checked the way Copy checks its start, rather than clamped, because a
       start outside the text is a mistake in the caller's arithmetic and
       answering -1 would hide it among the ordinary not-found answers. */
    if (at < 0 || at > size) {
        char message[80];
        snprintf(message, sizeof message, "Pos failed: Start %d out of range 0..%d.", at, size);
        alg_error(message);
    }

    const char *found = strstr(haystack + utf8_offset(haystack, text.length, at), needle);

    if (found == NULL) return alg_int(-1);

    /* Counted from the START of the haystack, not from 'at'. The answer is an
       index into the text, so it can be handed straight back as the next
       search's start. */
    return alg_int(utf8_chars_in(haystack, (int32_t)(found - haystack)));
}

Value alg_pos(Value text, Value part) {
    return position_from(text, part, 0);
}

Value alg_pos_from(Value text, Value part, Value start) {
    return position_from(text, part, as_integer(start, "Pos expects an Integer start."));
}

Value alg_char(Value code) {
    int32_t point = as_integer(code, "Char expects an Integer.");

    if (point < 0 || point > 0x10FFFF || (point >= 0xD800 && point <= 0xDFFF)) {
        alg_error("Char is limited to 0..10FFFF, excluding D800..DFFF.");
    }

    return alg_char_value(point);
}

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

    const char *digits = text;
    int32_t     sign   = 1;

    if (*digits == '-') {
        sign = -1;
        digits++;
    }

    if (*digits == '\0') return as_double;

    Value result = alg_int(0);
    for (const char *at = digits; *at != '\0'; at++) {
        if (*at < '0' || *at > '9') return as_double;

        result = alg_add(alg_multiply(result, alg_int(10)), alg_int(*at - '0'));
    }
    return alg_multiply(alg_int(sign), result);
}

Value alg_ord(Value v) {

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

static Value stepped(Value v, int32_t by, const char *name) {
    if (v.type == VAL_INT || is_bigint(v)) return alg_add(v, alg_int(by));

    if (v.type == VAL_CHAR) {
        int32_t code = utf8_decode(v.string) + by;

        if (code < 0 || code > 0x10FFFF) {
            Builder b = { NULL, 0, 0 };
            builder_append(&b, name);
            builder_append(&b, " failed: '");
            builder_append(&b, as_text(v));
            builder_append(&b, "' has no ordinal beyond it.");

            alg_error(b.text);
        }
        return alg_char_value(code);
    }

    Builder b = { NULL, 0, 0 };
    builder_append(&b, name);
    builder_append(&b, " failed: '");
    builder_append(&b, as_text(v));
    builder_append(&b, "' has no ordinal.");

    alg_error(b.text);
    return alg_nil();
}

Value alg_succ(Value v) { return stepped(v,  1, "Succ"); }
Value alg_pred(Value v) { return stepped(v, -1, "Pred"); }

#ifdef ALG_FFI

#ifdef __APPLE__
#include <ffi/ffi.h>
#else
#include <ffi.h>
#endif

#include <dlfcn.h>

static ffi_type *foreign_type(const char *declared) {
    char base[64];

    split_type(declared, base, sizeof base);

    if (alg_stricmp(base, "Double") == 0)  return &ffi_type_double;
    if (alg_stricmp(base, "String") == 0)  return &ffi_type_pointer;
    if (alg_stricmp(base, "Pointer") == 0) return &ffi_type_pointer;
    if (alg_stricmp(base, "") == 0)        return &ffi_type_void;

    return &ffi_type_sint64;
}

#define FOREIGN_CACHE_SLOTS 256

typedef struct {
    const char *symbol;
    const char *library;
    void       *fn;
} ForeignEntry;

static ForeignEntry foreign_cache[FOREIGN_CACHE_SLOTS];
static int32_t      foreign_cached = 0;

static uint32_t foreign_hash(const char *symbol, const char *library) {

    uint32_t hash = hash_bytes(2166136261u, symbol, strlen(symbol));

    return hash_bytes(hash, library, strlen(library));
}

static const char *foreign_key(const char *text) {
    size_t size = strlen(text) + 1;
    char  *copy = arena_alloc(size);

    memcpy(copy, text, size);
    return copy;
}

static void *foreign_resolve(const char *symbol, const char *library) {
    if (library == NULL || library[0] == '\0') {
        void *found = dlsym(RTLD_DEFAULT, symbol);

        if (found == NULL) {
            Builder b = { NULL, 0, 0 };
            builder_append(&b, "No foreign symbol '");
            builder_append(&b, symbol);
            builder_append(&b, "'.");
            alg_error(b.text);
        }
        return found;
    }

    void *handle = dlopen(library, RTLD_LAZY);

    if (handle == NULL) {
        Builder b = { NULL, 0, 0 };
        builder_append(&b, "Cannot open foreign library '");
        builder_append(&b, library);
        builder_append(&b, "'.");
        alg_error(b.text);
    }

    void *found = dlsym(handle, symbol);

    if (found == NULL) {
        Builder b = { NULL, 0, 0 };
        builder_append(&b, "No foreign symbol '");
        builder_append(&b, symbol);
        builder_append(&b, "' in '");
        builder_append(&b, library);
        builder_append(&b, "'.");
        alg_error(b.text);
    }
    return found;
}

static void *foreign_symbol(const char *symbol, const char *library) {
    if (library == NULL) library = "";

    uint32_t slot = foreign_hash(symbol, library) % FOREIGN_CACHE_SLOTS;

    for (int32_t probe = 0; probe < FOREIGN_CACHE_SLOTS; probe++) {
        ForeignEntry *entry = &foreign_cache[(slot + probe) % FOREIGN_CACHE_SLOTS];

        if (entry->fn == NULL) break;
        if (strcmp(entry->symbol, symbol) == 0 && strcmp(entry->library, library) == 0)
            return entry->fn;
    }

    void *found = foreign_resolve(symbol, library);

    if (foreign_cached < FOREIGN_CACHE_SLOTS) {
        for (int32_t probe = 0; probe < FOREIGN_CACHE_SLOTS; probe++) {
            ForeignEntry *entry = &foreign_cache[(slot + probe) % FOREIGN_CACHE_SLOTS];

            if (entry->fn == NULL) {
                entry->symbol  = foreign_key(symbol);
                entry->library = foreign_key(library);
                entry->fn      = found;
                foreign_cached++;
                break;
            }
        }
    }
    return found;
}

Value alg_foreign(const char *symbol, const char *library, const char **types,
                  int32_t count, const char *returns, Value *args) {
    if (count > 8) alg_error("A foreign call takes at most eight arguments.");

    void *fn = foreign_symbol(symbol, library);

    ffi_type *arg_types[8];
    ffi_type *ret_type = foreign_type(returns);

    int64_t words[8];
    double  reals[8];
    const char *texts[8];
    void   *values[8];

    for (int32_t i = 0; i < count; i++) {
        const char *declared = (types != NULL) ? types[i] : "";

        arg_types[i] = foreign_type(declared);

        if (arg_types[i] == &ffi_type_double) {
            reals[i]  = as_double(args[i]);
            values[i] = &reals[i];
        }
        else if (is_text(args[i])) {
            texts[i]  = as_text(args[i]);
            values[i] = &texts[i];
        }
        else if (args[i].type == VAL_POINTER) {
            values[i] = &args[i].pointer;
        }
        else if (args[i].type == VAL_NIL) {
            words[i]  = 0;
            values[i] = &words[i];
        }
        else {

            if (args[i].type == VAL_INT)       words[i] = args[i].integer;
            else if (args[i].type == VAL_BOOL) words[i] = args[i].boolean ? 1 : 0;
            else if (is_number(args[i]))       words[i] = (int64_t)as_double(args[i]);
            else                               words[i] = 0;

            values[i] = &words[i];
        }
    }

    ffi_cif cif;
    if (ffi_prep_cif(&cif, FFI_DEFAULT_ABI, (unsigned)count, ret_type, arg_types) != FFI_OK)
        alg_error("A foreign call could not be prepared.");

    if (ret_type == &ffi_type_double) {
        double answer = 0;
        ffi_call(&cif, FFI_FN(fn), &answer, values);

        return alg_double(answer);
    }

    if (ret_type == &ffi_type_void) {
        ffi_arg ignored;
        ffi_call(&cif, FFI_FN(fn), &ignored, values);

        return alg_nil();
    }

    ffi_arg answer = 0;
    ffi_call(&cif, FFI_FN(fn), &answer, values);

    {
        char base[64];
        split_type(returns, base, sizeof base);

        if (alg_stricmp(base, "Pointer") == 0) return alg_pointer((void *)(intptr_t)answer);
        if (alg_stricmp(base, "Boolean") == 0) return alg_bool((int64_t)answer != 0);
        if (alg_stricmp(base, "String")  == 0) {
            const char *text = (const char *)(intptr_t)answer;

            return text == NULL ? alg_nil() : alg_string(text);
        }
    }

    return alg_int((int64_t)answer);
}

#else

Value alg_foreign(const char *symbol, const char *library, const char **types,
                  int32_t count, const char *returns, Value *args) {
    (void)library; (void)types; (void)count; (void)returns; (void)args;

    Builder b = { NULL, 0, 0 };
    builder_append(&b, "Foreign calls are not available in this build: '");
    builder_append(&b, symbol);
    builder_append(&b, "' cannot be reached.");

    alg_error(b.text);
    return alg_nil();
}

#endif

Value alg_foreign_call(Value symbol, Value library, Value types, Value returns, Value args) {
    const char *type_names[8];
    Value       values[8];

    ObjSeq *type_seq = (ObjSeq *)types.obj;
    ObjSeq *arg_seq  = (ObjSeq *)args.obj;

    int32_t count = arg_seq->count;
    if (count > 8) alg_error("A foreign call takes at most eight arguments.");

    for (int32_t i = 0; i < count; i++) {
        type_names[i] = i < type_seq->count ? as_text(type_seq->items[i]) : "";
        values[i]     = arg_seq->items[i];
    }

    return alg_foreign(as_text(symbol), as_text(library), type_names, count,
                       as_text(returns), values);
}

Value alg_clock(void) {
    struct timeval now;
    gettimeofday(&now, NULL);

    long long millis = (long long)now.tv_sec * 1000 + now.tv_usec / 1000;

    return alg_double((double)millis / 1000.0);
}

Value alg_max(Value a, Value b) {
    bool numbers = (a.type == VAL_INT || a.type == VAL_DOUBLE)
                && (b.type == VAL_INT || b.type == VAL_DOUBLE);

    if (!numbers) alg_error("Max expects numbers.");

    return alg_truthy(alg_greater(a, b)) ? a : b;
}

Value alg_mod(Value a, Value b) {

    if (!is_integer(a)) alg_error("Mod expects Integers.");
    if (!is_integer(b)) alg_error("Mod expects Integers.");

    if (is_bigint(a) || is_bigint(b)) {
        ObjBigInt *x = as_big(a);
        ObjBigInt *y = as_big(b);

        if (y->count == 0) alg_error("Mod failed: Division by zero.");

        ObjBigInt *quotient;
        ObjBigInt *remainder;
        mag_divmod(x, y, &quotient, &remainder);

        remainder->negative = x->negative;
        return big_value(remainder);
    }

    int64_t left  = a.integer;
    int64_t right = b.integer;

    if (right == 0) alg_error("Mod failed: Division by zero.");

    if (left == INT64_MIN && right == -1) return alg_int(0);

    return alg_int(left % right);
}

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

void alg_writeln_blank(void) {
    alg_writeln(alg_string(""));
}

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
