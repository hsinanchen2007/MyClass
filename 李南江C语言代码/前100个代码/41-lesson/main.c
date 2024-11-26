#include <stdio.h>

int main()
{
    /*
     * if第二种形式
     *
     * if(条件表达式){
     *      条件成立执行的语句
     * }else{
     *      条件不成立执行的语句
     * }
     *
     * 特点: if和else后面大括号中的代码, 只有一个会被执行, 并且只会被执行一次
     * 如果条件为真, 那么就执行if后面大括号中的代码
     * 如果条件为假, 那么就执行else后面大括号中的代码
     */
    int age = 17;
    if(age >= 18){
        printf("开网卡\n");
    }else{
        printf("回家叫家长\n");
    }
    printf("卖饮料\n");
    return 0;
}
