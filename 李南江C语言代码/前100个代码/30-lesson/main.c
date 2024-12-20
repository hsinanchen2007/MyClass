#include <stdio.h>

int main()
{
    /*
     * 1.关系运算符的结合性
     * 左结合性
     * 注意点: 不能使用关系运算符来判断区间
     * 2.关系运算符的优先级
     * < > <= >= 优先级高于 == !=
     */
    // 第一步运算: 10 > 5 返回 1
    // 第二步运算: 1 > 3  返回 0
//    int res = 10 > 5 > 3;
//    printf("res = %i\n", res);

    // 由于==的优先级小于>, 所以会先计算>
    // 第一步运算: 10 > 5 返回 1
    // 第二步运算: 10 == 1 返回 0
    int res = 10 == 10 > 5;
    printf("res = %i\n", res);
    return 0;
}
