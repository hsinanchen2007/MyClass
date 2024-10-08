#include <stdio.h>
#include <string.h>

int main()
{
    #define STR "Hello, \0D.T.Software\0"
    
    char* src = STR;
    char buf[255] = {0};
    
    snprintf(buf, sizeof(buf), src);
    
    printf("strlen(STR) = %d\n", strlen(STR));  // strlen(STR) = 7
    printf("sizeof(STR) = %d\n", sizeof(STR));  // sizeof(STR) = 22
    
    printf("strlen(src) = %d\n", strlen(src));  // strlen(src) = 7
    printf("sizeof(src) = %d\n", sizeof(src));  // sizeof(src) = 4
    
    printf("strlen(buf) = %d\n", strlen(buf));  // strlen(buf) = 7
    printf("sizeof(buf) = %d\n", sizeof(buf));  // sizeof(buf) = 255
    
    printf("src = %s\n", src);                  // src = Hello,
    printf("buf = %s\n", buf);                  // buf = Hello,
    
    printf("%d\n", sizeof("ABCD EFGH"));        // 10 = 9 + 1 where 1 is '\0

    return 0;
}
