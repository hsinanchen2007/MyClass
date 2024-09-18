#include <stdio.h>

int main()
{
    int i = 0;
    int j = 0;
    int k = 0;
    
    if( ++i | ++j & ++k )
    {
        printf("Run here...\n");
        printf("i = %d\n", i);      // 1
        printf("j = %d\n", j);      // 1
        printf("k = %d\n", k);      // 1
    }
    
    // reset and try || and &&
    i = j = k = 0;

    // || and && have short-circuit feature which means 
    // if the left hand side is true, the right hand side will not be executed
    // here after ++i, the left hand side is true, so the right hand side will 
    // not be executed and condition is true
    if( ++i || ++j && ++k )
    {
        printf("Run here...\n");
        printf("i = %d\n", i);    // 1
        printf("j = %d\n", j);    // 0
        printf("k = %d\n", k);    // 0
    }

    return 0;
}
