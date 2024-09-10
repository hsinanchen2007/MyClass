#include <stdio.h>

int main()
{
    int a[] = {1, 2, 3};
    int* p = a;
    int v = *p++;

    char* s = NULL;

    printf("%p\n", "D.T.Software");             // 002A3000
    printf("%p\n", "D.T.Software");             // 002A3014

    printf("v = %d, *p = %d\n", v, *p);         // v = 1, *p = 2

    printf("First = %c\n", *"D.T.Software");    // First = D

    s = "D.T.Software";

    while( *s ) printf("%c", *s++);             // D.T.Software

    printf("\n");
    printf("%p\n", s);                          // 002A3064

    return 0;
}
