#include <stdio.h>

int main()
{
    int num = 0;

    printf("Input a number: ");

    scanf("%d", &num);

    switch( num % 3 )
    {
        case 0:
            printf("Object Number: %d\n", num);
            break;
        case 1:
            printf("Bigger!\n");
            break;
        case 2:
            printf("Smaller!\n");
            break;
    }


    return 0;
}
