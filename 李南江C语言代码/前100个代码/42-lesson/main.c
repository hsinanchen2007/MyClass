#include <stdio.h>

int main()
{
    /*
     * if第三种形式
     *
     * if(条件表达式){
     *      条件成立执行的代码
     * }else if(条件表达式){
     *      条件成立执行的代码
     * }else if(条件表达式){
     *      条件成立执行的代码
     * }
     * ...
     * else{
     *      所有条件都不成立执行的代码
     * }
     *
     *
     * 特点: 众多大括号只有一个会被执行, 并且只会被执行一次
     * 会从上至下的依次判断每一个条件表达式, 哪一个条件表达式满足, 就执行哪一个后面{}中的代码
     * 如果所有的条件表达式都不满足, 那么就执行else后面{}中的代码
     *
     * 注意点:
     * else if可以有一个或多个
     */

    int age = 3;
    if(age >= 18){
        printf("上大学\n");
    }else if(age >= 12){
        printf("上中学\n");
    }else if(age >= 6){
        printf("上小学\n");
    }else{
        printf("Other\n");
    }
    printf("最后一条语句\n");
    return 0;
}
