#include <stdio.h>
#include <string.h>

int main()
{
    char s[10] = "abcd";
    int size = sizeof(s);

    int len = strlen(s);

    printf("size = %d\n", size);
    printf("len = %d\n", len);

    return 0;
}
