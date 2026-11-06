/* Generated from Algol-24.  Do not edit. */
#ifndef ALG_PARSER_H
#define ALG_PARSER_H

#include "algol.h"

Value f_readwholefile(Value **cells, Value *args, int32_t count);
Value f_setmodulefolder(Value **cells, Value *args, int32_t count);
Value f_folderof(Value **cells, Value *args, int32_t count);
Value f_libraryfolder(Value **cells, Value *args, int32_t count);
extern Value fn_readwholefile;
extern Value v_moduleVfolder;
extern bool d_moduleVfolder;
extern Value fn_setmodulefolder;
extern Value fn_folderof;
extern Value fn_libraryfolder;
extern Value k_parser;
void init_Parser(void);

#endif
