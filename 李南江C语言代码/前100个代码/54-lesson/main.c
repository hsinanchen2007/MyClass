#include <stdio.h>

int main()
{
    // 需求: 要求判断用户输入的一个整数是否是100~200之间的整数
    // if更适合对区间进行判断, switch更适合对固定的几个值进行判断
    // 但是switch能做的if都能做, 所以在企业开发中, 能用if就用if
    printf("请输入一个整数, 以回车结束\n");
    int num;
    scanf("%i", &num);
    // 利用if来判断
//    if(num >= 100 && num <= 200){
//        printf("是100~200之间的整数\n");
//    }else{
//        printf("不是100~200之间的整数\n");
//    }

    // 利用switch来判断
    /*
     * 101 / 10 = 10; 120 / 10 = 12
     * 200 / 10 = 20; 202 / 10 = 20;
    */
//    switch (score) {
//    case 100:

//        break;
//    default:
//        break;
//    }
    return 0;
}
