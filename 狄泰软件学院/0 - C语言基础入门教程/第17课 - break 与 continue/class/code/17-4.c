#include <stdio.h>

int main()
{
    int k = 0;
    int input = 0;

    printf("Input: ");
    scanf("%d", &input);

    switch( input % 2 )
    {
        case 0:
            printf("case 0\n");
            for(k=0; k<=2; k=k+1)
                if( k )
                    break;  //  exit for loop
            break;  // exit switch
        case 1:
            printf("case 1\n");
            break;  // exit switch
    }


    return 0;
}
