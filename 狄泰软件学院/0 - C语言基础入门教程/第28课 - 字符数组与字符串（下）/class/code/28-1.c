#include <stdio.h>
#include <string.h>

int main()
{
    char s[10] = "abcd";
    int size = sizeof(s);

    int len = strlen(s);

    printf("size = %d\n", size);    // size = 10
    printf("len = %d\n", len);      // len = 4

    return 0;
}
