#include <stdio.h>

int main()
{
    // 1.case的穿透问题, 一般情况下case和default后面的break不能省略
    // 因为一旦有一个case或者default被匹配了, 那么其它的case和default都会失效
    // 2.break在switch语句中的作用: 立即结束当前的switch语句
//    int day = 1;
//    switch(day){
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

    // 3.default的位置可以随便写, 也就是不用写在最后
    // 但是无论写在什么地方, default都会在所有case不匹配之后才会执行
//    int day = 1;
//    switch(day){
//    default:
//        printf("OTHER\n");
//        break;
//    case 1:
//        printf("星期一\n");
//        break;
//    case 2:
//        printf("星期二\n");
//        break;
//    }

    // 4.如果default写在最后, 那么default后面的break可以省略
    // 如果default不是写在最后, 那么default后面的break不能省略
    int day = 3;
    switch(day){
    default:
        printf("OTHER\n");
//        break;
    case 1:
        printf("星期一\n");
        break;
    case 2:
        printf("星期二\n");
        break;
//    default:
//        printf("OTHER\n");
////        break;
    }

    // 总结: 一般情况下都不要省略break, 一般情况下都把default写在最后
    return 0;
}
