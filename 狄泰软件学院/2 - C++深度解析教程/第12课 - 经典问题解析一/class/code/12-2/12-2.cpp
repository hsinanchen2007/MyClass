#include <stdio.h>

int a = 1;

struct SV
{
    int& x;
    int& y;
    int& z;
};

int main()
{
    int b = 2;
    int* pc = new int(3);
    SV sv = { a, b, *pc };

    // Below statement cannot work because *pc won't guarantee that its address will be
    // in the same order of a and b
    // int& array[] = { a, b, *pc }; // &array[1] - &array[0] = ?  Expected ==> 4

    // But if we put same data members into struct, it works as struct doesn't require
    // all data members should be saved in the order with same distance
    printf("&sv.x = %p\n", &sv.x);
    printf("&sv.y = %p\n", &sv.y);
    printf("&sv.z = %p\n", &sv.z);

    delete pc;

    return 0;
}
