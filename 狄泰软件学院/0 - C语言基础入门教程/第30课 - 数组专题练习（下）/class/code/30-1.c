#include <stdio.h>
#include <string.h>

int main()
{
    int i = 0;
    int e = 0;
    char r[10] = ""; // char r[10] = {0};

    for(i=0; i<strlen("abcd")+1; i++)       // 97 98 99 100 0 
    {
        // below is a very special way to demonstrate that the "abcd" is a const variable
        // and can show its elements by index like array's index
        e = "abcd"[i];

        printf("%d ", e);
    }

    printf("\n");

    strcat(r, "abcd");
    strcat(r, "efghi");

    printf("r = %s\n", r);                  // r = abcdefghi


    return 0;
}
