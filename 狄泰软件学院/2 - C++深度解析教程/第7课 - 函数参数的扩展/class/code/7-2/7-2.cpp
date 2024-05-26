#include <stdio.h>

int add(int x, int y = 0, int z = 0);

int main(int argc, char* argv[])
{
    printf("%d\n", add(1));         // x = 1, rest uses default
    printf("%d\n", add(1, 2));      // x = 1, y = 2, last uses default
    printf("%d\n", add(1, 2, 3));   // all x, y, z use specified values

    return 0;
}

int add(int x, int y, int z)
{
    return x + y + z;
}

