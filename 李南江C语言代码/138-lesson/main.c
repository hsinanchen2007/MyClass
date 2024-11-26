#include <stdio.h>

int main()
{
    /*
     * 1.字符串的特点
     * 字符串的本质就是一个特殊的数组
     * 数组中保存的都是字符, 并且数组必须以\0结尾
     *
     * 2.如何定义字符串?
     * char str1[] = {'l', 'n', 'j', '\0'};
     * char str2[] = "lnj";
     *
     * 3.数组的特点
     * 数组名保存的就是数组的地址, 所以我们可以直接将数组名赋值给一个指针变量
     *
     * 4.正式因为如何, 所以定义字符串有了第三种方式
     * char *str3 = "lnj";
     *
     * 5.通过指针变量接收字符串和通过数组变量接收字符串有什么区别?
     * 通过数组变量接收字符串, 这个字符串存储在栈中
     * 通过指针变量接收字符串, 这个字符串存储在常量区中
     * 存储的区域不同
     *
     * 6.存储的区域不同带来的影响
     * 6.1存储在栈中的数据, 是可以修改的. 存储在常量区中的数据, 是不可以修改
     * 6.2通过数组变量接收字符串, 哪怕字符串中的数据相同, 每次定义也会重新分配存储空间
     *    通过指针变量接收字符串, 只要字符串中的数据相同, 就只有第一次定义会分配存储空间
     */
//    char str1[] = {'l', 'n', 'j', '\0'};
//    char str2[] = "lnj";
//    char *str3 = "lnj";
//    printf("str1 = %s\n", str1);
//    printf("str2 = %s\n", str2);
//    printf("str3 = %s\n", str3);

//    str1[2] = 'X';
//    printf("str1 = %s\n", str1);
//    str3[2] = 'X'; // 不可以修改
//    printf("str3 = %s\n", str3);

//    char str1[] = {'l', 'n', 'j', '\0'};
//    char str2[] = {'l', 'n', 'j', '\0'};
//    printf("str1 = %p\n", str1);
//    printf("str2 = %p\n", str2);

//    char str1[] = "lnj";
//    char str2[] = "lnj";
//    printf("str1 = %p\n", str1);
//    printf("str2 = %p\n", str2);

    char *str1 = "lnj";
    char *str2 = "lnj";
    printf("str1 = %p\n", str1);
    printf("str2 = %p\n", str2);
    return 0;
}

