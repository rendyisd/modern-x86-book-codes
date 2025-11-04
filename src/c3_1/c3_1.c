// ========================================================
// Simple Stack Arguments
// ========================================================
#include <stdio.h>
#include <inttypes.h>

#include "c3_1.h"

void display_results_i32(int32_t a, int32_t b, int32_t c, int32_t d,
                         int32_t e, int32_t f, int32_t g, int32_t h,
                         int32_t res1, int32_t res2)
{
    printf("\nStack Example #1\n");
    printf("a = %d, b = %d, c = %d ", a, b, c);
    printf("d = %d, e = %d, f = %d ", d, e, f);
    printf("g = %d, h = %d\n", g, h);
    printf("res1 = %d, res2 = %d\n", res1, res2);
}

void display_results_u64(uint64_t a, uint64_t b, uint64_t c, uint64_t d,
                         uint64_t e, uint64_t f, uint64_t g, uint64_t h,
                         uint64_t res1, uint64_t res2)
{
    printf("\nStack Example #2\n");
    printf("a = %"PRIu64", b = %"PRIu64", c = %"PRIu64" ", a, b, c);
    printf("d = %"PRIu64", e = %"PRIu64", f = %"PRIu64" ", d, e, f);
    printf("g = %"PRIu64", h = %"PRIu64"\n", g, h);
    printf("res1 = %"PRIu64", res2 = %"PRIu64"\n", res1, res2);
}

static void stack_example1(void)
{
    // Stack example #1 - 32-bit integers
    int32_t a = 2, b = -3, c = 8, d = 9;
    int32_t e = 3, f = -7, g = 5, h = -1000000;

    int32_t res1 = a + b + c + d + e + f + g + h;
    int32_t res2 = sum_vals_i32_a(a, b, c, d, e, f, g, h);

    display_results_i32(a, b, c, d, e, f, g, h, res1, res2);
}

static void stack_example2(void)
{
    // Stack example #2 - 64-bit integers
    uint64_t a = 10, b = 20, c = 30, d = 40;
    uint64_t e = 50, f = 60, g = 70, h = 80;

    uint64_t res1 = a * b * c * d * e * f * g * h;
    uint64_t res2 = mul_vals_u64_a(a, b, c, d, e, f, g, h);

    display_results_u64(a, b, c, d, e, f, g, h, res1, res2);
}

int main(void)
{
    printf("----- Results for c3_1 -----\n");

    stack_example1();
    stack_example2();
}
