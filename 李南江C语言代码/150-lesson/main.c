#include <stdio.h>
struct Person{
    char *name;
    int age;
};
void change(struct Person p);
int main()
{
    /*
     * 1.结构体作为函数的参数
     * 结构体变量作为函数的参数传递, 在函数中修改形参不会影响到外界实参
     * 只有地址传递在函数中修改形参才会影响到外界的实参
     * 和数组名不同的是, 数组名保存了数组的地址, 但是结构体变量名没有保存结构体变量的地址
     */
    struct Person per = {"lnj", 13};
    printf("age = %i\n", per.age);
    change(per);
    printf("age = %i\n", per.age);
    return 0;
}
void change(struct Person p){
    p.age = 666;
}
