// ========================================================
// Integer Multiplication and Division
// ========================================================
#include <stdio.h>

#include "c2_5.h"

void display_results(int test_id,
                     int a,
                     int b,
                     int prod1,
                     long long prod2,
                     int quo,
                     int rem,
                     int rc)
{
    printf("Mul/Div test case #%d\n", test_id);
    printf("a = %d, b = %d\n", a, b);
    printf("prod1 = %d, prod2 = %lld\n", prod1, prod2);

    if (rc == 0)
        printf("error: division by zero\n");
    else
        printf("quo = %d, rem = %d\n", quo, rem);

    printf("\n");
}

int main(void)
{
    const int a_vals[] = {47, -291, 19, 247};
    const int b_vals[] = {13, 7, 0, 85};
    const int n = sizeof(a_vals) / sizeof(int);

    printf("----- Results for c2_5 -----\n\n");

    for (int i = 0; i < n; ++i)
    {
        int a = a_vals[i];
        int b = b_vals[i];
        int prod1, quo, rem;
        long long prod2;

        mul_i32_a(&prod1, &prod2, a, b);
        int rc = div_i32_a(&quo, &rem, a, b);
        display_results(i, a, b, prod1, prod2, quo, rem, rc);
    }

    return 0;

}
