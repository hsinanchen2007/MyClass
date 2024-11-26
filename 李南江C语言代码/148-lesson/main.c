#include <stdio.h>

int main()
{
    /*
     * 1.指向结构体的指针
     * 结构体变量也是一个变量, 也会分配存储空间, 也有自己的地址, 所以也可以利用指针保存它的地址
     *
     * 2.如何定义一个指向结构体的指针
     * 和定义普通的指针变量一样, 分为三步
     * 1.将变量的定义拷贝过来
     * 2.在数据类型和变量名称的中间加上一颗星
     * 3.修改变量名称
     *
     * 3.当指针指向结构体变量之后如何利用指针变量访问结构体变量
     * 结构体变量名称.属性名称
     * (*指针变量名称).属性名称
     * 指针变量名称->属性名称
     */
    struct Person{
        char *name;
        int age;
    };
    struct Person per = {"lnj", 13};

    struct Person *p;
    p = &per;
    // 注意点:
    // 和数组不同的是, 数组名保存的就是数组的地址, 但是结构体变量名并没有保存结构体变量的地址
//    printf("&per = %p\n", &per);
//    printf("p = %p\n", p);
//    printf("per = %p\n", per);
    printf("name = %s\n", per.name);
    printf("name = %s\n", (*p).name);
    printf("name = %s\n", p->name);
    return 0;
}
