#include <stdio.h>

int main()
{
    char b = "abc"[0];
    char c = *("123" + 1);
    char t = *"";
    
    printf("%c\n", b);
    printf("%c\n", c);
    printf("%d\n", t);
    
    printf("%s\n", "Hello");
    printf("%p\n", "World");
    
    return 0;
}
