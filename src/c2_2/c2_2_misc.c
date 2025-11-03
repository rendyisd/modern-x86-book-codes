// ========================================================
// Bitwise Logical Operations
// ========================================================
#include <stdio.h>

#include "c2_2.h"

void display_results(int a, int b, int c, int d, int res1, int res2)
{
    printf("----- Results for c2_2 -----\n\n");
    printf("a = %x\n", a);
    printf("b = %x\n", b);
    printf("c = %x\n", c);
    printf("d = %x\n", d);
    printf("res1 = %x\n", res1);
    printf("res2 = %x\n", res2);
    printf("\n");
}

int main(void)
{ 
    unsigned int a = 0xffffffff;
    unsigned int b = 0x12345678;
    unsigned int c = 0x87654321;
    unsigned int d = 0x55555555;

    unsigned int res1 = bitops_u32_c(a, b, c, d);
    unsigned int res2 = bitops_u32_a(a, b, c, d);

    display_results(a, b, c, d, res1, res2);

    return 0;
}
