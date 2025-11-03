// ========================================================
// 64-bit Integer Addition and Substraction
// ========================================================
#include <stdio.h>

#include "c2_4.h"

void display_results(const char *msg,
                     long long a,
                     long long b,
                     long long c,
                     long long d,
                     long long res1,
                     long long res2)
{
    printf("%s\n", msg);
    printf("a = %lld\n", a);
    printf("b = %lld\n", b);
    printf("c = %lld\n", c);
    printf("d = %lld\n", d);
    printf("res1 = %lld\n", res1);
    printf("res2 = %lld\n", res2);
    printf("\n");
}

int main(void)
{
    long long a = 10;
    long long b = 40;
    long long c = 9;
    long long d = 6;
    long long res1, res2;

    printf("----- Result for c2_4 -----\n\n");

    res1 = (a + b) - (c + d) + 7;
    res2 = add_sub_i64_a_a(a, b, c, d);
    display_results("Results for add_sub_i64_a_a()", a, b, c, d, res1, res2);

    b *= -10000000000;
    res1 = (a + b) - (c + d) + 12345678900;
    res2 = add_sub_i64_b_a(a, b, c, d);
    display_results("Results for add_sub_i64_b_a()", a, b, c, d, res1, res2); 

    return 0;
}
