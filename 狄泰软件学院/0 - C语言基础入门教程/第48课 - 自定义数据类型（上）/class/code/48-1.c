#include <stdio.h>
#include <string.h>

typedef  unsigned char  byte;

void func()
{
    typedef  byte  uint8;

    uint8 var = 200;
    byte  b   = var;   // ����Ϊ��ͬ���ͱ���֮��ĳ�ʼ��

    printf("sizeof(uint8) = %d\n", sizeof(uint8));      // sizeof(uint8) = 1
    printf("var = %d\n", var);                          // var = 200
    printf("b = %d\n", b);                              // b = 200
}

int main()
{
    // uint8 var = 1;   // ERROR
    byte b = 128;

    func();

    printf("sizeof(byte) = %d\n", sizeof(byte));        // sizeof(byte) = 1
    printf("b = %d\n", b);                              // b = 128

    return 0;
}
