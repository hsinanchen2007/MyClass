#include <stdio.h>
#include <string.h>

struct BW
{
    // the ": number" defines the size of variable
    // by default it is byte in struct, but user
    // can specify the size of variable in struct
    unsigned char a : 4;
    unsigned char b : 2;
    unsigned char c : 2;
};

int main()
{
    struct BW bw = {0};

    bw.a = 10;
    bw.b = 4;   // 4 大于 b 能表示的最大值，因此赋值后 b 回转到 0
    bw.c = 3;

    printf("sizeof(struct BW) = %d\n", sizeof(struct BW));      // sizeof(struct BW) = 1, not it is not 3 bytes anymore
    printf("bw.a = %d\n", bw.a);                                // bw.a = 10
    printf("bw.b = %d\n", bw.b);                                // bw.b = 0
    printf("bw.c = %d\n", bw.c);                                // bw.c = 3

    return 0;
}

