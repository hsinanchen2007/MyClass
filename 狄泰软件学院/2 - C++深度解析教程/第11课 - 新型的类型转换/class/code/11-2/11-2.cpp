#include <stdio.h>

void static_cast_demo()
{
    int i = 0x12345;
    char c = 'c';
    int* pi = &i;
    char* pc = &c;

    c = static_cast<char>(i);

    // static_Cast<> cannot be used for basic type pointer conversion
    //pc = static_cast<char*>(pi);
}

void const_cast_demo()
{
    const int& j = 1;
    int& k = const_cast<int&>(j);

    const int x = 2;
    int& y = const_cast<int&>(x);

    // const_case<> must use on reference or pointer
    // int z = const_cast<int>(x);

    k = 5;

    printf("k = %d\n", k);
    printf("j = %d\n", j);

    y = 8;

    printf("x = %d\n", x);
    printf("y = %d\n", y);
    printf("&x = %p\n", &x);
    printf("&y = %p\n", &y);
}

void reinterpret_cast_demo()
{
    int i = 0;
    char c = 'c';
    int* pi = &i;
    char* pc = &c;

    pc = reinterpret_cast<char*>(pi);
    pi = reinterpret_cast<int*>(pc);

    // reinterpret_cast<> is used to convert between pointers or 
    // int and pointer only
    // pi = reinterpret_cast<int*>(i);
    // c = reinterpret_cast<char>(i);
}

void dynamic_cast_demo()
{
    int i = 0;
    int* pi = &i;

    // dynamic_case<> is mainly used within parent/child classes
    // and virtual function is needed
    // char* pc = dynamic_cast<char*>(pi);
}

int main()
{
    static_cast_demo();
    const_cast_demo();
    reinterpret_cast_demo();
    dynamic_cast_demo();

    return 0;
}
