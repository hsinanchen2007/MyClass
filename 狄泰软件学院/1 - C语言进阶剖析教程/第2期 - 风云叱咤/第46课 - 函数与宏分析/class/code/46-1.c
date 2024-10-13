#include <stdio.h>

#define RESET(p, len)          \
    while( len > 0 )           \
        ((char*)p)[--len] = 0

void reset(void* p, int len)
{
    while( len > 0 ) 
        ((char*)p)[--len] = 0;
}

int main()
{
    int array[] = {1, 2, 3, 4, 5};
    int len = sizeof(array);
    int i = 0;
    
    // below two are same, no problem
    // RESET(array, len);
    // reset(array, len);

    // ERROR!!! but by using macro, it will compile but cause error
    // RESET(6, len);

    // but by using function, it will cause compile error
    // reset(6, len);

    for(i=0; i<5; i++)
    {
        printf("array[%d] = %d\n", i, array[i]);
    }
    
    return 0;
}

