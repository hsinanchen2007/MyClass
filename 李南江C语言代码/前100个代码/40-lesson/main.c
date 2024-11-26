#include <stdio.h>

int main()
{
    /*
     * if第一种形式
     *
     * if(条件表达式){
     *      条件成立执行的语句;
     * }
     *
     * 特点:
     * {}只会被执行一次, 并且只有条件满足才会被执行
     */

    int age = 17;
    if(age >= 18){
        printf("开网卡\n");
    }
    printf("卖饮料\n");
    return 0;
}
