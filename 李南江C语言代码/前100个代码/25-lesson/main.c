#include <stdio.h>

int main()
{
    /*
     * �����Լ������д�ڱ���ǰ��ͺ��������
     * 1.��������Լ������д�ڱ����ĺ���, ��ô���Ȳ�����������, Ȼ���������Լ�
     * 2.��������Լ������д�ڱ�����ǰ��, ��ô���������Լ�Ȼ���ٲ�������������
     */

    int num = 5;
    // ����д�ڱ����ĺ���
    // ��ô���Ȳ�����������, Ȼ��������
    // �൱��: int value = 5 + num; num++;
//    int value = 5 + num++;
//    printf("value = %i\n", value); // 10
//    printf("num = %i\n", num); // 6

    // ����д�ڱ�����ǰ��
    // ��ô��������Ȼ���ٲ�������������
    // ++num; int value = 5 + num;
//    int value = 5 + ++num;
//    printf("value = %i\n", value); // 11
//    printf("num = %i\n", num); // 6

    // �Լ��ڱ����ĺ���
    // ��ô���Ȳ�����������, Ȼ�����Լ�
    // int value = 5 + num; num--;
//    int value = 5 + num--;
//    printf("value = %i\n", value); // 10
//    printf("num = %i\n", num); // 4

    // �Լ��ڱ�����ǰ��
    //  ��ô�����Լ�Ȼ���ٲ�������������
    //   num--; int value = 5 + num;
    int value = 5 + --num;
    printf("value = %i\n", value); // 9
    printf("num = %i\n", num); // 4
    return 0;
}
