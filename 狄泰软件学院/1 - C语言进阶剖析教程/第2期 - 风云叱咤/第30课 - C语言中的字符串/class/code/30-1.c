#include <stdio.h>

int main()
{
    char ca[] = {'H', 'e', 'l', 'l', 'o'};          // No '\0' at the end, not a string, Hello~▼
    char sa[] = {'W', 'o', 'r', 'l', 'd', '\0'};    // '\0' at the end, a string, World
    char ss[] = "Hello world!";                     // '\0' at the end, a string, Hello world!
    char* str = "Hello world!";                     // '\0' at the end, a string, Hello world!
    
    printf("%s\n", ca);
    printf("%s\n", sa);
    printf("%s\n", ss);
    printf("%s\n", str);
    
    return 0;
}
