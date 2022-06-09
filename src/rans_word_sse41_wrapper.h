#ifndef RYG_RANS_SYS_RANS_WORD_SSE41_WRAPPER_H
#define RYG_RANS_SYS_RANS_WORD_SSE41_WRAPPER_H

#include "platform.h"
#include "rans_word_sse41.h"

void rans_word_tables_init_symbol(RansWordTables* tab, uint8_t sym, uint32_t start, uint32_t freq);
RansWordEnc rans_word_enc_init();
void rans_word_enc_put(RansWordEnc* r, uint16_t** pptr, uint32_t start, uint32_t freq);
void rans_word_enc_flush(RansWordEnc* r, uint16_t** pptr);
void rans_word_dec_init(RansWordDec* r, uint16_t** pptr);
uint8_t rans_word_dec_sym(RansWordDec* r, RansWordTables const* tab);
void rans_word_dec_renorm(RansWordDec* r, uint16_t** pptr);
void rans_simd_dec_init(RansSimdDec* r, uint16_t** pptr);
uint32_t rans_simd_dec_sym(RansSimdDec* r, RansWordTables const* tab);
void rans_simd_dec_renorm(RansSimdDec* r, uint16_t** pptr);

#endif // RYG_RANS_SYS_RANS_WORD_SSE41_WRAPPER_H
