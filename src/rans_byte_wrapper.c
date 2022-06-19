#include "rans_byte_wrapper.h"

void rans_enc_init(RansState* r) {
    RansEncInit(r);
}

RansState rans_enc_renorm(RansState x, uint8_t** pptr, uint32_t freq, uint32_t scale_bits) {
    return RansEncRenorm(x, pptr, freq, scale_bits);
}

void rans_enc_put(RansState* r, uint8_t** pptr, uint32_t start, uint32_t freq, uint32_t scale_bits) {
    RansEncPut(r, pptr, start, freq, scale_bits);
}

void rans_enc_flush(RansState* r, uint8_t** pptr) {
    RansEncFlush(r, pptr);
}

void rans_dec_init(RansState* r, uint8_t** pptr) {
    RansDecInit(r, pptr);
}

uint32_t rans_dec_get(RansState* r, uint32_t scale_bits) {
    return RansDecGet(r, scale_bits);
}

void rans_dec_advance(RansState* r, uint8_t** pptr, uint32_t start, uint32_t freq, uint32_t scale_bits) {
    RansDecAdvance(r, pptr, start, freq, scale_bits);
}

void rans_enc_symbol_init(RansEncSymbol* s, uint32_t start, uint32_t freq, uint32_t scale_bits) {
    RansEncSymbolInit(s, start, freq, scale_bits);
}

void rans_dec_symbol_init(RansDecSymbol* s, uint32_t start, uint32_t freq) {
    RansDecSymbolInit(s, start, freq);
}

void rans_enc_put_symbol(RansState* r, uint8_t** pptr, RansEncSymbol const* sym) {
    RansEncPutSymbol(r, pptr, sym);
}

void rans_dec_advance_symbol(RansState* r, uint8_t** pptr, RansDecSymbol const* sym, uint32_t scale_bits) {
    RansDecAdvanceSymbol(r, pptr, sym, scale_bits);
}

void rans_dec_advance_step(RansState* r, uint32_t start, uint32_t freq, uint32_t scale_bits) {
    RansDecAdvanceStep(r, start, freq, scale_bits);
}

void rans_dec_advance_symbol_step(RansState* r, RansDecSymbol const* sym, uint32_t scale_bits) {
    RansDecAdvanceSymbolStep(r, sym, scale_bits);
}

void rans_dec_renorm(RansState* r, uint8_t** pptr) {
    RansDecRenorm(r, pptr);
}
