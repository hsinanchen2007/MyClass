#include <stdio.h>

int main()
{   
    char c = 0;
    short s = 0;
    int i = 0;
    double d = 0;
    char* p = "str";
        
    printf( "%d\n", sizeof(c ? c : s) );    // 4
    printf( "%d\n", sizeof(i ? i : d) );    // 8

    // 三目运算符返回的是一个值，其类型是两个操作数的公共类型
    // here d and p are different types, so the compiler will report an error
    // printf( "%d\n", sizeof(d ? d : p) );

    return 0;
}
