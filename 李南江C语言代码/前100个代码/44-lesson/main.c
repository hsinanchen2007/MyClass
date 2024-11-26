#include <stdio.h>

int main()
{
   // 从键盘输入一个整数，判断其是否是偶数，如果是偶数就输出YES，否则输出NO；
    // 1.提示用户输入一个整数
    printf("请输入一个整数, 以回车结束\n");
    // 2.定义变量保存用户输入的数据
    int num;
    // 3.接收用户输入的数据
    scanf("%i", &num);
    // 4.判断用户输入的数据是否是一个偶数
    num % 2 == 0 ? printf("YES\n"): printf("NO\n");
//    if(0 == num % 2){
//        // 5.根据判断结果输出YES或者NO
//        printf("YES\n");
//        num = 1;
//    }else{
//        printf("NO\n");
//        num = 0;
//    }
    printf("num = %i\n", num);

    /*
     * 在企业开发中什么情况下使用三目运算符, 什么情况下使用ifelse
     * 简单的运算, 返回结果只有一条语句的时候, 我们就可以使用三目运算符
     * 复杂的运算, 返回结果不止一条语句的时候, 我们就使用ifelse
     */
    return 0;
}
