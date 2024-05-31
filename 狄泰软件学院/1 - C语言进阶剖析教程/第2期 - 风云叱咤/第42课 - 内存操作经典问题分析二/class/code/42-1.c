#include <stdio.h>
#include <malloc.h>

void test(int* p, int size)
{
    int i = 0;
    
    for(i=0; i<size; i++)
    {
        printf("%d\n", p[i]);
    }
    
    free(p);
}

void func(unsigned int size)
{
    int* p = (int*)malloc(size * sizeof(int));
    int i = 0;
    
    if( size % 2 != 0 )
    {
        return; 
    }
    
    for(i=0; i<size; i++)
    {
        p[i] = i;
        printf("%d\n", p[i]);
    }
    
    free(p);
}

int main()
{
    int* p = (int*)malloc(5 * sizeof(int));
    
    test(p, 5);
    
    free(p); 
    
    func(9);
    func(10);
       
    return 0;
}

