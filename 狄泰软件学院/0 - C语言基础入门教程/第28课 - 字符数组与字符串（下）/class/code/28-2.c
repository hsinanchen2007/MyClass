#include <stdio.h>
#include <string.h>

int main()
{
    char s[10] = "abcd";
    char d[] = "efg";
    int len = strlen(s);
    char in[16] = {0};

    printf("s = %s\n", s);
    printf("len = %d\n", len);

    strcpy(s, d);
    strcat(s, d);

    len = strlen(s);

    printf("s = %s\n", s);
    printf("len = %d\n", len);

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
