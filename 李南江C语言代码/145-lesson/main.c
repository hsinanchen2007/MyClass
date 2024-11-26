#include <stdio.h>

int main()
{
    /*
     * 1.结构体变量的初始化方式
     * 1.1先定义再初始化
     * 1.2定义的同时初始化
     */
    // 1先定义再初始化
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

    // 2定义的同时初始化
    /*
    // 注意点:
    // 1.初始化的值必须和数据类型中定义的顺序一致
    // 2.结构体变量和数组一样, 也支持指定属性初始化
    // 1.定义结构体类型
    struct Person{
        char *name;
        int age;
        float score;
    };
    // 2.定义结构体变量
//    struct Person per = {"lnj", 13, 59.5};
//    struct Person per = {13, 59.5, "lnj"};
    struct Person per = {.age = 13, .score = 59.5, .name = "lnj"};
    printf("name = %s\n", per.name);
    printf("age = %i\n", per.age);
    printf("score = %f\n", per.score);
    */

    // 过去学习数组的时候, 不能先定义再一次性初始化
//    int ages[3] = {1, 3, 5};
//    int ages[3];
//    ages = {1, 3, 5};
    // 结构体变量支持先定义再一次性初始化, 但是需要强制类型转换
    struct Person{
        char *name;
        int age;
        float score;
    };
    struct Person per;
    per = (struct Person){"lnj", 13, 59.5};
    printf("name = %s\n", per.name);
    printf("age = %i\n", per.age);
    printf("score = %f\n", per.score);
    return 0;
}

