#include <stdio.h>

int g_var = 1;
static int g_sVar = 2;

int main()
{
    static int s_var = 3;
    auto int v = 4;
    register int rv = 5;

    printf("g_var = %d\n", g_var);      // g_var = 1
    printf("g_sVar = %d\n", g_sVar);    // g_sVar = 2
    printf("s_var = %d\n", s_var);      // s_var = 3
    printf("v     = %d\n", v);          // v     = 4
    printf("rv    = %d\n", rv);         // rv    = 5

    return 0;
}
