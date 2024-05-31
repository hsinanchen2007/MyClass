#include <stdio.h>

int main()
{
    float f = 8.25;
    
    unsigned int* p = (unsigned int*)&f;
    
    printf("0x%08X\n", *p);
    
    return 0;
}
