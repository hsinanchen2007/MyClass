#include <stdio.h>

int main()
{
    // 需求: 交换两个变量的值
    int a = 10;
    int b = 20;
    printf("a = %i, b = %i\n", a, b);
    // 第一种方式: 利用临时变量
//    int temp;
//    temp = a; // temp = 10;
//    a = b; // a = 20;
//    b = temp; // b = 10;

    // 第二种方式: 利用算数运算符
//    a = a + b; // a = 10 + 20; a = 30;
//    b = a - b; // b = 30 - 20; b = 10;
//    a = a - b; // a = 30 - 10; a = 20;

    // 第三种方式: 利用位运算符
    a = a ^ b;
    b = a ^ b; //  b = a ^ b ^ b;
    a = a ^ b; //  a = a ^ a ^ b;
    printf("a = %i, b = %i\n", a, b);
    return 0;
}
