/*   �{���W�� : ch4_3.c                   */
/*   �p�� 1 + 2 + ..... + 100             */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int sum = 0;
    int i = 1;

    for ( ; i <= 100; )
       sum += i++;
    printf("�`�M = %d \n",sum);
    system("pause");
    return 0;
}
