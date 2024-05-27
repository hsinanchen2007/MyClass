#include <stdio.h>

int main()
{
    // 1. new is for C++, malloc is for C
    // 2. new can initialize data at the same time, malloc cannot achieve this
    // 3. new can initialize memory based on data type, malloc is based on byte

    // use new to create a heap memory of int pointer
    int* p = new int;

    *p = 5;
    *p = *p + 10;

    printf("p = %p\n", p);
    printf("*p = %d\n", *p);

    // always new<->delete pair after use
    delete p;

    // create an array of heap memory for int pointers
    p = new int[10];

    for (int i = 0; i < 10; i++)
    {
        p[i] = i + 1;

        printf("p[%d] = %d\n", i, p[i]);
    }

    // for heap memory of array, always add [] with delete
    delete[] p;

    return 0;
}