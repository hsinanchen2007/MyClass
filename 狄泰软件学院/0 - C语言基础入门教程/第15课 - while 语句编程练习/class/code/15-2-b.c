#include <stdio.h>

int main()
{
    double sum = 0.0;
    double an = 1.0;
    int i = 1;
    int flag = 1;

    while( !((-(1e-6) < an) && (an < 1e-6)) )
    {
        an = flag * (1.0/(2*i - 1));
        sum = sum + an;
        flag = flag * (-1);
        i = i + 1;
    }

    printf("PI = %f\n", sum*4);

    return 0;
}
