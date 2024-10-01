#include <stdio.h>

int main()
{
    char b = "abc"[0];
    char c = *("123" + 1);
    char t = *"";
    
    printf("%c\n", b);          // a
    printf("%c\n", c);          // 2
    printf("%d\n", t);          // 0
    
    printf("%s\n", "Hello");    // Hello
    printf("%p\n", "World");    // 00503020
    
    return 0;
}
