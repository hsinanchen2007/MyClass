#include <iostream>

void swap(int *x, int *y);

int main()
{
    int a, b;
    a = 3;
    b = 5;

    swap(&a, &b);

    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";

    return 0;
}

void swap(int *x, int *y)
{
#if 0
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
#endif

    *x ^= *y;
    *y ^= *x;
    *x ^= *y;
}
