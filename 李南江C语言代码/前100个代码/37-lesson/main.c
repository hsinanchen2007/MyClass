#include <stdio.h>

int main()
{
    /*
     * 用户从键盘上输入三个整数,找出最大值,然后输入最大值
     */
    // 1.提示用户输入三个整数
    printf("请输入三个整数, 以逗号隔开, 以回车结束\n");
    // 2.定义三个变量, 保存用户输入的三个整数
    int num1, num2, num3;
    // 3.接收用户输入的三个整数
    scanf("%i,%i,%i", &num1, &num2, &num3);
    // 4.找出某两个整数中的最大值
    int temp = num1 > num2 ? num1 : num2;
    // 5.利用找出的最大值再和第三个整数进行比较
    int max = temp > num3 ? temp : num3;
    // 6.输出结果
    printf("max = %i\n", max);

    return 0;
}
