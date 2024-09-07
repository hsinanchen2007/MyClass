#include <stdio.h>

int main()
{
    int sum = 0;
    int input = 0;
    int i = 0;

    // will not have below output 
    while( i > 100 )
        printf("while( i > 0 )\n");

    // will have below output as do { ...... } while ( ...... )
    // will always have loop once
    do
        printf("do...while( i > 0 )\n");
    while( i > 100 );


    do
    {
        printf("Input: ");
        scanf("%d", &input);
        sum = sum + input;
    } while( sum < 100 );

    printf("sum = %d\n", sum);

    return 0;
}
