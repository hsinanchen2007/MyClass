#include <stdio.h>
#include <string.h>

struct Bits1
{
    int a   : 16;
    short b : 8;
    char c  : 8;
    float f;     // float f : 32;   ==> �����ͳ�Ա����ָ��λ���
};

struct Bits2
{
    unsigned char a : 6;
    unsigned char b : 6;
    unsigned char c : 6;
    // unsigned char d : 9;    ==> ָ����λ��Ȳ��ܴ����������͵�λ���
};

struct Bits3
{
    unsigned char a : 4;
    unsigned char   : 0;  // ����һ���洢��Ԫ��ʾ�µĳ�Ա
    unsigned char b : 4;
};

int main()
{
    printf("sizeof(Bits1) = %d\n", sizeof(struct Bits1));
    printf("sizeof(Bits2) = %d\n", sizeof(struct Bits2));
    printf("sizeof(Bits3) = %d\n", sizeof(struct Bits3));

    return 0;
}

