/*   �{���W�� name : ch4_2.c              */
/*   �p�� 1 + 2 + ..... + 100             */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int sum = 0;
    int i;

    for ( i = 1; i <= 100; i++ )
       sum += i;
    printf("�`�M = %d \n",sum);
    system("pause");
    return 0; 
}
