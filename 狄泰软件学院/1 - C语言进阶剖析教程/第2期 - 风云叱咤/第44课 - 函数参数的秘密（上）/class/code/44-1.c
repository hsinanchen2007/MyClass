#include <stdio.h>

int func(int i, int j)
{
    // depends on compiler, below code may output 1, 2 or 2, 1 or 1, 1
    // In C language, the order of evaluation of function arguments is unspecified.
    printf("%d, %d\n", i, j);   // 1, 1
    
    return 0;
}

int main()
{
    int k = 1;
    
    // parameters are passed to function at stack first
    // then the function is called
    func(k++, k++);
    
    printf("%d\n", k);          // 3    
    
    return 0;
}

