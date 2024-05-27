#include <stdio.h>
#include <string.h>

// overload function can be same function name but 
// 1. different parameters
// 2. different number of parameters
// 3. different order of parameters
// not return type
// 
//void func(int x)
//{
//    printf("This is void func(int x)");
//}

int func(int x)
{
    return x;
}

int func(int a, int b)
{
    return a + b;
}

int func(const char* s)
{
    return strlen(s);
}


int main(int argc, char* argv[])
{
    printf("%d\n", func(3));
    printf("%d\n", func(4, 5));
    printf("%d\n", func("D.T.Software"));

    return 0;
}

