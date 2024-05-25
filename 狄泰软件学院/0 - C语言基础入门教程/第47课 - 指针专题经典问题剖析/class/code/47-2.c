#include <stdio.h>
#include <stdlib.h>

int getDouble(double** pp, unsigned n)
{
    int ret = 0;
    double* pd = malloc(sizeof(double) * n);

    if( pd != NULL )
    {
        printf("pd = %p\n", pd);
        *pp = pd;
        ret = 1;
    }

    return ret;
}

int main()
{
    double* p = NULL;

    if( getDouble(&p, 5) )
    {
        printf("p = %p\n", p);

        free(p);
    }

    return 0;
}
