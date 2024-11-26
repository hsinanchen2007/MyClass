#include <stdio.h>

int main()
{
    /*
     * sizeof运算符
     * 作用: 用来计算某种数据类型占用的存储空间大小
     *
     * 格式:
     * sizeof(变量/常量/数据类型)
     * sizeof 变量/常量
     *
     * 注意点:
     * 1.sizeof是一个运算符, 而不是函数
     * 2.sizeof计算是一个运算符, 所以也有优先级, sizeof运算符的优先级高于算术运算符
     */
    // 1.利用sizeof计算的两种格式
    /*
    int res = sizeof(num);
    printf("res = %i\n", res);

    double value = 3.14;
    int res2 = sizeof value;
    printf("res2 = %i\n", res2);
    */
    // 2.利用sizeof计算常量的两种格式
    /*
    int res = sizeof(5);
    printf("res = %i\n", res);

    int res2 = sizeof 3.14;
    printf("res2 = %i\n", res2);
    */

    // 3.利用sizeof计算数据类型的格式
    /*
    int res = sizeof(char);
    printf("res = %i\n", res);

//    int res2 = sizeof int; // 报错
//    printf("res2 = %i\n", res2);
    */

    // 4.sizeof计算是一个运算符, 所以也有优先级, sizeof运算符的优先级高于算术运算符
//    int res = sizeof(10) + 10; // 4 + 10
    int res = sizeof 10 + 10; // 4 + 10
    printf("res = %i\n", res); // 14
    return 0;
}
