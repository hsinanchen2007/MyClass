#include <stdio.h>

// for MSVC, force the inline function be compiled
// as real inline functions
__forceinline

// for g++, used in Linux g++
// __attribute__((always_inline))

inline
int add_inline(int n);

int main(int argc, char* argv[])
{
    int r = add_inline(10);

    printf(" r = %d\n", r);

    return 0;
}

inline int add_inline(int n)
{
    int ret = 0;

    for (int i = 0; i < n; i++)
    {
        ret += i;
    }

    return ret;
}