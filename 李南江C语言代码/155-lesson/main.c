#include <stdio.h>

int main()
{
    /*
     * 1.auto关键字(忘记)
     * 作用: 告诉操作系统, 将变量存储到栈中. 默认情况下变量就是存储在栈中的, 所以默认情况下变量就是被auto修饰的
     *
     * 2.register关键字(忘记)
     * 作用: 告诉操作系统, 将变量存储到CPU的寄存器中, 可以提升变量的访问速度
     * 注意点: 当C语言代码被编译为二进制的时候, 编译器会自动优化代码, 可能会自动将register修饰的变量优化为auto
     */
//    int num;
//    auto int num; // 等价于上面一句代码

    int num; // 存储在栈中
    register int value; // 存储到CPU的寄存器中
    return 0;
}
