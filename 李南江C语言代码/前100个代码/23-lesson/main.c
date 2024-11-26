#include <stdio.h>

int main()
{
    /*
     * 赋值运算符
     * 1.简单的赋值运算符
     * =
     * 2.复杂的赋值运算符
     * += -= *= /= %=
     *
     * 结合性: 右结合性
     * 注意点: 赋值运算符的优先级要低于算术运算符
     */
    /*
    // 1.简单的赋值运算符
    // 作用: 将等号右边的值放到等号左边变量对应的存储空间中
    int num;
    num = 666;
    printf("num = %i\n", num);

    // 2.复杂的赋值运算符
    // 作用: 将等号左边的值取出来和等号右边的值计算, 计算之后再把计算的结果赋值给等号的左边
    int value = 5;
//    value += 10; // 相当于 value = value + 10
    value -= 10; // 相当于 value = value - 10
    printf("value = %i\n", value);
    */

//    int num;
//    num = 2 + 2;
//    printf("num = %i\n", num); // 4

    int value = 5;
    value += 2 + 2; // value += (2 + 2);  value = value + (2 + 2); value = 5 + (4)
    printf("value = %i\n", value);
    return 0;
}
