#include <stdio.h>
void change(int value);
void change2(int values[3]);
int main()
{
    /*
     * 1.������Ϊ�����Ĳ���
     * ��������Ϊ�����Ĳ���, �ں������޸��β�, ��Ӱ�쵽����ʵ��
     *
     * 2.��������������Ϊ�����Ĳ���
     * char int float double
     * �ں������޸��β�, ����Ӱ�쵽����ʵ��
     */
//    int num = 123;
//    printf("num = %i\n", num);
//    change(num);
//    printf("num = %i\n", num);

    int ages[3] = {1, 3, 5};
    printf("ages[1] = %i\n", ages[1]);
    // ��������������ľ�������ĵ�ַ
    // ���������� == &������ == &������[0]
    // ��������ط��൱�ڰ�����ĵ�ַ���ݸ����β�
    change2(ages);
    printf("ages[1] = %i\n", ages[1]);

//    printf("ages = %p\n", ages);
//    printf("&ages = %p\n", &ages);
//    printf("&ages[0] = %p\n", &ages[0]);
    return 0;
}
void change2(int values[3]){
    values[1] = 666;
}
void change(int value){
    value = 666;
}
