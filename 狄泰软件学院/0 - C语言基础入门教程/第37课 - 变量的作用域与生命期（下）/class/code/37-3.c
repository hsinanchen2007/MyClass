#include <stdio.h>

int g_var = 1;
static int g_sVar = 2;

int main()
{
    static int s_var = 3;
    auto int v = 4;
    register int rv = 5;

    printf("g_var = %d\n", g_var);
    printf("g_sVar = %d\n", g_sVar);
    printf("s_var = %d\n", s_var);
    printf("v     = %d\n", v);
    printf("rv    = %d\n", rv);

    return 0;
}
