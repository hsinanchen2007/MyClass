#include <stdio.h>
#include <malloc.h>

struct Demo
{
    char* p;
};

int main()
{
    struct Demo d1;
    struct Demo d2;
    
    char i = 0;
    
    for(i='a'; i<'z'; i++)
    {
        d1.p[i] = 0; 
    }
    
    d2.p = (char*)calloc(5, sizeof(char));
    
    printf("%s\n", d2.p);
    
    for(i='a'; i<'z'; i++)
    {
        d2.p[i] = i; 
    }
    
    free(d2.p);
    
    return 0;
}
