#include <stdio.h>

// 1.给函数起一个有意义的名称
// 2.确定形参列表
// 3.编写业务逻辑代码
// 4.确定返回值和返回值类型
int getMinus(int a, int b)
{
    int res = a - b;
    return res;
}

int main()
{
    // 需求: 要求计算两个变量的差
    int num1 = 20;
    int num2 = 10;
//    int value = num1 - num2;
    int value = getMinus(num1, num2);
    printf("value = %i\n", value);
    return 0;
}
