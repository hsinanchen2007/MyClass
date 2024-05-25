#include <stdio.h>

int main()
{
    int score = 0;

    printf("Input score: ");

    scanf("%d", &score);

    if( (0 <= score) && (score <= 100) )
    {
        if( score >= 90 )
            printf("A\n");
        else if( score >= 80 )
            printf("B\n");
        else if( score >= 70 )
            printf("C\n");
        else if( score >= 60 )
            printf("D\n");
        else
            printf("E\n");
    }
    else
    {
        printf("Invalid Score!\n");
    }

    return 0;
}
