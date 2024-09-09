#include <stdio.h>

// function declaration 聲明
int pow2(int a);

int main()
{
    int a = 3;

    // use pow2()
    printf("call pow2(%d): %d\n", a, pow2(a));

    return 0;
}

// function definition 定義
int pow2(int a)
{
    return a * a;
}
