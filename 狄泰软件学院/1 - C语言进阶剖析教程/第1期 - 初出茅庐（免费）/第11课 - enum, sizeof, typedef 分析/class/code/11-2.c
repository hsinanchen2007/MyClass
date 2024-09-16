#include <stdio.h>

int f()
{
    printf("Delphi Tang\n");
    
    return 0;
}

int main()
{
    int var = 0;
    
    // sizeof is a operator, not a function, so even here it does var++
    // var++ will not change the value of var, so var is still 0
    int size = sizeof(var++);
    
    printf("var = %d, size = %d\n", var, size);     // var = 0, size = 4
    
    size = sizeof(f());
    
    printf("size = %d\n", size);                    // size = 4
    
    return 0;
}
