#include <stdio.h>
#include <string.h>

struct Test;
struct Test* g_pt;    // 只要有了类型声明就可以创建对应的指针变量

// 必须先给出类型的完整定义才能创建相应类型的变量
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

    printf("g_pt = %p\n", g_pt);
    printf("g_pt->a = %d\n", g_pt->a);
    printf("g_pt->b = %d\n", g_pt->b);

    return 0;
}

