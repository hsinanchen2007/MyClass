#include <stdio.h>

// !!!! BAD CODE !!!!
// Return a local variable reference, its reference will be freed
// after end of function call
int& demo()
{
    int d = 0;

    printf("demo: d = %d\n", d);

    return d;
}

// !!!! OK CODE !!!!
// The returned variable is static, so its reference won't be changed
// during the run
int& func()
{
    static int s = 0;

    printf("func: s = %d, address = %p\n", s, &s);

    return s;
}

int main(int argc, char* argv[])
{
    int& rd = demo();
    int& rs = func();   // int &rs = s;

    printf("\n");
    printf("main: rd = %d\n", rd);
    printf("main: rs = %d, address = %p\n", rs, &rs);
    printf("\n");

    rd = 10;
    rs = 11;

    demo();
    func();

    printf("\n");
    printf("main: rd = %d\n", rd);
    printf("main: rs = %d\n", rs);
    printf("\n");

    return 0;
}
