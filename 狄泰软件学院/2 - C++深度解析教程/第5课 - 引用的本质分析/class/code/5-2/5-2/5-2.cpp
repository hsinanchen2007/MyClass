#include <stdio.h>

struct TRef
{
    char& r;
};

struct Test1
{
    int myI1;   // 4
    int myI2;   // 4
    char& c1;   // 8
    double d1;  // 8
};

struct Test2 {

};

// when the data member is reference, it will use 8 bytes (x64) 
// as internally C++ uses pointer to them
struct Test3 {
    int& myI1;   // 8
    int& myI2;   // 8
    char& c1;    // 8
    double& d1;  // 8
};

struct Test4 {
    int* myI1;   // 8
    int* myI2;   // 8
    char* c1;    // 8
    double* d1;  // 8
};

int main(int argc, char* argv[])
{
    // type & name == type * const name
    char c = 'c';
    char& rc = c;
    TRef ref = { c };
    TRef& Rref = ref;
    Test1 t1 = {1, 2, c, 10000.0};
    Test2 t2;
    int a = 100;
    int b = 200;
    double d = 1.2345;
    Test3 t3 = {a, b, c, d};
    Test4 t4 = {};

    // common data type size and their reference will be same as original one
    printf("sizeof(char&) = %d\n", sizeof(char&));          // 1
    printf("sizeof(int&) = %d\n", sizeof(int&));            // 4
    printf("sizeof(double&) = %d\n", sizeof(double&));      // 8
    printf("sizeof(float&) = %d\n", sizeof(float&));        // 4

    printf("sizeof(char) = %d\n", sizeof(char));            // 1
    printf("sizeof(int) = %d\n", sizeof(int));              // 4
    printf("sizeof(double) = %d\n", sizeof(double));        // 8
    printf("sizeof(float) = %d\n", sizeof(float));          // 4

    printf("sizeof(rc) = %d\n", sizeof(rc));                // 1

    printf("sizeof(TRef) = %d\n", sizeof(TRef));            // 8 for x64, 4 for x86
    printf("sizeof(ref.r) = %d\n", sizeof(ref.r));          // 1

    // reference is same as its original variable
    printf("sizeof(Rref) = %d\n", sizeof(Rref));            // 8 for x64, 4 for x86

    // struct Test1, will depend on what data members in the struct
    printf("sizeof(t1) = %d\n", sizeof(t1));                // 24 for x64, 24 for x86

    // data member memory usage in struct
    printf("sizeof(t2) = %d\n", sizeof(t2));                // 1 for x64, 1 for x86
    printf("sizeof(t3) = %d\n", sizeof(t3));                // 32 for x64, 16 for x86
    printf("sizeof(t4) = %d\n", sizeof(t4));                // 32 for x64, 16 for x86

    return 0;
}
