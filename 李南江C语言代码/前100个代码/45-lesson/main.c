#include <stdio.h>

int main()
{
    // 接收用户输入的1～7的整数，根据用户输入的整数，输出对应的星期几
    // 1.提示用户输入一个1~7的整数
    printf("请输入一个1~7的整数, 以回车结束\n");
    // 2.定义一个变量保存用户输入的数据
    int day;
    // 3.接收用户输入的数据
    scanf("%i", &day);
    // 4.判断用户输入的数据, 根据判断结果输出星期几
//    if(1 == day){
//        printf("星期一\n");
//    }else if(2 == day){
//        printf("星期二\n");
//    }else if(3 == day){
//        printf("星期三\n");
//    }else if(4 == day){
//        printf("星期四\n");
//    }else if(5 == day){
//        printf("星期五\n");
//    }else if(6 == day){
//        printf("星期六\n");
//    }else if(7 == day){
//        printf("星期日\n");
//    }else{
//        printf("没有这个星期\n");
//    }

    if(day > 7 || day < 1){
        printf("没有这个星期\n");
    }else if(1 == day){
        printf("星期一\n");
    }else if(2 == day){
        printf("星期二\n");
    }else if(3 == day){
        printf("星期三\n");
    }else if(4 == day){
        printf("星期四\n");
    }else if(5 == day){
        printf("星期五\n");
    }else if(6 == day){
        printf("星期六\n");
    }else{
        printf("星期日\n");
    }
    return 0;
}
