#include "rans_64_wrapper.h"

void rans_64_enc_init(Rans64State* r) {
    Rans64EncInit(r);
}

void rans_64_enc_put(Rans64State* r, uint32_t** pptr, uint32_t start, uint32_t freq, uint32_t scale_bits) {
    Rans64EncPut(r, pptr, start, freq, scale_bits);
}

void rans_64_enc_flush(Rans64State* r, uint32_t** pptr) {
    Rans64EncFlush(r, pptr);
}

void rans_64_dec_init(Rans64State* r, uint32_t** pptr) {
    Rans64DecInit(r, pptr);
}

uint32_t rans_64_dec_get(Rans64State* r, uint32_t scale_bits) {
    Rans64DecGet(r, scale_bits);
}

void rans_64_dec_advance(Rans64State* r, uint32_t** pptr, uint32_t start, uint32_t freq, uint32_t scale_bits) {
    Rans64DecAdvance(r, pptr, start, freq, scale_bits);
}

void rans_64_enc_symbol_init(Rans64EncSymbol* s, uint32_t start, uint32_t freq, uint32_t scale_bits) {
    Rans64EncSymbolInit(s, start, freq, scale_bits);
}

void rans_64_dec_symbol_init(Rans64DecSymbol* s, uint32_t start, uint32_t freq) {
    Rans64DecSymbolInit(s, start, freq);
}

void rans_64_enc_put_symbol(Rans64State* r, uint32_t** pptr, Rans64EncSymbol const* sym, uint32_t scale_bits) {
    Rans64EncPutSymbol(r, pptr, sym, scale_bits);
}

void rans_64_dec_advance_symbol(Rans64State* r, uint32_t** pptr, Rans64DecSymbol const* sym, uint32_t scale_bits) {
    Rans64DecAdvanceSymbol(r, pptr, sym, scale_bits);
}

void rans_64_dec_advance_step(Rans64State* r, uint32_t start, uint32_t freq, uint32_t scale_bits) {
    Rans64DecAdvanceStep(r, start, freq, scale_bits);
}

void rans_64_dec_advance_symbol_step(Rans64State* r, Rans64DecSymbol const* sym, uint32_t scale_bits) {
    Rans64DecAdvanceSymbolStep(r, sym, scale_bits);
}

void rans_64_dec_renorm(Rans64State* r, uint32_t** pptr) {
    Rans64DecRenorm(r, pptr);
}
