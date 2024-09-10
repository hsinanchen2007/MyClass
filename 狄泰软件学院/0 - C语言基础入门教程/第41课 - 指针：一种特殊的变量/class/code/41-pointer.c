#include <stdio.h>

int main()
{
    int var = 0;
    int another = 0;
    int* pVar = NULL;

    printf("1. var = %d\n", var);               // 1. var = 0
    printf("1. pVar = %p\n", pVar);             // 1. pVar = 00000000

    pVar = &var;  // ʹ��ָ�뱣������ĵ�ַ

    *pVar = 100;  // *pVar �ȼ��� var �� var = 100;

    printf("2. var = %d\n", var);               // 2. var = 100
    printf("2. pVar = %p\n", pVar);             // 2. pVar = 00CFFBA4

    pVar = &another;  // �ı��� pVar ��ָ��ʹ�� pVar ���� another �ĵ�ַ

    *pVar = 1000;     // another = 1000;

    printf("3. another = %d\n", another);       // 3. another = 1000
    printf("3. pVar = %p\n", pVar);             // 3. pVar = 00CFFBA0

    printf("4. add ==> %d\n", var + another + *pVar);   // 100 + 1000 + 1000  ==> 2100, 4. add ==> 2100

    return 0;
}
