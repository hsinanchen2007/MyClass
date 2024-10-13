#include <stdio.h>

int main()
{
    int k = 2;
    int a = 1;
    
    // 2 + 2 + (K++ twice) = 6
    // do + first, then do ++
    k = k++ + k++;
    
    printf("k = %d\n", k);
    
    // once we hit &&, value needed to be evaluated
    // so it becomes if (1 && 0) which is false
    if( a-- && a )
    {
        printf("a = %d\n", a);
    }
    
    return 0;
}

