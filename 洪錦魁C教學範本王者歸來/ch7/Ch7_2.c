/*   �{���W�� : ch7_2.c                   */
/*   auto �ܼƩ󤣦P��ƪ�����            */
#include <stdio.h>
#include <stdlib.h>
void fun1()
{
    int i = 1;     /* �����ŧi���� auto �ܼ� */ 
    printf("fun1 ��� i = %d\n",i);
}
void fun2()
{
    int i = 2;     /* �����ŧi���� auto �ܼ� */
    printf("fun2 ��� i = %d\n",i);
}
int main()
{
    int  i = 0;
    printf("Main �D�{�� i = %d \n",i);
    fun1();
    fun2();
    printf("Main �D�{�� i = %d \n",i);
    fun1();
    fun2();
    system("pause");
    return 0;
}
