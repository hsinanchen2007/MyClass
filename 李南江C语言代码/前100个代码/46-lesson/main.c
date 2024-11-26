#include <stdio.h>

int main()
{
    /*
     * 接收用户输入的一个整数month代表月份，根据月份输出对应的季节
     * 3/4/5 春季 6/7/8 夏季 9/10/11 秋季 12/1/2 冬季
     */
    // 1.提示用户输入一个1~12的整数
    printf("请输入一个1~12的整数, 以回车结束\n");
    // 2.定义变量保存用户输入的数据
    int month;
    // 3.接收用户输入的数据
    scanf("%i", &month);
    // 4.判断是什么季节, 然后输出结果
//    if(month == 3 || month == 4 || month == 5){
//        printf("春季\n");
//    }else if(month == 6 || month == 7 || month == 8){
//        printf("夏季\n");
//    }else if(month == 9 || month == 10 || month == 11){
//        printf("秋季\n");
//    }else if(month == 12 || month == 1 || month == 2){
//        printf("冬季\n");
//    }else{
//        printf("没有这个季节\n");
//    }

//    if(month < 1 || month > 12){
//        printf("没有这个季节\n");
//    }else if(month == 3 || month == 4 || month == 5){
//        printf("春季\n");
//    }else if(month == 6 || month == 7 || month == 8){
//        printf("夏季\n");
//    }else if(month == 9 || month == 10 || month == 11){
//        printf("秋季\n");
//    }else if(month == 12 || month == 1 || month == 2){
//        printf("冬季\n");
//    }

    if(month < 1 || month > 12){
        printf("没有这个季节\n");
    }else if(month >= 3 && month <= 5){
        printf("春季\n");
    }else if(month >= 6 && month <= 8){
        printf("夏季\n");
    }else if(month >= 9 && month <= 11){
        printf("秋季\n");
    }else{
        printf("冬季\n");
    }
    return 0;
}
