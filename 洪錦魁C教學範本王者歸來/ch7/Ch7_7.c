/*   �{���W�� : ch7_7.c                   */
/*   �Ҧ��ܼƬҫŧi���~�b�ܼ�             */
#include <stdio.h>
#include <stdlib.h>
int a, b, c;       /* �ŧi�~�b�ܼ� */ 

void add()
{
    c = a + b;
}
int main()
{
    a = b = 4;
    add();
    printf("c = %d \n",c);
    system("pause");
    return 0;
}
