#include <stdio.h>

int var = 1;

void func()
{
    printf("var = %d\n", var);          // no parameter, no local, use global variable, 1
}

int main()
{
    int var = 2;
    int i = 0;

    for(i=0; i<5; i++)
    {
        int var = 4;                    // alwys use this var and initialized as 4 in each iteration

        var += i;

        printf("var = %d\n", var);
    }

    func();

    printf("var = %d\n", var);          // use local variable, 2

    return 0;
}
