// ========================================================
// Mixed-Type Integer Arithmetic
// ========================================================
#include <stdio.h>
#include <inttypes.h>

#include "c3_3.h"

void display_results(int32_t i,
                     int32_t rc,
                     int32_t v1, int32_t v2, int32_t v3, int32_t v4)
{
    printf("i = %d, rc = %d, v1 = %d, v2 = %d, v3 = %d, v4 = %d\n",
           i, rc, v1, v2, v3, v4);

    if(!(v1 == v2 && v2 == v3 && v3 == v4))
        printf("validation test failed, i = %d\n", i);
}

int main(void)
{
    printf("----- Results for c3_3 -----\n");

    // Initialize g_sum_primes_a (defined in the assembly language file)
    g_sum_primes_a = 0;

    for (int i = -1; i < g_num_primes_a + 1; i++) {
        int32_t v1 = -1, v2 = -1, v3 = -1, v4 = -1;
        int32_t rc = mem_addressing_a(i, &v1, &v2, &v3, &v4);

        display_results(i, rc, v1, v2, v3, v4);
    }

    printf("\ng_sum_primes_a = %d\n", g_sum_primes_a);

    return 0;
}
