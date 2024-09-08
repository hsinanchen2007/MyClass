#include <stdio.h>

int main()
{
    int a = 0;
    int b = 10;

    a = b = b + 1; // a=>11  b=>11

    printf("a = %d, b = %d\n", a, b);   // a = 11, b = 11

    a += 1;
    a -= 2;
    a *= 3;
    a /= 4;

    // a => 7

    printf("a = %d\n", a);              // a = 7

    /*
        ���ϸ�ֵ��������ֵ����
    */
    a += b -= 1;

    printf("a = %d, b = %d\n", a, b);   // a = 17, b = 10

    return 0;
}
