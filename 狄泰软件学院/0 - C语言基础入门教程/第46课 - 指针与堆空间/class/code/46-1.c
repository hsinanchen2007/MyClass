#include <stdio.h>

int main()
{
    char c = 0;
    int i = 0;
    float f = 2.0f;
    double d = 3.0;

    void* p = NULL;

    double* pd = NULL;
    int* pi = NULL;

    /* void* ָ����Ա����������͵ĵ�ַ */
    p = &c;
    p = &i;
    p = &f;
    p = &d;

    printf("%p\n", p);

    // void* ���͵�ָ���޷������ڴ��е�����
    // printf("%f\n", *p);

    /* void* ���͵ı�������ֱ�ӺϷ��ĸ�ֵ�����������������͵�ָ����� */
    pd = p;
    pi = p;

    // void* �����⣬����ָ�����͵ı��������໥��ֵ
    // pd = pi;

    return 0;
}
