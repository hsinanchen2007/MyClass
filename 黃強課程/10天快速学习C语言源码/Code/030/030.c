
#include <stdio.h>

void  fun(int a)
{
    printf("这是fun函数%d\n", a);
}

int main()
{
     //函数名就代表 函数的首地址
     printf("函数的地址是 %p \n", fun);

      //定义一个函数指针变量，必须与函数的形式一样
     void  (*pFun)(int a);
     pFun = fun; //给函数指针变量赋值

     //函数指针可以当成函数名来使用
     pFun(100);//成功调用函数
}
