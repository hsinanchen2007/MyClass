#include <stdio.h>

int main()
{
    /*
     * 1.�ṹ���Ƕ�׶���
     * �ṹ�����������һ���ṹ��, ���Ǿͳ�֮Ϊ�ṹ���Ƕ�׶���
     */
    struct Date{
        int year;
        int month;
        int day;
    };
    struct Person{
        char *name;
        int age;

        // ��������
//        int year;
//        int month;
//        int day;
        struct Date birthday;

//        // ��������
//        int year;
//        int month;
//        int day;

//        // ��ѧ����
//        int year;
//        int month;
//        int day;

//        // ��ҵ����
//        int year;
//        int month;
//        int day;

//        // ��������
//        int year;
//        int month;
//        int day;

//        // �������
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
