#include <stdio.h>

int main()
{
    // 1.if后面的{}可以省略, 但是如果省略if后面的{}, 那么只有紧随其后的那条语句受到if的控制
//    int age = 17;
//    if(age >= 18)
//        printf("开网卡\n");
//        printf("玩游戏\n"); // 不受控制
//    printf("卖饮料\n");

    // 2.如果省略了if后面的{}, 那么不能在紧随其后的位置定义新的变量
//    int age = 17;
//    if(age >= 18)
//        int num = 666;
//        printf("玩游戏\n"); // 不受控制
//    printf("卖饮料\n");

    // 3.else后面的{}也可以省略, 省略之后和if一样, 只有紧随其后的那条语句受到控制
//    int age = 19;
//    if(age >= 18){
//        printf("玩游戏\n");
//    }else
//        printf("回家叫家长\n");
//        printf("Other\n"); // 不受控制
//    printf("卖饮料\n");

    // 4.else if后面的{}也可以省略, 省略之后和if一样, 只有紧随其后的那条语句受到控制
    // 并且如果省略了else if后面的大括号, 那么后面只能编写一条语句
    // 如果想编写多条语句, 那么后面必须没有else

//    int age = 19;
//    if(age >= 18){
//        printf("上大学\n");
//    }else if(age >= 12)
//        printf("上中学\n");
//        printf("谈恋爱\n");
////    else{
////        printf("Other\n");
////    }
//    printf("最后一条语句\n");

    // 总结: 在企业开发中, 一定不要省略{}

    // 5.if的()后面不用编写分号, 因为分号也是一条语句, 分号是一条空语句
    // 在C语言中如果{}单独出现, 我们称之为代码块, 代码块一般用于控制局部变量的作用域
//    int age = 17;
//    if(age >= 18);
//    {
//        printf("开网卡\n");
//        int num = 666;
////        printf("num = %i\n", num);
//    }
//    printf("num = %i\n", num);
//    printf("卖饮料\n");

    // 6.在C语言中任何数值都有真假性 (非0既真)
//    if(1){
//    if(666){
//    if(0){
//        printf("开网卡\n");
//    }
//    printf("卖饮料\n");

    // 7.正式因为在C语言中任何数值都有真假性, 所以在判断条件的时候, 如果是==, 那么把常量写在前面, 把变量写在后面
//    int age = 16;
////    if(age = 18){ //  if(18){
//    if(18 = age){
//        printf("开网卡\n");
//    }
//    printf("卖饮料\n");

    // 8.if可以嵌套使用
    // 在企业开发中一般情况下不会嵌套超过三层
    if(1){
        if(0){
            printf("A\n");
        }else{
            printf("B\n");
        }
    }else{
        if(0){
            printf("C\n");
        }else{
            printf("D\n");
        }
    }
    return 0;
}
