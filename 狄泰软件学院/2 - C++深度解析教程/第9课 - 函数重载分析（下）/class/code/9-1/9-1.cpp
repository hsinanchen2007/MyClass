﻿#include <stdio.h>
#include <string.h>

int func(int x)
{
    return x;
}

int func(int a, int b)
{
    return a + b;
}

int func(const char* s)
{
    return strlen(s);
}

typedef int(*PFUNC) (int a);


int main(int argc, char* argv[])
{
    int c = 0;

    PFUNC p = func;
    c = p(1);

    printf("c = %d\n", c);

    // print out overload function's address
    printf("%p\n", (int(*)(int))func);
    printf("%p\n", (int(*)(int, int))func);
    printf("%p\n", (int(*)(const char *))func);

    return 0;
}

