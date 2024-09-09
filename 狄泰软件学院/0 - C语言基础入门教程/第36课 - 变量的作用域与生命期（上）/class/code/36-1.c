#include <stdio.h>

int var = 100;  // 全局变量

void f(int var) // var <==> 局部变量, pass by value
{
    var++;

    printf("var = %d\n", var);
}

void f2(int *var2) // var <==> 局部变量, pass by pointer
{
    // below statement is tricky, needed to use "" like (*var2) first, then ++
    // otherwise its value won't be set properly
    (*var2)++;

    printf("var = %d\n", *var2);
}

int main()
{
    int var = 10;  // 局部变量

    f(var);                     // f(10);

    printf("var = %d\n", var);  // var = 10;

    f2(&var);

    printf("var = %d\n", var);  // var = 11;

    return 0;
}
