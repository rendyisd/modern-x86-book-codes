#ifndef C3_2_H
#define C3_2_H

#include <stdint.h>

extern int64_t calc_result_i64_a(int8_t a, int16_t b, int32_t c, int64_t d,
                                 int8_t e, int16_t f, int32_t g, int64_t h);

extern void calc_result_u64_a(uint8_t a, uint16_t b, uint32_t c, uint64_t d,
                              uint8_t e, uint16_t f, uint32_t g, uint64_t h,
                              uint64_t* quo, uint64_t* rem);

#endif
