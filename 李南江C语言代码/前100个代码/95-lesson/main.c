#include <stdio.h>

int main()
{
    /*
     * 1.按位左移 <<
     * 运算的步骤: 将二进制的所有位都往左边移动, 移出去的部分删除, 在最后添加0
     * 规律: 左移多少位就是乘以2的多少次幂
     * 注意点: 左移运算可能会改变数值的正负性
     *
     * 9 << 1   --> 9 * 2(1) --> 9 * 2 --> 18
     *
     * 0000 0000 0000 0000 0000 0000 0000 0000 参照物
     * 000 0000 0000 0000 0000 0000 0000 10010   -->18
     *
     *
     * 9 << 2  --> 9 * 2(2)  --> 9 * 4 --> 36
     * 0000 0000 0000 0000 0000 0000 0000 0000 参照物
       00 0000 0000 0000 0000 0000 0000 100100   -->36
     *
     * 2.按位右移 >>
     * 运算的步骤: 将二进制除了符号位以外的所有位都向右移动, 移出去的部分删除, 在最高的后面补最高位
     * 规律: 右移多少位就是除以2的多少次幂
     * 9 >> 1  --> 9 / 2(1)  --> 9 / 2  --> 4
     * 0000 0000 0000 0000 0000 0000 0000 0000 参照物
     * 00000 0000 0000 0000 0000 0000 0000 100
     *
     * 9 >> 2  --> 9 / 2(2)  --> 9 / 4  --> 2
     * 0000 0000 0000 0000 0000 0000 0000 0000 参照物
     * 000000 0000 0000 0000 0000 0000 0000 10
     */
//    int res = 9 << 1;
//    int res = 9 << 2;
//    int res = 9 >> 1;
    int res = 9 >> 2;
    printf("res = %i\n", res);
    return 0;
}
