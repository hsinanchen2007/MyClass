#include <stdio.h>

int main()
{
    /*
     * 1.����ṹ������Ķ��ָ�ʽ
     * 1.1�ȶ���ṹ������, �ٶ���ṹ�����
     * 1.2����ṹ�����͵�ͬʱ����ṹ�����
     * 1.3����ṹ�����͵�ͬʱ����ṹ�����, ����ʡ�Խṹ�����͵�����
     */

    // �ȶ���ṹ������, �ٶ���ṹ�����
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
    // ����ṹ�����͵�ͬʱ����ṹ�����
    /*
    struct Person{
        char *name;
        int age;
        float score;
    } per;
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

    // ����ṹ�����͵�ͬʱ����ṹ�����, ����ʡ�Խṹ�����͵�����
    /*
    struct{
        char *name;
        int age;
        float score;
    } per;
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

    // ��������ĸ�ʽ  ������������ ��������;  int num;
    struct Person p1;
    struct Person p2;
    struct Person p3;
    struct Person p4;
    return 0;
}
