#include <stdio.h>

int main()
{
    // 1.switch中的case后面的值不能重复
//    int day = 1;
//    switch(day){
//    case 1:
//        printf("星期一\n");
//        break;
//    case 1:
//        printf("星期二\n");
//        break;
//    default:
//        printf("OTHER\n");
//        break;
//    }

    // 2.switch中的case后面不能定义新的变量
    //  如果想要定义新的变量, 必须加上{}
//    int day = 1;
//    switch(day){
//    case 1:
////        int num = 666; // 报错
//        printf("星期一\n");
//        break;
//    case 2:{
//        int num = 666;
//        printf("星期二\n");
//        break;
//        }
//    default:
//        printf("OTHER\n");
//        break;
//    }

    // 3.switch后面的()中可以放变量/常量/表达式, 但是不能放小数
//    int day = 1;
////    switch(day){ // 变量
////    switch(3){ // 常量
////    switch(1 + 1){ // 表达式
////    switch(3.14){ // 小数
//    switch(3.14 + 1){ // 小数
//    case 1:
//        printf("星期一\n");
//        break;
//    case 2:
//        printf("星期二\n");
//        break;
//    default:
//        printf("OTHER\n");
//        break;
//    }

    // 4.switch中的case后面只能放常量和常量表达式, 不能放变量和小数
    int day = 1;
    int num = 3;
    switch(day){
    case 1: // 常量
        printf("星期一\n");
        break;
    case 1 + 1: // 常量表达式
        printf("星期二\n");
        break;
//    case num: // 变量
//        printf("星期三\n");
//        break;
//    case 3.14: // 小数
//        printf("星期三\n");
//        break;
    case 1 + 3.14: // 小数
        printf("星期三\n");
        break;
    default:
        printf("OTHER\n");
        break;
    }

    return 0;
}
