#include <stdio.h>

int main()
{
    /*
     –Ë«Û:
     1 * 1 = 1
     1 * 2 = 2 2 * 2 = 4
     1 * 3 = 3 2 * 3 = 6 3 * 3 = 9

     */

    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= i; j++){
//            printf("*");
            printf("%i * %i = %i\t", j, i, j * i);
        }
        printf("\n");
    }
    return 0;
}
