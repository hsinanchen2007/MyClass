#include <stdio.h>

int var = 100;  // 全局变量

void f(int var) // var <==> 局部变量
{
    var++;

    printf("var = %d\n", var);
}

int main()
{
    int var = 10;  // 局部变量

    f(var);  // f(10);

    printf("var = %d\n", var);  // var = 10;

    return 0;
}
