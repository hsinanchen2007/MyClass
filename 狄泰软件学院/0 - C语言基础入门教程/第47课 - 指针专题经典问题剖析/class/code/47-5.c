#include <stdio.h>
#include <stdlib.h>

int* func()
{
    int var = 100;

    return &var;
}

int main()
{
    int* p = func();  // OOPS!!!!
                      // p ָ���˲��Ϸ��ĵ�ַ�������ַ��û�б�������
                      // p ��һ��Ұָ�룬���治�Ϸ���ַ��ָ�붼��Ұָ��

    printf("*p = %d\n", *p);

    *p = 200;   // �ı� func �����оֲ����� var ��ֵ���ǲ��Ƿǳ���֣�����

    printf("*p = %d\n", *p);

    return 0;
}
