#include <stdio.h>
int say()
{
    lnj:
    printf("say\n");
}

int main()
{
    /*
     * goto作用:
     * 跳转到指定的标签
     *
     * 什么是标签?
     * 只要在函数中的任意位置写上标识符, 然后再标识符的后面写上冒号, 就是标签
     *
     * 注意点:
     * 1.goto可以往后面跳转, 也可以往前面跳转
     * 2.在企业开发中不到万不得已, 不推荐使用goto
     * 3.goto只能在同一个函数中跳转
     */

    /*
    printf("第一条语句\n");
    goto lnj;
    printf("第二条语句\n");
    // 定义一个标签
    lnj:
    printf("第三条语句\n");
    */
    /*
    printf("第一条语句\n");
    lnj:
    printf("第二条语句\n");
    printf("第三条语句\n");
    goto lnj;
    */

    /*
    int num = 1;
    lnj:
    if(num <= 10){
        printf("num = %i\n", num); // 1 2 3
        num++; // 2 3
        goto lnj;
    }
    */


    printf("main");
    goto lnj;
    return 0;
}
