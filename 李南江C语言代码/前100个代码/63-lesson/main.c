#include <stdio.h>

int main()
{
    // 特点: while循环结束之后, 用于控制循环的变量还可以继续使用
//    int num = 1;
//    while(num <= 10){
//        printf("发射子弹%i\n", num);
//        num++;
//    }
//    printf("num = %i\n", num);

    // 特点: for循环结束之后, 用于控制循环的变量不可以继续使用
//    for(int num = 1; num <= 10; num++){
//        printf("发射子弹%i\n", num);
//    }
//    printf("num = %i\n", num);

    // 总结:
    // 在企业开发中, 如果用于控制循环的变量, 循环结束之后还需要使用, 那么建议使用while循环
    // 在企业开发中, 如果用于控制循环的变量, 循环结束之后不需要使用, 那么建议使用for循环
    // 规律:
    // 能用for循环就用for循环
    return 0;
}
