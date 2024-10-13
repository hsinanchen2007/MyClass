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
        // ERROR!!! when size is odd, p is not freed, will cause memory leak
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

    // ERROR!!! p is freed inside test(), here double free will cause memory corruption
    // 最好是在同一个函数中malloc/free
    free(p); 
    
    func(9);
    func(10);
       
    return 0;
}

