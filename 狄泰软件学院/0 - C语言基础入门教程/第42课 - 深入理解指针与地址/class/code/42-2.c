#include <stdio.h>

void func(int* p)
{
    *p = 100;   // �޸��ڴ��� 4 �ֽڵ����ݣ������޸�һ�����ͱ�����ֵ
}

void swap(int* pa, int* pb)
{
    int t = 0;

    t = *pa;
    *pa = *pb;
    *pb = t;
}

int main()
{
    int var = 0;
    int a = 1, b = 2;

    printf("1. var = %d\n", var);

    func( &var );

    printf("2. var = %d\n", var);

    printf("3. a = %d, b = %d\n", a, b);

    swap(&a, &b);

    printf("4. a = %d, b = %d\n", a, b);

    return 0;
}
