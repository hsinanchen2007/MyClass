#include <stdio.h>

int fac(int n)
{
    if( n == 1 )
    {
        return 1;
    }
    else if( n == 2 )
    {
        return 1;
    }
    else
    {
        return fac(n-1) + fac(n-2);
    }
    
    return -1;
}

int main()
{
    printf("%d\n", fac(1));
    printf("%d\n", fac(2));
    printf("%d\n", fac(9));
    
    return 0;
}
