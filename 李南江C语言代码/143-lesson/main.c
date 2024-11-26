#include <stdio.h>

int main()
{
    /*
     * 1.什么是结构体?
     * 结构体和数组很像, 都是用于存储一组数据的
     * 数组是专门用于存储一组相同类型数据的
     * 结构体是专门用于存储一组不同类型数据的
     *
     * 2.如何定义结构体变量
     * 2.1定义结构体类型
     * 2.2定义结构体变量
     *
     * 3.如何定义结构体类型
     * struct 结构体类型名称{
     *   数据类型 属性名称;
     *   数据类型 属性名称;
     *   ... ....
     * };
     *
     * 4.如何通过结构体类型定义结构体变量
     * struct 结构体类型名称 结构体变量名称;
     *
     * 5.如何使用结构体变量
     * 结构体变量名称.结构体属性名称;
     */

    // 1.定义结构体类型
    struct Person{
        char *name;
        int age;
        float score;
    };
    // 2.定义结构体变量
    struct Person per;
    // 3.使用结构体变量
    // 3.1往结构体变量中存储数据
    per.name = "lnj";
    per.age = 13;
    per.score = 59.5;
    // 3.2从结构体变量中获取存储的数据
    printf("name = %s\n", per.name);
    printf("age = %i\n", per.age);
    printf("score = %f\n", per.score);

    return 0;
}
