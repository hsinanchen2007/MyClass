#include <stdio.h>

int main()
{
    int a[5] = {0};
    int* p = a;
    int i = 0;
    
    for(i=0; i<5; i++)
    {
        p[i] = i + 1;
    }
    
    for(i=0; i<5; i++)
    {
        printf("a[%d] = %d\n", i, *(a + i));
    }
    
    printf("\n");
    
    // a[i] is equivalent to *(a + i) and i[a] is equivalent to *(i + a) 
    // so i[a] is equivalent to a[i]
    for(i=0; i<5; i++)
    {
        i[a] = i + 10;
    }
    
    for(i=0; i<5; i++)
    {
        printf("p[%d] = %d\n", i, p[i]);
    }
    
    return 0;
}
