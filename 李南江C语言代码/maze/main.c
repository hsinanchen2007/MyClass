
#include <stdio.h>

int main()
{
    /*
     * 1.字符串和指针
     * 1.1字符串的本质就是一个特殊的数组
     * 保存的都是字符, 并且以\0结尾
     * 1.2数组名保存的就是数组的地址
     * 可以将数组名赋值给一个指针变量
     * 1.3正式因为如何,所以定义字符串又多了一种方式
     * char str[] = {'',''};
     * char str[] = "";
     * char *str = "";
     *
     * 2.利用数组和指针定义字符串的区别
     * 利用数组定义字符串保存在栈中
     * 利用指针定义字符串保存在常量区中
     *
     * 3.注意点:
     * 由于利用数组定义的字符串保存在栈中, 所以操作系统需要提前知道开辟多大存储空间
     * 所以利用数组定义字符串不能直接利用指针变量接收
     */
    /*
    char str1[] = {'l', 'n', 'j', '\0'};
    char str2[] = "lnj";
    char *str3 = "lnj";
    printf("str1 = %s\n", str1);
    printf("str2 = %s\n", str2);
    printf("str3 = %s\n", str3);
    */

    char str1[] = {'l', 'n', 'j', '\0'};
    char str2[] = {'l', 'n', 'j', '\0'};
    char str3[] = "lnj";
    char str4[] = "lnj";
    printf("str1 = %p\n", str1);
    printf("str2 = %p\n", str2);
    printf("str3 = %p\n", str3);
    printf("str4 = %p\n", str4);

    char *str5 = "abc";
    char *str6 = "abc";
    printf("str5 = %p\n", str5);
    printf("str6 = %p\n", str6);
    return 0;
}
