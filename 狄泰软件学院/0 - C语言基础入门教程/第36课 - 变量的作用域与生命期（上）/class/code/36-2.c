#include <stdio.h>

int var = 100;  // ȫ�ֱ���

int main()
{
    int var = 10;  // �ֲ�����

    {
        int var = 1;  // �ֲ�����

        printf("var = %d\n", var);
    }

    printf("var = %d\n", var);  // var = 10;

    return 0;
}
