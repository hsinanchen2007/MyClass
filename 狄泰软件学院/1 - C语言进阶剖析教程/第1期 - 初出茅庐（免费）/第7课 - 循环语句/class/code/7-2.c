#include <stdio.h>

void f1(int n)
{
    int i = 0;
    
    for(i=1; i<=n; i++)
    {
        if( (i % 2) == 0 )
        {
            break;
        }
        
        printf("%d ", i);
    }
    
    printf("\n");
}

void f2(int n)
{
    int i = 0;
    
    for(i=1; i<=n; i++)
    {
        if( (i % 2) == 0 )
        {
            continue;
        }
        
        printf("%d ", i);
    }
    
    printf("\n");
}

int main()
{
    f1(10);
    f2(10);
    
    return 0;
}