/*   �{���W�� : ch6_16.c                  */
/*   exp(x), log(x), log10(x), sqrt(x)    */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    double x = 8.0;

    printf("exp(x)   --> %f  \n",exp(x));
    printf("log(x)   --> %f  \n",log(x));
    printf("log10(x) --> %f  \n",log10(x));
    printf("sqrt(x)  --> %f  \n",sqrt(x));
    system("pause");
    return 0;
}
