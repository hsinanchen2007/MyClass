#include <stdio.h>
#include <string.h>
#include "opm.h"

int main()
{
    struct Test t = {1, 2};

    printf("a + b = %d\n", add(t.a, t.b));
    printf("a * b = %d\n", mul(t.a, t.b));
    printf("g_var = %d\n", g_var);
    // printf("f_var = %d\n", f_var);   // �޷�ֱ��ʹ�������ļ��ж���ľ�̬ȫ�ֱ���

    test();

    return 0;
}

