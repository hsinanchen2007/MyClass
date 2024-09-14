#include <stdio.h>

int main()
{
 
    float f = 3.1415f;
    float fl = 123456789;
    
    printf("%0.10f\n", f);      // 3.1414999962
    printf("%0.10f\n", fl);     // 123456792.0000000000
    
    return 0;
}
