#include <stdio.h>

int main()
{
    int a[] = {1, 2, 3};
    int* p = a;
    int v = *p++;

    char* s = NULL;

    printf("%p\n", "D.T.Software");
    printf("%p\n", "D.T.Software");

    printf("v = %d, *p = %d\n", v, *p);

    printf("First = %c\n", *"D.T.Software");

    s = "D.T.Software";

    while( *s ) printf("%c", *s++);

    printf("\n");

    return 0;
}
