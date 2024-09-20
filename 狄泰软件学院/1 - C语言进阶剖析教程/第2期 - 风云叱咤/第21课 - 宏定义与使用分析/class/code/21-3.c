#include <stdio.h>

void def()
{
    // define PI as 3.1415926
    #define PI 3.1415926

    // define AREA as r * r * PI
    #define AREA(r) r * r * PI
}

double area(double r)
{
    // call defined macro AREA where it will be replaced as r * r * PI
    // the defined macros are only available in the same file 
    return AREA(r);
}

int main()
{
    double r = area(5);

    printf("PI = %f\n", PI);        // PI = 3.141593
    printf("d = 5; a = %f\n", r);   // d = 5; a = 78.539815
    
    return 0;
}
