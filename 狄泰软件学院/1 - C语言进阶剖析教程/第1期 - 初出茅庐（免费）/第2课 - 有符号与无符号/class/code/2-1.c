#include <stdio.h>

int main()
{
    char c = -5;
    short s = 6;
    int i = -7;
    
    printf("%d\n", 0x80);                           // 128 = 16 * 8
    printf("%d\n", 0x8000);                         // 32768 = 16 * 16 * 16 * 8
    printf("%d\n", 0x80000000);                     // -2147483648 

    printf("%d\n", ( (c & 0x80) != 0 ));            // 1
    printf("%d\n", ( (s & 0x8000) != 0 ));          // 0
    printf("%d\n", ( (i & 0x80000000) != 0 ));      // 1
    
    return 0;
}
