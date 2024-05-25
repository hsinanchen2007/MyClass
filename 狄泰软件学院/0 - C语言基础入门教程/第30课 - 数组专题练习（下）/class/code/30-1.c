#include <stdio.h>
#include <string.h>

int main()
{
    int i = 0;
    int e = 0;
    char r[10] = ""; // char r[10] = {0};

    for(i=0; i<strlen("abcd")+1; i++)
    {
        e = "abcd"[i];

        printf("%d ", e);
    }

    printf("\n");

    strcat(r, "abcd");
    strcat(r, "efghi");

    printf("r = %s\n", r);


    return 0;
}
