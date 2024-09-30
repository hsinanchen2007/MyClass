#include <stdio.h>

int main()
{
    int a[5] = {0};
    int b[2];
    int* p = NULL;
    
    p = a;
    
    printf("a = %p\n", a);                  // a = 006FFEA8
    printf("p = %p\n", p);                  // p = 006FFEA8
    printf("&p = %p\n", &p);                // &p = 006FFEA4
    printf("sizeof(a) = %d\n", sizeof(a));  // sizeof(a) = 20
    printf("sizeof(p) = %d\n", sizeof(p));  // sizeof(p) = 4
   
    printf("\n");

    p = b;
    
    printf("b = %p\n", b);                  // b = 006FFE9C
    printf("p = %p\n", p);                  // p = 006FFE9C
    printf("&p = %p\n", &p);                // &p = 006FFEA4
    printf("sizeof(b) = %d\n", sizeof(b));  // sizeof(b) = 8
    printf("sizeof(p) = %d\n", sizeof(p));  // sizeof(p) = 4
    
    // array name is a constant pointer
    // when assign a to b, it is not allowed
    // b = a;
  
    return 0;
}
