#include <stdio.h>

int main()
{
    // 需求: 判断一个整数是偶数还是奇数, 是偶数输出YES, 是奇数输出NO

    // 1.第一种实现方式: 三目运算符
//    int num = 5;
//    num % 2 == 0 ? printf("YES") : printf("NO");

    // 2.第二种实现方式: if else
//    int num = 5;
//    if(num % 2 == 0){
//        printf("YES");
//    }else{
//        printf("NO");
//    }

    // 3.第三种实现方式: 利用位运算符
    /*
     * 8 --> 二进制
     * 1000
     *&0001
     *
     * 6 --> 二进制
     * 0110
     *&0001
     *
     * 9 --> 二进制
     * 1001
     *&0001
     *
     * 7 --> 二进制
     * 0111
     *&0001
     */
    int num = 5;
    if((num&1) == 0){
       printf("YES");
    }else{
        printf("NO");
    }
    return 0;
}
