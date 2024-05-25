#include <stdio.h>

int main()
{
    char a[] = { 97, 98, 99 };
    char b[] = { 'D', '.', 'T', '.' };
    int i = 0;

    for(i=0; i<sizeof(a); i++)
        printf("%c", a[i]);

    printf("\n");

    for(i=0; i<sizeof(b); i++)
        printf("%c", b[i]);

    printf("\n");

    return 0;
}
