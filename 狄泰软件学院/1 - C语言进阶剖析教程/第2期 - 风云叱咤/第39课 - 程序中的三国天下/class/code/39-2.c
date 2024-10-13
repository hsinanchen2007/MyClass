#include <stdio.h>

// global and static global variables are located at 靜態存储區
int g_v = 1;

static int g_vs  = 2;

void f()
{
    static int g_vl = 3;
    
    printf("%p\n", &g_vl);  // 01003008
}

int main()
{
    printf("%p\n", &g_v);   // 01003000
    
    printf("%p\n", &g_vs);  // 01003004
    
    f();
    
    return 0;
}
