#include <stdio.h>

int main()
{
    int a = 1;
    int b = 2;
    char sign = 0;

    printf("Input a sign: ");

    scanf("%c", &sign);

    switch(sign)
    {
        case '+':
            printf("%d + %d = %d\n", a, b, a + b);
            break;
        case '-':
            printf("%d - %d = %d\n", a, b, a - b);
            break;
        case '*':
            printf("%d * %d = %d\n", a, b, a * b);
            break;
        default:
            printf("Unsupported Sign: %c\n", sign);
    }

    return 0;
}
