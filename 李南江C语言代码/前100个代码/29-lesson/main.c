#include <stdio.h>

int main()
{
    /*
     * 关系运算符
     * < > <= >= == !=
     *
     * 关系运算符也是一个运算符, 所以也有运算结果
     * 关系成立返回1, 真
     * 关闭不成立返回0, 假
     *
     * 在C语言中, 任何非0的值都代表真, 只有0才是假
     */
//    int res = 10 > 9;
    int res = 10 > 11;
    printf("res = %i\n", res);
    return 0;
}
