#include <stdio.h>

int main()
{
    int a[5] = {0};
    int* p = NULL;
    
    printf("a = 0x%X\n", (unsigned int)(a));            // a = 0xBFF734
    printf("a + 1 = 0x%X\n", (unsigned int)(a + 1));    // a + 1 = 0xBFF738
    
    printf("p = 0x%X\n", (unsigned int)(p));            // p = 0x0
    printf("p + 1 = 0x%X\n", (unsigned int)(p + 1));    // p + 1 = 0x4
    
    return 0;
}
