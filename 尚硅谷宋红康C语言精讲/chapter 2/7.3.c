#include <stdio.h>

/*
    在C语言中，puts() 是一个用于输出字符串的标准库函数，其原型定
    义在 <stdio.h> 头文件中。puts() 函数的作用是将一个以
    null 字符（ \0 ）结尾的字符串打印到标准输出（通常是控制台）
    上，并自动添加一个换行符。

    注意，puts()函数只能用于输出字符串，而不能输出其他类型的数
    据。如果需要输出其他类型的数据，应使用 printf() 函数。
*/

int main() {
    char str1[]={"China\nBeijing"};
    char str2[] = "helloworld";

    puts(str1);
    puts(str2);

    char str[15];
    printf("enter your name:");
    gets(str); //输入字符串至数组变量str
    printf("your name is ");
    puts(str); //输出字符串

    return 0;
}