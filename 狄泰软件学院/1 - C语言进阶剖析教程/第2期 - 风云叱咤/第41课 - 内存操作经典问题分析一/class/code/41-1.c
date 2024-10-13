#include <stdio.h>
#include <malloc.h>


int main()
{
    // ERROR!!! 40 means "sizeof(int) * 10 = 4 * 10 = 40"
    // but below for loop is 40, will cause buffer overflow
    int* p1 = (int*)malloc(40);

    // ERROR!!! 1234567 is not a valid address, will cause segmentation fault
    int* p2 = (int*)1234567;

    int i = 0;
    
    for(i=0; i<40; i++)
    {
        *(p1 + i) = 40 - i;
    }

    // ERROR!!! p1 is freed, but still used in below for loop
    // p1 is still not NULL, 野指針
    free(p1); 
    
    for(i=0; i<40; i++)
    {
        p1[i] = p2[i];
    }
    
    // ERROR!!! p2 is not freed, will cause memory leak

    return 0;
}

