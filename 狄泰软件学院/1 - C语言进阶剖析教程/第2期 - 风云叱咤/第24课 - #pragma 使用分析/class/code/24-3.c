#include <stdio.h>

#pragma pack(2)
struct Test1
{
    char  c1;
    short s;
    char  c2;
    int   i; 
};
#pragma pack()

#pragma pack(4)
struct Test2
{
    char  c1;
    char  c2;
    short s;
    int   i;
};
#pragma pack()

int main()
{
    printf("sizeof(Test1) = %d\n", sizeof(struct Test1));   //  sizeof(Test1) = 12
    printf("sizeof(Test2) = %d\n", sizeof(struct Test2));   //  sizeof(Test2) = 8

    return 0;
}
