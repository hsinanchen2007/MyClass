#include <stdio.h>

int var = 100;  // ȫ�ֱ���

void f(int var) // var <==> �ֲ�����
{
    var++;

    printf("var = %d\n", var);
}

int main()
{
    int var = 10;  // �ֲ�����

    f(var);  // f(10);

    printf("var = %d\n", var);  // var = 10;

    return 0;
}
