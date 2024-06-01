#include <stdio.h>

int main()
{ 
    int (*p1)(int*, int (*f)(int*));
    
    int (*p2[5])(int*);
    
    int (*(*p3)[5])(int*);

    int*(*(*p4)(int*))(int*);
    
    int (*(*p5)(int*))[5];

    return 0;
}

