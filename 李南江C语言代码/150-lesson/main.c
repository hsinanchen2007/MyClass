#include <stdio.h>
struct Person{
    char *name;
    int age;
};
void change(struct Person p);
int main()
{
    /*
     * 1.�ṹ����Ϊ�����Ĳ���
     * �ṹ�������Ϊ�����Ĳ�������, �ں������޸��ββ���Ӱ�쵽���ʵ��
     * ֻ�е�ַ�����ں������޸��ββŻ�Ӱ�쵽����ʵ��
     * ����������ͬ����, ����������������ĵ�ַ, ���ǽṹ�������û�б���ṹ������ĵ�ַ
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
