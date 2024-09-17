#include <stdio.h>

int g = 0;

int f()
{
    printf("In f()...\n");                      // In f()...

    return g++;
}

int main()
{
    /*
        The if statement contains the condition g || f() && f().
        The logical OR (||) operator has lower precedence than the logical AND (&&) operator, 
        so the condition is evaluated as g || (f() && f()).
        Since g is initially 0, the left side of the || operator is false, so the right side 
        (f() && f()) is evaluated.
        The first call to f() prints "In f()..." and returns 0 (since g was 0 before incrementing).
        The second call to f() prints "In f()..." again and returns 1 (since g was 1 before 
        incrementing).
        The result of f() && f() is 0 && 1, which is false.
        Therefore, the entire condition g || f() && f() evaluates to false, and the if block 
        is not executed.
        The printf statement outside the if block prints the current value of g, which is 1.
    */
    if( g || f() && f() )
    {
        printf("In if statement: %d\n", g);
    }
    
    printf("In main(): %d\n", g);               // In main(): 1
    
    return 0;
}
