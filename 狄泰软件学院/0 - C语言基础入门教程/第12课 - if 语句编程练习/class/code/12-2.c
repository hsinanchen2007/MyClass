#include <stdio.h>

int main()
{
    int x = 0;
    int y = 0;
    int z = 0;

    int t = 0;

    printf("Input 3 integers: ");

    scanf("%d%d%d", &x, &y, &z);

    if( x < y )
    {
        t = x;
    }
    else
    {
        t = y;
    }

    if( t > z )
    {
        t = z;
    }

    printf("The small one is: %d\n", t);

    return 0;
}
