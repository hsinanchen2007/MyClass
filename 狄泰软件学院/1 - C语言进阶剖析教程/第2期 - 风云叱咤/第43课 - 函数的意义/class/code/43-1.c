#include <stdio.h>
#include <malloc.h>

extern int g_var;

extern struct Test;

int main()
{
    extern void f(int i, int j);
    extern int g(int x);
    
    struct Test* p = NULL; // (struct Test*)malloc(sizeof(struct Test));
    
    printf("p = %p\n", p);
    
    //g_var = 10;
    
    printf("g_var = %d\n", g_var);
    
    f(1, 2);
    
    printf("g(3) = %d\n", g(3));
    
    free(p);
    
    return 0;
}
