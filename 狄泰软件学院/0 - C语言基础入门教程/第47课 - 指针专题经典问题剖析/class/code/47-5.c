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
                      // p 指向了不合法的地址，这个地址处没有变量存在
                      // p 是一个野指针，保存不合法地址的指针都是野指针

    printf("*p = %d\n", *p);

    *p = 200;   // 改变 func 函数中局部变量 var 的值，是不是非常奇怪？？？

    printf("*p = %d\n", *p);

    return 0;
}
