#include <stdio.h>

int main()
{
    int a = 1;
    int b = 2;
    int c = 0;
    
    c = a < b ? a : b;
    
    // 三目运算符返回的是一个值，而不是一个变量
    // (a < b ? a : b) = 3;
    
    printf("%d\n", a);  // 1
    printf("%d\n", b);  // 2
    printf("%d\n", c);  // 1
    
    return 0;
}
 