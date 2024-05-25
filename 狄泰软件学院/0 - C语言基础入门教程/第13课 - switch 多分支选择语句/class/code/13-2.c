#include <stdio.h>

int main()
{
    int num = 0;

    printf("Input a number: ");

    scanf("%d", &num);

    switch( num )
    {
        case 1:
            printf("A\n");
            break;
        case 2:
            printf("B\n");
            break;
        case 3:
            printf("C\n");
            break;
        case 4:
            printf("D\n");
            break;
        case 5:
            printf("E\n");
            break;
        default:
            printf("Invalid Input\n");
    }

    return 0;
}
