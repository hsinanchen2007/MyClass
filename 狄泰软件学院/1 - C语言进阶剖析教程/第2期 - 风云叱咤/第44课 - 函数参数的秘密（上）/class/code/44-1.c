#include <stdio.h>

int func(int i, int j)
{
    printf("%d, %d\n", i, j);
    
    return 0;
}

int main()
{
    int k = 1;
    
    func(k++, k++);
    
    printf("%d\n", k);
    
    return 0;
}

