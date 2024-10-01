#include <stdio.h>

void func1(char a[5])
{
    // In func1: sizeof(a) = 4
    // array name is a pointer, not array size info, so sizeof(a) is 4
    printf("In func1: sizeof(a) = %d\n", sizeof(a));
    
    *a = 'a';
    
    a = NULL;
}

void func2(char b[])
{
    // In func2: sizeof(b) = 4
    // array name is a pointer, not array size info, so sizeof(b) is 4
    printf("In func2: sizeof(b) = %d\n", sizeof(b));
    
    *b = 'b';
    
    b = NULL;
}

int main()
{
    char array[10] = {0};
    
    func1(array);
    
    printf("array[0] = %c\n", array[0]);    // array[0] = a
    
    func2(array);
    
    printf("array[0] = %c\n", array[0]);    // array[0] = b
    
    return 0;
}