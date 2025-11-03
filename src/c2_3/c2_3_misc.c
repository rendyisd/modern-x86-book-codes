// ========================================================
// Shift Operations
// ========================================================
#include <stdio.h>

#include "c2_3.h"

void print_bits32(unsigned int n) {
    for (int i = 31; i >= 0; i--)
        putchar((n & (1u << i)) ? '1' : '0');
}

void display_results(const char *s,
                     int rc,
                     unsigned int a,
                     unsigned int count,
                     unsigned int a_shl,
                     unsigned int a_shr)
{
    const int w = 10;

    printf("%s\n", s);
    printf("count: %*u\n", w, count);

    printf("a: %*u (0b", w, a);
    print_bits32(a);
    printf(")\n");

    if (rc == 1) {
        printf("shl: %*u (0b", w, a_shl);
        print_bits32(a_shl);
        printf(")\n");

        printf("shr: %*u (0b", w, a_shr);
        print_bits32(a_shr);
        printf(")\n");
    } else {
        printf("Invalid shift count\n");
    }

    printf("\n");
}

int main(void)
{
    int rc; 
    unsigned int a, count, a_shl, a_shr;

    printf("----- Result for c2_3 -----\n\n");

    a = 3119;
    count = 6;
    rc = shift_u32_a(&a_shl, &a_shr, a, count);
    display_results("Shift test #1", rc, a, count, a_shl, a_shr);

    a = 0x00800080;
    count = 4;
    rc = shift_u32_a(&a_shl, &a_shr, a, count);
    display_results("Shift test #2", rc, a, count, a_shl, a_shr);

    a = 0x80000001;
    count = 31;
    rc = shift_u32_a(&a_shl, &a_shr, a, count);
    display_results("Shift test #3", rc, a, count, a_shl, a_shr);

    a = 0x55555555;
    count = 32;
    rc = shift_u32_a(&a_shl, &a_shr, a, count);
    display_results("Shift test #4", rc, a, count, a_shl, a_shr);

    return 0;
}
