#include <stdio.h>

int global;                     // by default it will be initialized as 0

static int s_global = 1000;     // static variable and initialized as 1000

int func(int x)
{
    static int s_var;   // 全局数据区中的变量，默认初始化为 0
                        // 并且，只做一次初始化
    s_var += x;

    return s_var;
}

int func2(int x)
{
    // s_var2 is being initialized at first time call, and then 
    // its value will be kept in whole program life time
    static int s_var2 = 100;   

    s_var2 += x;

    return s_var2;
}

int func3(int x)
{
    // s_global is being initialized outside this function
    // and its value will be kept in whole program life time
    s_global += x;

    return s_global;
}

int main()
{
    int i = 0;

    printf("global = %d\n", global);
    printf("s_global = %d\n", s_global);

    for(i=1; i<=5; i++)
    {
        printf("func(%d) = %d\n", i, func(i));
    }

    for(i=1; i<=5; i++)
    {
        printf("func2(%d) = %d\n", i, func2(i));
    }

    for(i=1; i<=5; i++)
    {
        printf("func3(%d) = %d\n", i, func3(i));
    }

    printf("func(0) = %d\n", func(0));

    printf("global = %d\n", global);

    return 0;
}
