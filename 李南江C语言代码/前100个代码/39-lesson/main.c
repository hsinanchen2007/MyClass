#include <stdio.h>

int main()
{
    /*
     * 有两个变量a和b, a = 10, b = 20; 要求用两种方式交换两个变量中保存的值
     * 交换前: a = 10, b = 20; 交换后 a = 20, b = 10;
     */
    int a = 10;
    int b = 20;
    printf("交换前: a = %i, b = %i\n", a, b);
    // 利用算数运算符
    // a = 10 + 20; a = 30
    a = a + b;
    // b = 30 - 20; b = 10
    b = a - b;
    // a = 30 - 10; a = 20
    a = a - b;
    printf("交换后: a = %i, b = %i\n", a, b);
    return 0;
}
