/*   �{���W�� : ch15_7.c                  */
/*   �ϥ� rand() ��ƦC�X 10 ���H����     */
#include <stdlib.h>
#include <stdio.h>
int main()
{
    int  i;

    for ( i = 0; i < 10; i++ )
       printf("%d\n",rand());
    system("pause");
    return 0;   
}
