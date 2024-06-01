// Include C standard library
// but their names are starting with 
// "c" and no ".h" at the end
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

// This is C++'s STL namespace
using namespace std;

int main()
{
    printf("Hello world!\n");

    // by purpose to use C style malloc
    char* p = (char*)malloc(16);

    strcpy(p, "D.T.Software");

    double a = 3;
    double b = 4;
    double c = sqrt(a * a + b * b);

    printf("c = %f\n", c);

    // by purpose to use C style free()
    free(p);

    return 0;
}
