#include <stdio.h>

const char* f(const int i)
{
    // i = 5;
    
    return "Delphi Tang";
}

int main()
{
    // error: invalid conversion from 'const char*' to 'char*'
    // but if it is not const, it will be ok for pc[6] = '_' below
    char* pc = f(0);
    
    printf("%s\n", pc); // Delphi Tang
    
    pc[6] = '_';
    
    printf("%s\n", pc); // Delphi_Tang
    
    return 0;
}
