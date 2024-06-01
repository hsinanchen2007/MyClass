#include <stdio.h>
#include <string.h>

int main()
{
    char s[] = "Hello\0world";
    int i = 0;
    
    for(i=0; i<sizeof(s)/sizeof(char); i++)
    {
        printf("%c\n", s[i]);
    }
    
    printf("%s\n", s);

    printf( "%d\n", strlen(s) );
    printf( "%d\n", strlen("123") );
 
    
    return 0;
}
