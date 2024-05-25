#include <stdio.h>

int g_var = 1;
static int f_var = 2;   // 只能在当前文件中使用 ==> 静态全局变量

static void func()  // 静态函数只能在当前文件中被调用
{
    printf("void func() : f_var = %d\n", f_var);
}

void test()   // 当前文件中定义的所有函数都可以调用 func() 函数
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
