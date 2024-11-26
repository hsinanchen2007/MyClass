#include <stdio.h>


// 函数声明
//int getSum(int, int);
//int getSum(int, int);
//int getSum(int, int);
//int getSum(int, int);
//int getSum(int, int);
int main()
{

    // 1.函数声明中的形参变量名称可以不写
    // 2.函数的定义不可以重复, 但是函数的声明可以重复
    // 3.函数的声明只要在调用之前声明即可
    int getSum(int, int);
    int num = getSum(10, 20);
    printf("num = %i\n", num);
    return 0;
}
// 函数的定义
int getSum(int a, int b){
    int res = a + b;
    return res;
}



