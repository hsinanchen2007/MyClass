#include <stdio.h>

int add(int a, int b)  // int(int, int)
{
    return a + b;
}

int add(int a, int b, int c) // int(int, int, int)
{
    return a + b + c;
}

int main()
{
    // We can use dumpbin /symbols *.obj to get function's symbol
    // 
    // Below way to print out function address:
    //   1. copy its return(parameter1, parameter2, ....)
    //   2. use (1) as pre-fix, change return type to (int*)
    //   3. add function name at the end
    // Remember that the returned address should use "%p"
    // Use %d will not print out valid address value
    printf("%p\n", (int(*)(int, int))add);
    printf("%p\n", (int(*)(int, int, int))add);

    return 0;
}