#include <stdio.h>

int main()
{
    char buf[10] = {0};
    char src[] = "hello %s";
    
    snprintf(buf, sizeof(buf), src);
    
    printf("buf = %s\n", buf);
    
    return 0;
}
