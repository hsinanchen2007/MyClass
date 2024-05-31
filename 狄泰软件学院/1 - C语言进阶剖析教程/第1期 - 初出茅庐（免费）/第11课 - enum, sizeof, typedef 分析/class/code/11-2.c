#include <stdio.h>

int f()
{
    printf("Delphi Tang\n");
    
    return 0;
}

int main()
{
    int var = 0;
    
    int size = sizeof(var++);
    
    printf("var = %d, size = %d\n", var, size);
    
    size = sizeof(f());
    
    printf("size = %d\n", size);
    
    return 0;
}
