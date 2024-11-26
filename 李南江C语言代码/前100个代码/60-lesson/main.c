#include <stdio.h>

int main()
{
    /*
     * while格式:
     * while(条件表达式){
     *      重复执行的代码;
     * }
     * 特点: 只有条件表达式为真, 才会执行{}中的代码
     *
     * dowhile格式:
     * do{
     *      重复执行的代码;
     * }while(条件表达式);
     * 特点: 无论条件表达式是否为真, 都会执行一次{}中的代码
     */

//    while(0){
//        printf("重复执行的代码\n");
//    }

//    do{
//        printf("重复执行的代码\n");
//    }while(0);

//    int num = 1;
//    while(num <= 10){
//        printf("发射子弹%i\n", num);
//        num++;
//    }

    int num = 1;
    do{
        printf("发射子弹%i\n", num);
        num++;
    }while(num <= 10);
    return 0;
}
