#include <stdio.h>

int main()
{
    /*
     * ��ֵ�����
     * 1.�򵥵ĸ�ֵ�����
     * =
     * 2.���ӵĸ�ֵ�����
     * += -= *= /= %=
     *
     * �����: �ҽ����
     * ע���: ��ֵ����������ȼ�Ҫ�������������
     */
    /*
    // 1.�򵥵ĸ�ֵ�����
    // ����: ���Ⱥ��ұߵ�ֵ�ŵ��Ⱥ���߱�����Ӧ�Ĵ洢�ռ���
    int num;
    num = 666;
    printf("num = %i\n", num);

    // 2.���ӵĸ�ֵ�����
    // ����: ���Ⱥ���ߵ�ֵȡ�����͵Ⱥ��ұߵ�ֵ����, ����֮���ٰѼ���Ľ����ֵ���Ⱥŵ����
    int value = 5;
//    value += 10; // �൱�� value = value + 10
    value -= 10; // �൱�� value = value - 10
    printf("value = %i\n", value);
    */

//    int num;
//    num = 2 + 2;
//    printf("num = %i\n", num); // 4

    int value = 5;
    value += 2 + 2; // value += (2 + 2);  value = value + (2 + 2); value = 5 + (4)
    printf("value = %i\n", value);
    return 0;
}
