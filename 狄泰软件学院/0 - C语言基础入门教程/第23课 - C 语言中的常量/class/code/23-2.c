#include <stdio.h>

int main()
{
    const int ci = 222;
    const double cd = 1.11;

    int it = ci;
    double dd = cd;

    /* ERROR:
        ci = 333;
        cd = 2.22;
    */

    printf("it = %d\n", it);
    printf("dd = %f\n", dd);

    return 0;
}
