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

    /* void* 指针可以保存任意类型的地址 */
    p = &c;
    p = &i;
    p = &f;
    p = &d;

    printf("%p\n", p);

    // void* 类型的指针无法访问内存中的数据
    // printf("%f\n", *p);

    /* void* 类型的变量可以直接合法的赋值给其他具体数据类型的指针变量 */
    pd = p;
    pi = p;

    // void* 是例外，其他指针类型的变量不能相互赋值
    // pd = pi;

    return 0;
}
