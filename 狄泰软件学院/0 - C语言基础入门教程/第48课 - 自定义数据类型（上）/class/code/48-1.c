#include <stdio.h>
#include <string.h>

typedef  unsigned char  byte;

void func()
{
    typedef  byte  uint8;

    uint8 var = 200;
    byte  b   = var;   // 本质为相同类型变量之间的初始化

    printf("sizeof(uint8) = %d\n", sizeof(uint8));
    printf("var = %d\n", var);
    printf("b = %d\n", b);
}

int main()
{
    // uint8 var = 1;   // ERROR
    byte b = 128;

    func();

    printf("sizeof(byte) = %d\n", sizeof(byte));
    printf("b = %d\n", b);

    return 0;
}
