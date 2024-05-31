#include <stdio.h>
#include <string.h>

int main()
{
    #define STR "Hello, \0D.T.Software\0"
    
    char* src = STR;
    char buf[255] = {0};
    
    snprintf(buf, sizeof(buf), src);
    
    printf("strlen(STR) = %d\n", strlen(STR));
    printf("sizeof(STR) = %d\n", sizeof(STR));
    
    printf("strlen(src) = %d\n", strlen(src));
    printf("sizeof(src) = %d\n", sizeof(src));
    
    printf("strlen(buf) = %d\n", strlen(buf));
    printf("sizeof(buf) = %d\n", sizeof(buf));
    
    printf("src = %s\n", src);
    printf("buf = %s\n", buf);
    
    return 0;
}
