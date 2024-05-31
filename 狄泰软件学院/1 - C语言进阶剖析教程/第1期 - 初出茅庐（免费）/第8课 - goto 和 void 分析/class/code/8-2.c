#include <stdio.h>

void MemSet(void* src, int length, unsigned char n)
{
    unsigned char* p = (unsigned char*)src;
    
    int i = 0;
    
    for(i=0; i<length; i++)
    {
        p[i] = n;
    }
}

int main()
{
    int a[5];
    int i = 0;
    
    MemSet(a, sizeof(a), 0);
    
    for(i=0; i<5; i++)
    {
        printf("%d\n", a[i]);
    }
    
    return 0;
}
