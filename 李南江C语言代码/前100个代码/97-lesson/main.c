#include <stdio.h>

int main()
{
    // ����: ��������������ֵ
    int a = 10;
    int b = 20;
    printf("a = %i, b = %i\n", a, b);
    // ��һ�ַ�ʽ: ������ʱ����
//    int temp;
//    temp = a; // temp = 10;
//    a = b; // a = 20;
//    b = temp; // b = 10;

    // �ڶ��ַ�ʽ: �������������
//    a = a + b; // a = 10 + 20; a = 30;
//    b = a - b; // b = 30 - 20; b = 10;
//    a = a - b; // a = 30 - 10; a = 20;

    // �����ַ�ʽ: ����λ�����
    a = a ^ b;
    b = a ^ b; //  b = a ^ b ^ b;
    a = a ^ b; //  a = a ^ a ^ b;
    printf("a = %i, b = %i\n", a, b);
    return 0;
}
