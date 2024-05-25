#include <stdio.h>

int main()
{
    float f = 1.49f;
    float r = 0;

    r = f + 0.5f;
    r = (int)r;

    printf("f = %f\n", f);
    printf("r = %f\n", r);

    return 0;
}
