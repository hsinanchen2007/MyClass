#include <stdio.h>

// swap with one additional variable
#define SWAP1(a, b)    \
{                      \
    int t = a;         \
    a = b;             \
    b = t;             \
}

// swap without additional variable
// a = a + b; b = a - b; a = a - b;
// a = 3, b = 7
// a = 3 + 7 = 10
// b = 10 - 7 = 3
// a = 10 - 3 = 7
// now, a = 7, b = 3
#define SWAP2(a, b)    \
{                      \
    a = a + b;         \
    b = a - b;         \
    a = a - b;         \
}

// swap without additional variable and XOR operation
// a = a ^ b; b = a ^ b; a = a ^ b;
// a = 3, b = 7
// a = 3 ^ 7 = 4
// b = 4 ^ 7 = 3
// a = 4 ^ 3 = 7
// now, a = 7, b = 3
#define SWAP3(a, b)    \
{                      \
    a = a ^ b;         \
    b = a ^ b;         \
    a = a ^ b;         \
}

int main()
{
    int a = 1;
    int b = 2;
    
    
    printf("a = %d\n", a); 
    printf("b = %d\n", b); 
    
    SWAP3(a ,b);
    // SWAP2(a, b);
    // SWAP1(a, b);

    printf("a = %d\n", a); 
    printf("b = %d\n", b); 
    
    return 0;
}
