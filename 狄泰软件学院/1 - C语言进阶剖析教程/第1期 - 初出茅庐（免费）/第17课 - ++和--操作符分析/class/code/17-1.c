#include <stdio.h> 

int main()
{
    int i = 0;
    int r = 0;

    r = (i++) + (i++) + (i++);

    printf("i = %d\n", i);      // 3
    printf("r = %d\n", r);      // 0

    r = (++i) + (++i) + (++i);

    printf("i = %d\n", i);      // 6
    printf("r = %d\n", r);      // 18

    return 0;
}
