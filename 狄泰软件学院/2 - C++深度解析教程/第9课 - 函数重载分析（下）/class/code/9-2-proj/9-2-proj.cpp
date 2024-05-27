#include <stdio.h>

// Below code block is good example that 
// it can be compiled with C and C++
// where the "__cplusplus" plays the key
// If the compiler is C++, use the following
// extern C { C code ...}, otherwise it will
// use C++ way to compile the code
#ifdef __cplusplus
extern "C" {
#endif

#include "add.h"

#ifdef __cplusplus
}
#endif

int main()
{
    int c = add(1, 2);

    printf("c = %d\n", c);

    // practice function pointer again
    printf("%p\n", (int(*)(int, int))add);

    return 0;
}