#include <stdio.h>

int main()
{
    char c = 0;
    short s = 0;
    int i = 0;
    
    printf("%d, %d\n", sizeof(char), sizeof(c));        // 1, 1
    printf("%d, %d\n", sizeof(short), sizeof(s));       // 2, 2
    printf("%d, %d\n", sizeof(int), sizeof(i));         // 4, 4
    
    return 0;
}
