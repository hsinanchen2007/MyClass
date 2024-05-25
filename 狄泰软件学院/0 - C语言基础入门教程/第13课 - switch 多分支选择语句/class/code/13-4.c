#include <stdio.h>

int main()
{
    int num = 0;

    printf("Input a number: ");

    scanf("%d", &num);

    switch( num )
    {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            printf("%c\n", 'A' + (num - 1));
            break;
        default:
            printf("Invalid Input\n");
    }

    return 0;
}
