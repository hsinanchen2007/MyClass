/*   �{���W�� : ch7_6.c                   */
/*   �~�b external �ܼƪ�����             */
#include <stdio.h>
#include <stdlib.h>
int val;              /* �ŧi�~�b�ܼ� */ 

void max(int a, int b)
{
    val = ( a > b ) ? a : b;
}
int main()
{
    int c = 5;
    int d = 6;

    max( c, d );
    printf("���j�� = %d \n",val);
    system("pause");
    return 0;
}
