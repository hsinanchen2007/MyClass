/*   �{���W�� : ch4_17.c                     */
/*   ���� 1 + 2 + .... + 100 �ϥ� do ..while */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,sum;

    i = 1;
    sum = 0;
    do
    {
       sum += i++;
    } while ( i <= 100 );
    printf("�`�M = %d \n",sum);
    system("pause");
    return 0;
}
