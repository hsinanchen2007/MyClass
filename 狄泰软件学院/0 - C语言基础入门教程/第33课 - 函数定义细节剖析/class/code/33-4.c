#include <stdio.h>

void demo(void)
{
    printf("How are you?\n");
    return;
    printf("Fine, thank you!\n");
}

int func(int a, int b)
{
    if( a > 0 )
        return a + b;
    // else
        // return a - b;
}

int g(int v)
{
    if( v > 0 )
        return "Delphi";
    else
        return "Tang";
}

int main()
{
    // int c = func(-1, 2);

    printf("Begin\n");

    //demo();
    // printf("c = %d\n", c);

    printf("End\n");

    return 0;
}
