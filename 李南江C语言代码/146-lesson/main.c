#include <stdio.h>
void test();
int num = 777;

// 全局作用域的结构体类型
struct Person{
    char *name;
    int age;
};
int main()
{
    /*
     * 1.什么是局部变量?
     * 定义在{}中的就是局部变量
     * 从定义的那一行开始, 直到遇到}结束, 或者遇到return为止
     * 2.什么是全局变量?
     * 定义在{}外面的就是全局变量
     * 从定义的那一行开始, 直到文件的末尾
     *
     * 3.结构体类型的作用域
     * 结构体类型是我们自己定义的, 所以也有作用域概念
     * 结构体类型的作用域和普通变量一样, 也分为局部作用域和全局作用域
     */
//    {
//        int num = 666;
//        printf("num = %i\n", num);
//    }
//    printf("num = %i\n", num); // 超出作用域

//    printf("num = %i\n", num);
//    test();

    /*
    {
    //  局部作用域的结构体类型
        struct Person{
            char *name;
            int age;
        };
        struct Person p1;
    }
     struct Person p2; // 超出作用域
     */

    struct Person p2;
    test();
    return 0;
}
void test(){
    printf("num = %i\n", num);
    struct Person p2;
}

