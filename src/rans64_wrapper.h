#ifndef RYG_RANS_SYS_RANS64_WRAPPER_H
#define RYG_RANS_SYS_RANS64_WRAPPER_H

#include "platform.h"
#include "rans64.h"

void rans_64_enc_init(Rans64State* r);
void rans_64_enc_put(Rans64State* r, uint32_t** pptr, uint32_t start, uint32_t freq, uint32_t scale_bits);
void rans_64_enc_flush(Rans64State* r, uint32_t** pptr);
void rans_64_dec_init(Rans64State* r, uint32_t** pptr);
uint32_t rans_64_dec_get(Rans64State* r, uint32_t scale_bits);
void rans_64_dec_advance(Rans64State* r, uint32_t** pptr, uint32_t start, uint32_t freq, uint32_t scale_bits);
void rans_64_enc_symbol_init(Rans64EncSymbol* s, uint32_t start, uint32_t freq, uint32_t scale_bits);
void rans_64_dec_symbol_init(Rans64DecSymbol* s, uint32_t start, uint32_t freq);
void rans_64_enc_put_symbol(Rans64State* r, uint32_t** pptr, Rans64EncSymbol const* sym, uint32_t scale_bits);
void rans_64_dec_advance_symbol(Rans64State* r, uint32_t** pptr, Rans64DecSymbol const* sym, uint32_t scale_bits);
void rans_64_dec_advance_step(Rans64State* r, uint32_t start, uint32_t freq, uint32_t scale_bits);
void rans_64_dec_advance_symbol_step(Rans64State* r, Rans64DecSymbol const* sym, uint32_t scale_bits);
void rans_64_dec_renorm(Rans64State* r, uint32_t** pptr);

#endif // RYG_RANS_SYS_RANS64_WRAPPER_H
