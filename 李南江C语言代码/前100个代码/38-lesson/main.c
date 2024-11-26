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
    // 1.定义临时变量, 用于存储临时数据
    int temp;
    // 2.将a保存的值给temp
    temp = a;
    // 3.将b的值给a
    a = b;
    // 4.将temp的值给b
    b = temp;
    printf("交换后: a = %i, b = %i\n", a, b);
    return 0;
}
