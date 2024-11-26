#include <stdio.h>

int main()
{
    // 1.和if一样, while后面的{}也可以省略, 如果省略{}, 那么只有紧随其后的那条语句受到while的控制
//    int num = 12;
//    while(num <= 10)
//        printf("发射子弹\n");
//        printf("Other\n");
//    printf("while外面的语句\n");

    // 2.和if一样, 如果while省略了{}, 那么不能在紧随其后的位置定义新的变量
//    int num = 12;
//    while(num <= 10)
//        int num = 666;
//        printf("Other\n");

    // 3.和if一样, while的()后面不用添加分号, 分号是一条空语句
//    int num = 12;
//    while(num <= 10);{
//        printf("发射子弹\n");
//        printf("Other\n");
//    }
//    printf("while外面的语句\n");

    // 4.和if一样, 任何数值都有真假性
    while(0){
        printf("发射子弹\n");
    }
    printf("while外面的语句\n");
    return 0;
}
