#include <stdio.h>

int g_var = 1;
static int f_var = 2;   // ֻ���ڵ�ǰ�ļ���ʹ�� ==> ��̬ȫ�ֱ���

static void func()  // ��̬����ֻ���ڵ�ǰ�ļ��б�����
{
    printf("void func() : f_var = %d\n", f_var);
}

void test()   // ��ǰ�ļ��ж�������к��������Ե��� func() ����
{
    func();
}

int add(int a, int b)
{
    return a + b;
}

int mul(int a, int b)
{
    return a * b;
}
