#include <stdio.h>

int main()
{
    /*
     * 1.结构体的嵌套定义
     * 结构体的属性又是一个结构体, 我们就称之为结构体的嵌套定义
     */
    struct Date{
        int year;
        int month;
        int day;
    };
    struct Person{
        char *name;
        int age;

        // 出生日期
//        int year;
//        int month;
//        int day;
        struct Date birthday;

//        // 死亡日期
//        int year;
//        int month;
//        int day;

//        // 入学日期
//        int year;
//        int month;
//        int day;

//        // 毕业日期
//        int year;
//        int month;
//        int day;

//        // 工作日期
//        int year;
//        int month;
//        int day;

//        // 结婚日期
//        int year;
//        int month;
//        int day;
    };

    struct Person p = {"lnj", 13, {2020, 11, 11}};
    printf("name = %s\n", p.name);
    printf("age = %i\n", p.age);
    printf("year = %i\n", p.birthday.year);
    printf("month = %i\n", p.birthday.month);
    printf("day = %i\n", p.birthday.day);
    return 0;
}
