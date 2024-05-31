#include <stdio.h>

int main()
{
    int i = 0;
    int j = 0;
    int k = 0;
    
    if( ++i | ++j & ++k )
    {
        printf("Run here...\n");
    }
    
    return 0;
}
