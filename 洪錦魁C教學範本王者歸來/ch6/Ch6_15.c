/*   �{���W�� : ch6_15.c                  */
/*   �]�p 1 + 2 + .... + n ��ANSI���     */
#include <stdio.h>
#include <stdlib.h>
int sum(int n)     /* ANSI��ƫŧi�覡 */ 
{
    int i,ret_sum;

    ret_sum = 0;
    for ( i = 1; i <= n; i++ )
       ret_sum += i;
    return ret_sum;
}
int main()
{
    int n;

    printf("�п�J�t�C�[�`�� ==> ");
    scanf("%d",&n);
    printf("�q 1 �[�� %d = %d\n",n,sum(n));
    system("pause");
    return 0;
}
