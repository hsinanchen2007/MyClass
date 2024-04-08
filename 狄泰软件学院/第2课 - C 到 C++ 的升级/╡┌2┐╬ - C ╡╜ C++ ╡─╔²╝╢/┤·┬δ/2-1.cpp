#include <stdio.h>

int g_v;
//int g_v;

int main(int argc, char *argv[])
{
    printf("Begin...\n");
    
    int c = 0;
    
    for(int i=1; i<=3; i++)
    {
        for(int j=1; j<=3; j++)
        {
            c += i * j;
        }
    }
    
    printf("c = %d\n", c);
    
    register int a = 0;
    
    printf("&a = %p\n", &a);
    
    printf("End...\n");
    
    return 0;
}
