#include <stdio.h>

int main()
{
    int c = sizeof(char);
    int s = sizeof(short);
    int i = sizeof(s);

    int uc = sizeof(unsigned char);
    int us = sizeof(unsigned short);
    int ui = sizeof(unsigned int);

    printf("c = %d\n", c);
    printf("s = %d\n", s);
    printf("i = %d\n", i);

    printf("sizeof(float) = %d\n", sizeof(float));
    printf("sizeof(double) = %d\n", sizeof(double));

    printf("uc = %d\n", uc);
    printf("us = %d\n", us);
    printf("ui = %d\n", ui);

    return 0;
}
