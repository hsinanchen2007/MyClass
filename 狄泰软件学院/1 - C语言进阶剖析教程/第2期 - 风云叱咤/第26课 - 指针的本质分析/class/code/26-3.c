#include <stdio.h>

int main()
{
    int i = 0;
    
    const int* p1 = &i;
    int const* p2 = &i;
    int* const p3 = &i;
    const int* const p4 = &i;
    
    *p1 = 1;    // compile error
    p1 = NULL;  // ok
    
    *p2 = 2;    // compile error
    p2 = NULL;  // ok
    
    *p3 = 3;    // ok
    p3 = NULL;  // compile error
    
    *p4 = 4;    // compile error
    p4 = NULL;  // compile error
    
    return 0;
}
