#include <stdio.h>

int swap(int* a, int* b)
{
    int c = *a;
    
    *a = *b;
    
    *b = c;
}

int main()
{
    int aa = 1;
    int bb = 2;
    
    printf("aa = %d, bb = %d\n", aa, bb);
    
    swap(&aa, &bb);
    
    printf("aa = %d, bb = %d\n", aa, bb);
    
    return 0;
}
