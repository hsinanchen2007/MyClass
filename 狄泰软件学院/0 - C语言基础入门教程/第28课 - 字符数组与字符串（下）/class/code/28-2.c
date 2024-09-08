#include <stdio.h>
#include <string.h>

int main()
{
    char s[10] = "abcd";
    char d[] = "efg";
    int len = strlen(s);
    char in[16] = {0};

    printf("s = %s\n", s);      // s = abcd
    printf("len = %d\n", len);  // len = 4

    strcpy(s, d);
    strcat(s, d);

    len = strlen(s);

    printf("s = %s\n", s);      // s = efgefg
    printf("len = %d\n", len);  // len = 6

    printf("Input: ");
    scanf("%s", in);

    if( strcmp(s, in) == 0 )
    {
        printf("equal\n");
    }
    else
    {
        printf("non-equal\n");
    }

    return 0;
}
