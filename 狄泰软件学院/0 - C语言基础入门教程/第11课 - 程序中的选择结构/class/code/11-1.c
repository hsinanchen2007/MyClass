#include <stdio.h>

int main()
{
    short a = 1;
    short b = 2;
    int c = a - b;

    if( c > 0 )
    {
        printf("a > b\n");
    }
    else
    {
        printf("a <= b\n");
    }

    return 0;
}
