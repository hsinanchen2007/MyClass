#include <stdio.h>

int main()
{
    // 1.和while一样, for后面的{}也可以省略, 如果省略{}, 那么只有紧随其后的那条语句受到for的控制
//    for(int num = 15; num <= 10; num++)
//        printf("语句一\n");
//        printf("语句二\n");
//    printf("OTHER\n");

    // 2.和while一样, 如果for省略了{}, 那么不能在紧随其后的位置定义新的变量
//    for(int num = 15; num <= 10; num++)
//        int value = 666;
//        printf("语句二\n");
//    printf("OTHER\n");

    // 3.和while一样, for的()后面不用添加分号, 分号是一条空语句
//    for(int num = 15; num <= 10; num++);

//    {
//        printf("语句一\n");
//        printf("语句二\n");
//    }
//    printf("OTHER\n");

    // 4.和while一样, 任何数值都有真假性
    for(;666;){
        printf("语句一\n");
    }
    return 0;
}
