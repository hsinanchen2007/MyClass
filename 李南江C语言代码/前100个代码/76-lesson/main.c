#include <stdio.h>

// 1.��������һ�������������
// 2.ȷ���β��б�
// 3.��дҵ���߼�����
// 4.ȷ������ֵ�ͷ���ֵ����
int getMinus(int a, int b)
{
    int res = a - b;
    return res;
}

int main()
{
    // ����: Ҫ��������������Ĳ�
    int num1 = 20;
    int num2 = 10;
//    int value = num1 - num2;
    int value = getMinus(num1, num2);
    printf("value = %i\n", value);
    return 0;
}
