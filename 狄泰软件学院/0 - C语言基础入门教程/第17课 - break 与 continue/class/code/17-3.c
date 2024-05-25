#include <stdio.h>

int main()
{
    int i = 0;

    for(i=1; i<=10; i=i+1)
    {
        switch( i % 2 )
        {
        case 0:
            printf("%d is even number!\n", i);
            break;
        case 1:
            printf("%d is odd number!\n", i);
            break;
        }
    }

    return 0;
}
