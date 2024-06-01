#include <stdio.h>

int g = 0;

int f()
{
    printf("In f()...\n");

    return g++;
}

int main()
{
    if( g || f() && f() )
    {
        printf("In if statement: %d\n", g);
    }
    
    printf("In main(): %d\n", g);
    
    return 0;
}
