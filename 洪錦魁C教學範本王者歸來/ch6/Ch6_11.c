/*   �{���W�� : ch6_11.c                  */
/*   ��ƹ�ը�Ƴ]�p                     */
#include <stdio.h>
#include <stdlib.h>
void swap(x,y)
int *x,*y;
{
    int tmp;

    tmp = *x;
    *x = *y;
    *y = tmp;
}
int main()
{
    int i,j;

    i = 5;
    j = 6;
    printf("�I�s swap �e\n");
    printf("i = %d,    j = %d \n",i,j);
    swap(&i,&j);
    printf("�I�s swap ��\n");
    printf("i = %d,    j = %d \n",i,j);
    system("pause");
    return 0;
}
