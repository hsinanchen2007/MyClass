#include <stdio.h>

int main()
{
    /*
     * 1.�ṹ������ĳ�ʼ����ʽ
     * 1.1�ȶ����ٳ�ʼ��
     * 1.2�����ͬʱ��ʼ��
     */
    // 1�ȶ����ٳ�ʼ��
    /*
    // 1.����ṹ������
    struct Person{
        char *name;
        int age;
        float score;
    };
    // 2.����ṹ�����
    struct Person per;
    // 3.ʹ�ýṹ�����
    // 3.1���ṹ������д洢����
    per.name = "lnj";
    per.age = 13;
    per.score = 59.5;
    // 3.2�ӽṹ������л�ȡ�洢������
    printf("name = %s\n", per.name);
    printf("age = %i\n", per.age);
    printf("score = %f\n", per.score);
    */

    // 2�����ͬʱ��ʼ��
    /*
    // ע���:
    // 1.��ʼ����ֵ��������������ж����˳��һ��
    // 2.�ṹ�����������һ��, Ҳ֧��ָ�����Գ�ʼ��
    // 1.����ṹ������
    struct Person{
        char *name;
        int age;
        float score;
    };
    // 2.����ṹ�����
//    struct Person per = {"lnj", 13, 59.5};
//    struct Person per = {13, 59.5, "lnj"};
    struct Person per = {.age = 13, .score = 59.5, .name = "lnj"};
    printf("name = %s\n", per.name);
    printf("age = %i\n", per.age);
    printf("score = %f\n", per.score);
    */

    // ��ȥѧϰ�����ʱ��, �����ȶ�����һ���Գ�ʼ��
//    int ages[3] = {1, 3, 5};
//    int ages[3];
//    ages = {1, 3, 5};
    // �ṹ�����֧���ȶ�����һ���Գ�ʼ��, ������Ҫǿ������ת��
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

