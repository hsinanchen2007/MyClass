#include <stdio.h>
#include <malloc.h>

// global variable defined in another C file
extern int g_var;

// function defined in another C file
extern struct Test;

int main()
{
    extern void f(int i, int j);
    extern int g(int x);
    
    // 若是換成(struct Test*)malloc(sizeof(struct Test)), compiler無法知道
    // struct test, 因為在此它只有extern struct Test的聲明, 沒有定義
    struct Test* p = NULL; // (struct Test*)malloc(sizeof(struct Test));
    
    printf("p = %p\n", p);
    
    //g_var = 10;
    
    printf("g_var = %d\n", g_var);
    
    f(1, 2);
    
    printf("g(3) = %d\n", g(3));
    
    free(p);
    
    return 0;
}
