#include <stdio.h>

int main()
{
    /*
     * sizeof�����
     * ����: ��������ĳ����������ռ�õĴ洢�ռ��С
     *
     * ��ʽ:
     * sizeof(����/����/��������)
     * sizeof ����/����
     *
     * ע���:
     * 1.sizeof��һ�������, �����Ǻ���
     * 2.sizeof������һ�������, ����Ҳ�����ȼ�, sizeof����������ȼ��������������
     */
    // 1.����sizeof��������ָ�ʽ
    /*
    int res = sizeof(num);
    printf("res = %i\n", res);

    double value = 3.14;
    int res2 = sizeof value;
    printf("res2 = %i\n", res2);
    */
    // 2.����sizeof���㳣�������ָ�ʽ
    /*
    int res = sizeof(5);
    printf("res = %i\n", res);

    int res2 = sizeof 3.14;
    printf("res2 = %i\n", res2);
    */

    // 3.����sizeof�����������͵ĸ�ʽ
    /*
    int res = sizeof(char);
    printf("res = %i\n", res);

//    int res2 = sizeof int; // ����
//    printf("res2 = %i\n", res2);
    */

    // 4.sizeof������һ�������, ����Ҳ�����ȼ�, sizeof����������ȼ��������������
//    int res = sizeof(10) + 10; // 4 + 10
    int res = sizeof 10 + 10; // 4 + 10
    printf("res = %i\n", res); // 14
    return 0;
}
