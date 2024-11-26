#include <stdio.h>

int main()
{
    /*
     * 1.数据类型的作用
     * 告诉操作系统需要分配多大的存储空间
     * char  1个字节存储空间    -2(7)~2(7)-1
     * int   4个字节存储空间    -2(31)~2(31)-1
     *
     * 2.类型说明符?
     * 在C语言中有两种类型说明符, 一种是用于说明长度的, 一种是用于说明符号位的
     *
     * 3.说明长度的类型说明符
     * 对变量的存储空间进行扩容或者缩容, 说明长度的类型说明符可以用于优化存储空间
     * short  2个字节存储空间   -2(15)~2(15)-1
     * long   在32位编译器下占用4个字节, 在64位编译器下占8个字节
     * long long 8个字节存储空间  -2(63)~2(63)-1
     *
     *
     * 4.如何输出被类型说明符说明的数据
     * short  --> %hi  %hd
     * long   --> %li  %ld
     * long long --> %lli   %lld
     *
     * 5.注意点:
     * 由于说明长度的类型说明符一般都是用于说明int类型, 所以在使用的时候int可以省略
     *
     * short int  == short
     * long int  == long
     * long long int == long long
     *
     *
     * 6.说明符号位的类型说明符
     * 用于明确的告诉操作系统可以保存哪些数据(正数/负数/零)
     * signed     告诉操作系统可以存储正数/负数/零
     * unsigned   告诉操作系统可以存储正数/零, 但是不能存储负数
     *
     * 7.注意点:
     * 默认情况下一个变量就是signed, 所以一般情况下signed我们不用写
     * 如果一个变量被unsigned修饰了, 那么在获取的时候就需要使用%u来获取
     */
//    char ch = 127;
//    char ch = 300;
//    printf("ch = %i\n", ch);

    /*
    int num1 = 123;  // 4个字节
    int size1 = sizeof(num1);
    printf("size1 = %i\n", size1);

    short int num2 = 123; // 2个字节
    int size2 = sizeof(num2);
    printf("size2 = %i\n", size2);

    long int num3 = 123; // 4个字节
    int size3 = sizeof(num3);
    printf("size3 = %i\n", size3);

    long long int num4 = 123; // 8个字节
    int size4 = sizeof(num4);
    printf("size4 = %i\n", size4);
    */

    /*
//    int num = 12345678901;
    long long int num = 12345678901;
    // 注意点: C语言不看怎么存, 只看怎么取
    // %i/%d都是按照int类型来取
//    printf("num = %i\n", num);
    printf("num = %lli\n", num);
    */

    /*
    short num1 = 123;
    int size1 = sizeof(num1);
    printf("size1 = %i\n", size1);

    long num3 = 123; // 4个字节
    int size3 = sizeof(num3);
    printf("size3 = %i\n", size3);

    long long num4 = 123; // 8个字节
    int size4 = sizeof(num4);
    printf("size4 = %i\n", size4);
    */

//    int num = 123;
//    printf("num = %i\n", num);
//    num = 0;
//    printf("num = %i\n", num);
//    num = -123;
//    printf("num = %i\n", num);

//    signed int num = 123;
//    printf("num = %i\n", num);
//    num = 0;
//    printf("num = %i\n", num);
//    num = -123;
//    printf("num = %i\n", num);

    unsigned int num = 123;
    printf("num = %u\n", num);
    num = 0;
    printf("num = %u\n", num);
    num = -123;
    printf("num = %u\n", num);
    return 0;
}
