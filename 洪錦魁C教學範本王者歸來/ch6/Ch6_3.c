/*   �{���W�� : ch6_3.c                   */
/*   �C�L���j�Ȩ��                       */
#include <stdio.h>
#include <stdlib.h>
void larger_value( a, b )
int a,b;
{
    if ( a < b )
       printf("���j�ȬO %d \n",b);
    else if ( a > b )
       printf("���j�ȬO %d \n",a);
    else
       printf("��ƭȬ۵� \n");
}
int main()
{
    int i,j;

    printf("�п�J��ƭ� \n ==> ");
    scanf("%d %d",&i,&j);
    larger_value(i,j);
    system("pause");
    return 0;
}
