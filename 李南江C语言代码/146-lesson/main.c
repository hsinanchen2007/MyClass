#include <stdio.h>
void test();
int num = 777;

// ȫ��������Ľṹ������
struct Person{
    char *name;
    int age;
};
int main()
{
    /*
     * 1.ʲô�Ǿֲ�����?
     * ������{}�еľ��Ǿֲ�����
     * �Ӷ������һ�п�ʼ, ֱ������}����, ��������returnΪֹ
     * 2.ʲô��ȫ�ֱ���?
     * ������{}����ľ���ȫ�ֱ���
     * �Ӷ������һ�п�ʼ, ֱ���ļ���ĩβ
     *
     * 3.�ṹ�����͵�������
     * �ṹ�������������Լ������, ����Ҳ�����������
     * �ṹ�����͵����������ͨ����һ��, Ҳ��Ϊ�ֲ��������ȫ��������
     */
//    {
//        int num = 666;
//        printf("num = %i\n", num);
//    }
//    printf("num = %i\n", num); // ����������

//    printf("num = %i\n", num);
//    test();

    /*
    {
    //  �ֲ�������Ľṹ������
        struct Person{
            char *name;
            int age;
        };
        struct Person p1;
    }
     struct Person p2; // ����������
     */

    struct Person p2;
    test();
    return 0;
}
void test(){
    printf("num = %i\n", num);
    struct Person p2;
}

