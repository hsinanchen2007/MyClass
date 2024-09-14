#include <stdio.h>

int main()
{
    char c = 'a';
    
    int i = c;    // safe
    
    unsigned int j = 0x11223344;
    
    short s = j;  // unsafe
    
    printf("c = %c\n", c);                          // c = a
    printf("i = %d\n", i);                          // i = 97
    printf("j = %x\n", j);                          // j = 11223344
    printf("s = %x\n", s);                          // s = 3344
    printf("sizeof(c + s) = %d\n", sizeof(c + s));  // sizeof(c + s) = 4
    
    return 0;
}
