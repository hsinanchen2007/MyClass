#include <stdio.h>

int main()
{
    int target = 30;
    int input = 0;

    for(;;)
    {
        printf("Input: ");
        scanf("%d", &input);

        if( input == target )
            break;
        else if( input < target )
            printf("It's small!\n");
        else if( input > target )
            printf("It's big!\n");
    }

    printf("Target = %d\n", input);

    return 0;
}
