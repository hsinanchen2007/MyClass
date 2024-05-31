#include <stdio.h>

const char* f(const int i)
{
    i = 5;
    
    return "Delphi Tang";
}

int main()
{
    char* pc = f(0);
    
    printf("%s\n", pc);
    
    pc[6] = '_';
    
    printf("%s\n", pc);
    
    return 0;
}
