#include <stdio.h>

int system_mode()
{
    // union is a special struct, all members share the same memory space
    // while i is largest one, it will use 4 bypes in this case
    // c is the smallest one, it will use 1 byte in this case
    union SM
    {
        int i;
        char c;
    };

    union SM sm;
    
    sm.i = 1;
    
    // return the first byte of sm, is 1, 小端模式
    return sm.c;
}


int main()
{
    printf("System Mode: %d\n", system_mode()); // System Mode: 1
    return 0;
}
