#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

int mul(int a, int b)
{
    return a * b;
}

int calculate(int a[], int len, int(*cal)(int, int))
{
    int ret = a[0];
    int i = 0;

    for(i=1; i<len; i++)
    {
        ret = cal(ret, a[i]);
    }

    return ret;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int (*pFunc) (int, int) = NULL;

    pFunc = add;

    printf("%d\n", pFunc(1, 2));        // 3
    printf("%d\n", (*pFunc)(3, 4));     // 7    

    pFunc = &mul;

    printf("%d\n", pFunc(5, 6));        // 30
    printf("%d\n", (*pFunc)(7, 8));     // 56

    printf("1 + ... + 5 = %d\n", calculate(a, 5, add));     // 1 + ... + 5 = 15
    printf("1 * ... * 5 = %d\n", calculate(a, 5, mul));     // 1 * ... * 5 = 120

    return 0;
}
