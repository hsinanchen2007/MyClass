#include <stdio.h>

int var = 100;  // ȫ�ֱ���

void f(int var) // var <==> �ֲ�����, pass by value
{
    var++;

    printf("var = %d\n", var);
}

void f2(int *var2) // var <==> �ֲ�����, pass by pointer
{
    // below statement is tricky, needed to use "" like (*var2) first, then ++
    // otherwise its value won't be set properly
    (*var2)++;

    printf("var = %d\n", *var2);
}

int main()
{
    int var = 10;  // �ֲ�����

    f(var);                     // f(10);

    printf("var = %d\n", var);  // var = 10;

    f2(&var);

    printf("var = %d\n", var);  // var = 11;

    return 0;
}
