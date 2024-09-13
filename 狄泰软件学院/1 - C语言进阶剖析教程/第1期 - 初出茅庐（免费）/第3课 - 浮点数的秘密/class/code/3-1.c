#include <stdio.h>

int main()
{
    float f = 8.25;
    
    unsigned int* p = (unsigned int*)&f;
    
    printf("0x%08X\n", *p);                             // 0x41040000
    
    printf("sizeof(float) = %d\n", sizeof(float));      // sizeof(float) = 4
    printf("sizeof(double) = %d\n", sizeof(double));    // sizeof(double) = 8

    return 0;
}
