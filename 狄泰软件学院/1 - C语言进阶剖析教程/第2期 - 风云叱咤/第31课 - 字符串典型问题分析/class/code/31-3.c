#include <stdio.h>
#include <string.h>

int main()
{
    #define S1 "D.T.Software"
    #define S2 "D.T.Software"
    
    if( S1 == S2 )
    {
        printf("Equal\n");
    }
    else
    {
        printf("Non Equal\n");
    }
    
    if( strcmp(S1, S2) == 0 )
    {
        printf("Equal\n");
    }
    else
    {
        printf("Non Equal\n");
    }
    
    return 0;
}
