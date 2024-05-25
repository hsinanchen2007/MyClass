#include <stdio.h>

int main()
{
    int x = 0;
    int y = 0;

    printf("Input 2 integers: ");

    scanf("%d%d", &x, &y);

    if( x > y )
    {
        printf("The bigger is: %d\n", x);
    }
    else if( x < y )
    {
        printf("The bigger is: %d\n", y);
    }
    else
    {
        printf("The 2 integers is equal: x == y\n");
    }

    return 0;
}
