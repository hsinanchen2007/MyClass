/*   �{���W�� : ch7_8.c                       */
/*   �Y�@�ܼƦP�ɳQ�ŧi���~�b�M�ϰ��ܼƪ����� */
#include <stdio.h>
#include <stdlib.h>
int a, b, c;

void add()
{
    int a;             /* �ϰ��ܼ� */ 
    a = 3;
    c = a + b;         /* a �ȬO�ϰ��ܼ� 3 */ 
}
int main()
{
    a = b = 4;
    add();
    printf("c = %d \n",c);
    system("pause");
    return 0;
}
