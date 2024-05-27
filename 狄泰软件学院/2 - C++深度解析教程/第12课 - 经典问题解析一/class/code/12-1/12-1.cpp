#include <stdio.h>

int main()
{
    // x cannot be changed
    const int x = 1;

    // rx cannot be changed, and also create a new variable location
    // Its address will be different than x
    const int& rx = x;

    // Now by using const_cast<>, make nrx can be changed 
    int& nrx = const_cast<int&>(rx);
    nrx = 5;

    printf("x = %d\n", x);
    printf("rx = %d\n", rx);
    printf("nrx = %d\n", nrx);
    printf("&x = %p\n", &x);
    printf("&rx = %p\n", &rx);
    printf("&nrx = %p\n", &nrx);

    // By using volatile, it makes y is not listed as const lookup table
    // so when we try to get its value, it will return real one if changed
    volatile const int y = 2;

    // make y can be changed now
    int* p = const_cast<int*>(&y);
    *p = 6;

    // Here, y will return real value, not from const lookup table
    printf("y = %d\n", y);
    printf("p = %p, %d\n", p, *p);

    // similar to y
    const int z = y;

    // make z can be changed now
    p = const_cast<int*>(&z);
    *p = 7;

    printf("z = %d\n", z);
    printf("p = %p\n", p);

    // c and rc are pointed to same location, and can be changed
    char c = 'c';
    char& rc = c;

    // trc will be initialized into const lookup table and
    // cannot be changed in code
    const int& trc = c;

    rc = 'a';

    // will show updated one "a"
    printf("c = %c %p\n", c, &c);
    printf("rc = %c %p\n", rc, &rc);

    // will still point to original one from const lookup table
    printf("trc = %c\n", trc);

    return 0;
}
