#include <stdio.h>
#include <string.h>

struct Test;
struct Test* g_pt;    // ֻҪ�������������Ϳ��Դ�����Ӧ��ָ�����

// �����ȸ������͵�����������ܴ�����Ӧ���͵ı���
struct Test
{
    int a;
    int b;
};

int main()
{
    struct Test t;

    t.a = 1;
    t.b = 2;

    g_pt = &t;

    printf("g_pt = %p\n", g_pt);            // g_pt = 00F3F93C
    printf("g_pt->a = %d\n", g_pt->a);      // g_pt->a = 1
    printf("g_pt->b = %d\n", g_pt->b);      // g_pt->b = 2

    return 0;
}

