#include "rans_word_sse41_wrapper.h"

void rans_word_tables_init_symbol(RansWordTables* tab, uint8_t sym, uint32_t start, uint32_t freq) {
    RansWordTablesInitSymbol(tab, sym, start, freq);
}

RansWordEnc rans_word_enc_init() {
    RansWordEncInit();
}

void rans_word_enc_put(RansWordEnc* r, uint16_t** pptr, uint32_t start, uint32_t freq) {
    RansWordEncPut(r, pptr, start, freq);
}

void rans_word_enc_flush(RansWordEnc* r, uint16_t** pptr) {
    RansWordEncFlush(r, pptr);
}

void rans_word_dec_init(RansWordDec* r, uint16_t** pptr) {
    RansWordDecInit(r, pptr);
}

uint8_t rans_word_dec_sym(RansWordDec* r, RansWordTables const* tab) {
    RansWordDecSym(r, tab);
}

void rans_word_dec_renorm(RansWordDec* r, uint16_t** pptr) {
    RansWordDecRenorm(r, pptr);
}

void rans_simd_dec_init(RansSimdDec* r, uint16_t** pptr) {
    RansSimdDecInit(r, pptr);
}

uint32_t rans_simd_dec_sym(RansSimdDec* r, RansWordTables const* tab) {
    RansSimdDecSym(r, tab);
}

void rans_simd_dec_renorm(RansSimdDec* r, uint16_t** pptr) {
    RansSimdDecRenorm(r, pptr);
}
