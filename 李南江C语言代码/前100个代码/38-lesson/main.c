#include <stdio.h>

int main()
{
    /*
     * ����������a��b, a = 10, b = 20; Ҫ�������ַ�ʽ�������������б����ֵ
     * ����ǰ: a = 10, b = 20; ������ a = 20, b = 10;
     */
    int a = 10;
    int b = 20;
    printf("����ǰ: a = %i, b = %i\n", a, b);
    // 1.������ʱ����, ���ڴ洢��ʱ����
    int temp;
    // 2.��a�����ֵ��temp
    temp = a;
    // 3.��b��ֵ��a
    a = b;
    // 4.��temp��ֵ��b
    b = temp;
    printf("������: a = %i, b = %i\n", a, b);
    return 0;
}
