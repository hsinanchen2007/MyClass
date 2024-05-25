#include <stdio.h>

int main()
{
    int a = 0;
    int c = 1;

    if( a + c > 0 )
    {
        printf("a = %d, c = %d\n", a, c);
        goto ELSE;
    }
    else
    {
        ELSE: printf("%d + %d = %d\n", a, c, a + c);
        goto FOR;
    }

    for(c=10; c>0; c--)
    {
        FOR:
        printf("c = %d\n", c);
    }

    return 0;
}
