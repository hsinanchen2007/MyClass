#include <stdio.h>

int main()
{
    char enter = '\n';
    
    char* p = "\141\t\x62";
    
    printf("%s", p);        // a       b
    printf("%c", enter);    // \n
    
    return 0;
}

