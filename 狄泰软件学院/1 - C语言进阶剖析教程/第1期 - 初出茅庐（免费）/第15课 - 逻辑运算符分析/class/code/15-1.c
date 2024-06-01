#include <stdio.h>

int main()
{
    int i = 0;
    int j = 0;
    int k = 0;
    
    ++i || ++j && ++k;

    printf("%d\n", i);
    printf("%d\n", j);
    printf("%d\n", k);
    
    return 0;
}
