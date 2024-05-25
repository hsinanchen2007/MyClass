#include <stdio.h>

int main()
{
    int var = 0;
    int another = 0;
    int* pVar = NULL;

    printf("1. var = %d\n", var);
    printf("1. pVar = %p\n", pVar);

    pVar = &var;  // 使用指针保存变量的地址

    *pVar = 100;  // *pVar 等价于 var ， var = 100;

    printf("2. var = %d\n", var);
    printf("2. pVar = %p\n", pVar);

    pVar = &another;  // 改变了 pVar 的指向，使得 pVar 保存 another 的地址

    *pVar = 1000;     // another = 1000;

    printf("3. another = %d\n", another);
    printf("3. pVar = %p\n", pVar);

    printf("4. add ==> %d\n", var + another + *pVar);   // 100 + 1000 + 1000  ==> 2100

    return 0;
}
