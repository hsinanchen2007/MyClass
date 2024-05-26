#include <stdio.h>

#define FUNC(a, b) ((a) < (b) ? (a) : (b))

inline int func(int a, int b)
{
    return a < b ? a : b;
}

int main(int argc, char* argv[])
{
    int a = 1;
    int b = 3;

    // It will become ((++a) < (b) ? (++a) : (b)), resule 3 3 3, 
    // unexpected, reason is that macro will just replace the 
    // statement as "a" is "++a", it will be replaced to "++a" 
    // in all "a" part, while inline function behaves like regular 
    // function call, but compiler will replace the infunction 
    // function into original caller
    int c = FUNC(++a, b); 

    // inline function, result 2 3 2, expected, like regular
    // function
    // int c = func(++a, b); 

    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n", c);

    return 0;
}
