#include <stdio.h>

int var = 100;  // 全局变量

int main()
{
    int var = 10;  // 局部变量

    {
        int var = 1;  // 局部变量

        printf("var = %d\n", var);
    }

    printf("var = %d\n", var);  // var = 10;

    return 0;
}
