#include <stdio.h>

// In C++, when we define struct, it will be considered as a new data type
// there is no need to do typedef struct_name new_type_name
struct Student
{
    const char* name;
    int age;
};

// Below two functions are OK for C, but not C++
/* 
f(i)
{
    printf("i = %d\n", i);
}

g()
{
    return 5;
}
*/

// C++ required specified return type and parameters
void f(int i)
{
    printf("i = %d\n", i);
}

// Use ... as parameter to allow unknown # of parameters
int g(...)
{
    return 5;
}

int main(int argc, char* argv[])
{
    Student s1 = { "Delphi", 30 };
    Student s2 = { "Tang", 30 };

    f(10);

    // C++ required specified paramters
    // If we do need such usage, can use "..." in g() function like "g(...)"
    printf("g() = %d\n", g(1, 2, 3, 4, 5));

    return 0;
}
