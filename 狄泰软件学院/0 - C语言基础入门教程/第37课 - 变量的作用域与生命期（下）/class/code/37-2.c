#include <stdio.h>

int global;

int func(int x)
{
    static int s_var;   // 全局数据区中的变量，默认初始化为 0
                        // 并且，只做一次初始化
    s_var += x;

    return s_var;
}

int main()
{
    int i = 0;

    for(i=1; i<=5; i++)
    {
        printf("func(%d) = %d\n", i, func(i));
    }

    printf("func(0) = %d\n", func(0));

    printf("global = %d\n", global);

    return 0;
}
