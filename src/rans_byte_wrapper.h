#ifndef RYG_RANS_SYS_RANS_BYTE_WRAPPER_H
#define RYG_RANS_SYS_RANS_BYTE_WRAPPER_H

#include "platform.h"
#include "rans_byte.h"

void rans_enc_init(RansState* r);
RansState rans_enc_renorm(RansState x, uint8_t** pptr, uint32_t freq, uint32_t scale_bits);
void rans_enc_put(RansState* r, uint8_t** pptr, uint32_t start, uint32_t freq, uint32_t scale_bits);
void rans_enc_flush(RansState* r, uint8_t** pptr);
void rans_dec_init(RansState* r, uint8_t** pptr);
uint32_t rans_dec_get(RansState* r, uint32_t scale_bits);
void rans_dec_advance(RansState* r, uint8_t** pptr, uint32_t start, uint32_t freq, uint32_t scale_bits);
void rans_enc_symbol_init(RansEncSymbol* s, uint32_t start, uint32_t freq, uint32_t scale_bits);
void rans_dec_symbol_init(RansDecSymbol* s, uint32_t start, uint32_t freq);
void rans_enc_put_symbol(RansState* r, uint8_t** pptr, RansEncSymbol const* sym);
void rans_dec_advance_symbol(RansState* r, uint8_t** pptr, RansDecSymbol const* sym, uint32_t scale_bits);
void rans_dec_advance_step(RansState* r, uint32_t start, uint32_t freq, uint32_t scale_bits);
void rans_dec_advance_symbol_step(RansState* r, RansDecSymbol const* sym, uint32_t scale_bits);
void rans_dec_renorm(RansState* r, uint8_t** pptr);

#endif // RYG_RANS_SYS_RANS_BYTE_WRAPPER_H
