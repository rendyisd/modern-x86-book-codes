// ========================================================
// Mixed-Type Integer Arithmetic
// ========================================================
#include <stdio.h>
#include <inttypes.h>

#include "c3_2.h"

void display_results_int(int8_t a, int16_t b, int32_t c, int64_t d,
                         int8_t e, int16_t f, int32_t g, int64_t h,
                         int64_t prod1, int64_t prod2)
{
    printf("\ncalc_result_i64 results\n");
    printf("a = %"PRIi8", b = %"PRIi16", c = %d, d = %"PRIi64", ", a, b, c, d);
    printf("e = %"PRIi8", f = %"PRIi16", g = %d, h = %"PRIi64"\n", e, f, g, h);
    printf("prod1 = %"PRIi64"\n", prod1);
    printf("prod2 = %"PRIi64"\n", prod2);
}

void display_results_uint(uint8_t a, uint16_t b, uint32_t c, uint64_t d,
                          uint8_t e, uint16_t f, uint32_t g, uint64_t h,
                          uint64_t quo1, uint64_t rem1,
                          uint64_t quo2, uint64_t rem2)
{
    printf("\ncalc_result_u64 results\n");
    printf("a = %"PRIu8", b = %"PRIu16", c = %d, d = %"PRIu64", ", a, b, c, d);
    printf("e = %"PRIu8", f = %"PRIu16", g = %d, h = %"PRIu64"\n", e, f, g, h);
    printf("quo1 = %"PRIu64", rem1 = %"PRIu64"\n", quo1, rem1);
    printf("quo2 = %"PRIu64", rem2 = %"PRIu64"\n", quo2, rem2);
}

static void calc_result_i64(void)
{
    int8_t a = 2, e = 3;
    int16_t b = -3, f = -7;;
    int32_t c = 8, g = -5;
    int64_t d = 4, h = 10;

    // Calculate (a * b * c * d) + (e * f * g * h)
    int64_t prod1 = ((int64_t)a * b * c * d) + ((int64_t)e * f * g * h);
    int64_t prod2 = calc_result_i64_a(a, b, c, d, e, f, g, h);

    display_results_int(a, b, c, d, e, f, g, h, prod1, prod2);
}

static void calc_result_u64(void)
{
    uint8_t a = 12, e = 101;
    uint16_t b = 17, f = 37;
    uint32_t c = 71000000, g =25;
    uint64_t d = 90000000000, h = 5;

    uint64_t quo1, rem1;
    uint64_t quo2, rem2;

    // Calculate quotient and remainder for (a + b + c + d) / (e + f + g + h)
    quo1 = ((uint64_t)a + b + c + d) / ((uint64_t)e + f + g + h);
    rem1 = ((uint64_t)a + b + c + d) % ((uint64_t)e + f + g + h);

    calc_result_u64_a(a, b, c, d, e, f, g, h, &quo2, &rem2);
    display_results_uint(a, b, c, d, e, f, g, h, quo1, rem1, quo2, rem2);
}

int main(void)
{
    printf("----- Results for c3_1 -----\n");

    calc_result_i64();
    calc_result_u64();

    return 0;
}
