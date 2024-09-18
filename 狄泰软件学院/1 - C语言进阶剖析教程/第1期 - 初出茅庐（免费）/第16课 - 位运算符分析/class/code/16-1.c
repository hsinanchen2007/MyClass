#include <stdio.h>

int main()
{
    printf("%d\n", 3 << 2);         // 12
    printf("%d\n", 3 >> 1);         // 1
    printf("%d\n", -1 >> 1);        // -1

    // bit operation has lower priority than +, -, *, /
    // so below code is actually like: 0x01 << (+-*/ operator)
    printf("%d\n", 0x01 << 2);      // 4
    printf("%d\n", 0x01 << 2 + 1);  // 8
    printf("%d\n", 0x01 << 2 + 2);  // 16
    printf("%d\n", 0x01 << 2 + 3);  // 32
    
    // left hand side should be a positive number [0 - 31]
    printf("%d\n", 3 << -1); // oops!   
    
    return 0;
}
