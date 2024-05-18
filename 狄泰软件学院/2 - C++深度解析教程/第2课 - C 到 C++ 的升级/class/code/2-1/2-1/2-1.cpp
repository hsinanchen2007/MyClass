#include <stdio.h>

int g_v;

// C++ doesn't allow multiple same global variables defined in code, but C can, 
// and will link them to same global data area
// int g_v;

int main(int argc, char* argv[])
{
    printf("Begin...\n");

    int c = 0;

    // C++ allows to declare variables when it is needed, but C needed to declare 
    // them at the beginning
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            c += i * j;
        }
    }

    printf("c = %d\n", c);

    // C++ can get register variable address, but C cannot
    register int a = 0;
    printf("&a = %p\n", &a);

    printf("End...\n");

    return 0;
}
