#include <stdio.h>
#include <string.h>

struct Bits1
{
    int a   : 16;
    short b : 8;
    char c  : 8;
    float f;     // float f : 32;   ==> 浮点型成员不能指点位宽度
};

struct Bits2
{
    unsigned char a : 6;
    unsigned char b : 6;
    unsigned char c : 6;
    // unsigned char d : 9;    ==> 指定的位宽度不能大于声明类型的位宽度
};

struct Bits3
{
    unsigned char a : 4;
    unsigned char   : 0;  // 重启一个存储单元表示新的成员
    unsigned char b : 4;
};

int main()
{
    printf("sizeof(Bits1) = %d\n", sizeof(struct Bits1));
    printf("sizeof(Bits2) = %d\n", sizeof(struct Bits2));
    printf("sizeof(Bits3) = %d\n", sizeof(struct Bits3));

    return 0;
}

