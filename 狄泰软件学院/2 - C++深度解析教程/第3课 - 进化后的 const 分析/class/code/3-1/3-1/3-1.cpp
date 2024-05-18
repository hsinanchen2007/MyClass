#include <stdio.h>

int main()
{
    // For C++, once we define a const variable, it will be put into a table lookup
    // If later on any usage of this const variable, it will just be replaced from the table, 
    // no matter the value of the address has be changed or not

    // For C, below int* p = (int*)&c will allow program to change c's value, and
    // later on when program tries to access this value, it will become another updated value
    // as C didn't pre-saved the const value into a table lookup

    // If the const variable is used with extern or & reference, it will be also created
    // with a const variable space, to be used with reference or extern, but the value
    // in that const variable space will NOT be used. This is just for C and C++ usage
    const int c = 0;

    // Get C's address, and this address is pointed to a int, we save it into one int pointer
    int* p = (int*)&c;

    printf("Begin...\n");

    printf("c = %d\n", c);  // 0
    printf("p = %d\n", *p); // 0
    printf("c = %p\n", &c); // 000000E38CF5F774
    printf("p = %p\n", p);  // 000000E38CF5F774

    *p = 5;

    printf("c = %d\n", c);  // 0, in C++, c's value will be still 0, but in C, it will become 5
    printf("p = %d\n", *p); // 5
    printf("c = %p\n", &c); // 000000E38CF5F774
    printf("p = %p\n", p);  // 000000E38CF5F774

    printf("End...\n");

    return 0;
}
