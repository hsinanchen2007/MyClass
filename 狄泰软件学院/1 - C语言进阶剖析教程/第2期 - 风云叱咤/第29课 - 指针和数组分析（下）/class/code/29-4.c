#include <stdio.h>

void func1(char a[5])
{
    printf("In func1: sizeof(a) = %d\n", sizeof(a));
    
    *a = 'a';
    
    a = NULL;
}

void func2(char b[])
{
    printf("In func2: sizeof(b) = %d\n", sizeof(b));
    
    *b = 'b';
    
    b = NULL;
}

int main()
{
    char array[10] = {0};
    
    func1(array);
    
    printf("array[0] = %c\n", array[0]);
    
    func2(array);
    
    printf("array[0] = %c\n", array[0]);
    
    return 0;
}