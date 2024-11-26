#include <stdio.h>

int main()
{
    // 用户从键盘上输入两个整数,找出最大值,然后输入最大值
    // 1.提示用户如何输入两个整数
    printf("请输入两个整数, 以逗号隔开, 以回车结束\n");
    // 2.定义两个变量, 用于保存用户输入的数据
    int num1, num2;
    // 3.接收用户输入的两个整数
    scanf("%i,%i", &num1, &num2);
    // 4.比较两个整数, 找到最大的那个整数
    int max = num1 > num2 ? num1 : num2;
    // 5.输入找到的那个最大值
    printf("max = %i\n", max);

    return 0;
}
