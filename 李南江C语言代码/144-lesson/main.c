#include <stdio.h>

int main()
{
    /*
     * 1.定义结构体变量的多种格式
     * 1.1先定义结构体类型, 再定义结构体变量
     * 1.2定义结构体类型的同时定义结构体变量
     * 1.3定义结构体类型的同时定义结构体变量, 并且省略结构体类型的名称
     */

    // 先定义结构体类型, 再定义结构体变量
    /*
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
    */
    // 定义结构体类型的同时定义结构体变量
    /*
    struct Person{
        char *name;
        int age;
        float score;
    } per;
    // 3.使用结构体变量
    // 3.1往结构体变量中存储数据
    per.name = "lnj";
    per.age = 13;
    per.score = 59.5;
    // 3.2从结构体变量中获取存储的数据
    printf("name = %s\n", per.name);
    printf("age = %i\n", per.age);
    printf("score = %f\n", per.score);
    */

    // 定义结构体类型的同时定义结构体变量, 并且省略结构体类型的名称
    /*
    struct{
        char *name;
        int age;
        float score;
    } per;
    // 3.使用结构体变量
    // 3.1往结构体变量中存储数据
    per.name = "lnj";
    per.age = 13;
    per.score = 59.5;
    // 3.2从结构体变量中获取存储的数据
    printf("name = %s\n", per.name);
    printf("age = %i\n", per.age);
    printf("score = %f\n", per.score);
    */

    // 定义变量的格式  数据类型名称 变量名称;  int num;
    struct Person p1;
    struct Person p2;
    struct Person p3;
    struct Person p4;
    return 0;
}
