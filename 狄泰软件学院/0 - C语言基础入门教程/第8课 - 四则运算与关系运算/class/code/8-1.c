#include <stdio.h>

int main()
{
    int a = 5;
    int b = 2;
    double c = 3;

    c = a / b;

    printf("c = %f\n", c);

    c = a % b;

    printf("c = %f\n", c);

    return 0;
}
