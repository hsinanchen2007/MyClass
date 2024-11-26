#include <stdio.h>

int main()
{
    // 实现+ - * / 简单计算器
    // 1.提示用户输入操作数和操作符号
    printf("请输入需要技术的表达式\n");
    printf("举例: 1+1\n");
    // 2.定义变量保存用户输入的操作数和操作符号
    int a, b;
    char ch;
    // 3.接收用户输入的操作数和操作符号
    scanf("%i%c%i", &a, &ch, &b);
    // 4.根据操作符号进行对应的运算
    switch(ch){
    case '+':
        printf("%i %c %i = %i", a, ch, b, a + b);
        break;
    case '-':
        printf("%i %c %i = %i", a, ch, b, a - b);
        break;
    case '*':
        printf("%i %c %i = %i", a, ch, b, a * b);
        break;
    case '/':
        printf("%i %c %i = %i", a, ch, b, a / b);
        break;
    default:
        printf("想使用更多功能请购买付费版本\n");
        break;
    }
    return 0;
}
