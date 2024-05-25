#include <stdio.h>

void func(int* p)
{
    *p = 100;   // 修改内存中 4 字节的数据，即：修改一个整型变量的值
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
