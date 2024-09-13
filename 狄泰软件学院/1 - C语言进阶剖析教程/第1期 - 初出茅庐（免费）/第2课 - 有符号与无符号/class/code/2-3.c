#include <stdio.h>

int main()
{
 
    unsigned int i = 0;
    
    // for unsigned int value, min value is 0
    // but in below for loop, when i is -1, 
    // the value will become a big number
    for(i=9; i>=0; i--)
    {
        printf("i = %u\n", i);
    }
    
    return 0;
}
