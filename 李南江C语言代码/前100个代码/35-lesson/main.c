#include <stdio.h>

int main()
{
    // 表达式 6＝＝6＝＝6 的值是多少？

    // 第一步运算: 6 == 6 1
    // 第二步运算: 1 == 6 0
    int res = 6 == 6 == 6;
    printf("res = %i\n", res);
    return 0;
}
