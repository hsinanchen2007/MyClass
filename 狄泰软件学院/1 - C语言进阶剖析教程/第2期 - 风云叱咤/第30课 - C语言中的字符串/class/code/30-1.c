#include <stdio.h>

int main()
{
    char ca[] = {'H', 'e', 'l', 'l', 'o'};
    char sa[] = {'W', 'o', 'r', 'l', 'd', '\0'};
    char ss[] = "Hello world!";
    char* str = "Hello world!";
    
    printf("%s\n", ca);
    printf("%s\n", sa);
    printf("%s\n", ss);
    printf("%s\n", str);
    
    return 0;
}
