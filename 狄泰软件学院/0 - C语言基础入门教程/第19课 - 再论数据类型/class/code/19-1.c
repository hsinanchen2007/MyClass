#include <stdio.h>

int main()
{
    int c = sizeof(char);
    int s = sizeof(short);
    int i = sizeof(s);

    int uc = sizeof(unsigned char);
    int us = sizeof(unsigned short);
    int ui = sizeof(unsigned int);

    printf("c = %d\n", c);  // c = 1
    printf("s = %d\n", s);  // s = 2
    printf("i = %d\n", i);  // i = 4

    printf("sizeof(float) = %d\n", sizeof(float));      // sizeof(float) = 4
    printf("sizeof(double) = %d\n", sizeof(double));    // sizeof(double) = 8

    printf("uc = %d\n", uc);    // uc = 1
    printf("us = %d\n", us);    // us = 2
    printf("ui = %d\n", ui);    // ui = 4

    return 0;
}
