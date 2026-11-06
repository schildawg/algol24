/* Generated from Algol-24.  Do not edit. */
#ifndef ALG_PARSER_H
#define ALG_PARSER_H

#include "algol.h"

Value f_readwholefile(Value **cells, Value *args, int32_t count);
Value f_setmodulefolders(Value **cells, Value *args, int32_t count);
Value f_folderof(Value **cells, Value *args, int32_t count);
Value f_libraryfolders(Value **cells, Value *args, int32_t count);
extern Value fn_readwholefile;
extern Value v_moduleVfolders;
extern bool d_moduleVfolders;
extern Value fn_setmodulefolders;
extern Value fn_folderof;
extern Value fn_libraryfolders;
extern Value k_parser;
void init_Parser(void);

#endif
