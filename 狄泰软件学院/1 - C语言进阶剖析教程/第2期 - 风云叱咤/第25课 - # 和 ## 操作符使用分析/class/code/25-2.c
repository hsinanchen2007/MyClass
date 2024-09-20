#include <stdio.h>

// there is a tricky part in below macro definition
// it uses "," to separate two parts, the first part is a printf statement
// and the second part is a return statement, so after calling the macro
// the return value will be f(p), which is the result of the function
#define CALL(f, p) (printf("Call function %s\n", #f), f(p))

// another example, but hard coded the return value to 999
#define CALL2(f, p) (printf("Call function %s\n", #f), f(p), 999)
   
int square(int n)
{
    return n * n;
}

int func(int x)
{
    return x;
}

int main()
{
    int result = 0;
    
    result = CALL(square, 4);           // Call function square
    
    printf("result = %d\n", result);    // result = 16
    
    result = CALL(func, 10);            // Call function func
    
    printf("result = %d\n", result);    // result = 10

    return 0;
}
