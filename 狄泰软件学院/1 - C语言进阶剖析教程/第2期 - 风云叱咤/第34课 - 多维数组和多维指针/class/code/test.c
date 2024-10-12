#include <stdio.h>

int main()
{
    int i = 100;
    int *p = NULL;
    int **pp = NULL;

    pp = &p;
    
    // 以下两种方式都可以
    // *pp = &i;
    p = &i;

    // 100, 009DFD2C, 009DFD34, 009DFD30, 100, 009DFD2C, 009DFD34, 009DFD2C, 100
    printf("%d, %p, %p, %p, %d, %p, %p, %p, %d\n", **pp, *pp, pp, &pp, *p, p, &p, &i, i);

    return 0;
}