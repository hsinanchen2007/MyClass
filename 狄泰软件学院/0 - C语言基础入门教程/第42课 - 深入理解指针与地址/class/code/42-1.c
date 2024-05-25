#include <stdio.h>

int main()
{
    int i = 10;
    float f = 10;

    int* pi = &f;    // WARNING
    float* pf = &f;  // OK

    printf("pi = %p, pf = %p\n", pi, pf);
    printf("*pi = %d, *pf = %f\n", *pi, *pf);

    pi = i;   // WARNING

    *pi = 110;  // OOPS

    printf("pi = %p, *pi = %d\n", pi, *pi);

    return 0;
}
