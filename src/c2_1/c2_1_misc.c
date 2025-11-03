#include <stdio.h>

#include "c2_1.h"

void display_results(int a, int b, int c, int d, int res1, int res2)
{
    printf("----- Results for c2_1 -----\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n", c);
    printf("d = %d\n", d);
    printf("res1 = %d\n", res1);
    printf("res2 = %d\n", res2);
    printf("\n");
}

int main(void)
{ 
    int a = 10;
    int b = 40;
    int c = 9;
    int d = 6;

    int res1 = (a + b) - (c + d) + 7;
    int res2 = add_sub_i32_a(a, b, c, d);

    display_results(a, b, c, d, res1, res2);

    return 0;
}
