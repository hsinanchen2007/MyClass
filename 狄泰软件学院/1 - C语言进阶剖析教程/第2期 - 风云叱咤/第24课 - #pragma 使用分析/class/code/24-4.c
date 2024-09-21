#include <stdio.h>

#pragma pack(8)

struct S1
{
    short a;
    long b;
};

struct S2
{
    char c;
    struct S1 d;
    double e;
};

#pragma pack()

int main()
{
    printf("%d\n", sizeof(struct S1));  // 8
    printf("%d\n", sizeof(struct S2));  // 24

    return 0;
}
