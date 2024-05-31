#include <stdio.h>
#include <malloc.h>


int main()
{
    int* p1 = (int*)malloc(40);
    int* p2 = (int*)1234567;
    int i = 0;
    
    for(i=0; i<40; i++)
    {
        *(p1 + i) = 40 - i;
    }

    free(p1); 
    
    for(i=0; i<40; i++)
    {
        p1[i] = p2[i];
    }
    
    return 0;
}

