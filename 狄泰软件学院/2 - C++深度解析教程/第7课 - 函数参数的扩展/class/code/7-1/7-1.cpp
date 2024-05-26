#include <stdio.h>

// C++ compiler supports this, but C compiler does NOT support this
int mul(int x = 0);

int main(int argc, char* argv[])
{
    printf("%d\n", mul());      // no specified parameter value, use default 0 value
    printf("%d\n", mul(-1));    // has specified parameter value, use its value
    printf("%d\n", mul(2));     // has specified parameter value, use its value

    return 0;
}

int mul(int x)
{
    return x * x; 
}

