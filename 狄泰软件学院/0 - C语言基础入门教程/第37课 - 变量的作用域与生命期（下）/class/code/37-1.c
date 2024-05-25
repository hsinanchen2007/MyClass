#include <stdio.h>

int var = 1;

void func()
{
    printf("var = %d\n", var);
}

int main()
{
    int var = 2;
    int i = 0;

    for(i=0; i<5; i++)
    {
        int var = 4;

        var += i;

        printf("var = %d\n", var);
    }

    func();

    printf("var = %d\n", var);

    return 0;
}
