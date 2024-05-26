#include <stdio.h>

// int func(int x, int = 0);

// in below function, the second parameter didn't have any variable
// but we can still give it a default value. However, we still need 
// that second parameter set w/ default value, otherwise when caller has 2 
// parameters, it will have complication error
int func(int x, int = 0)
{
    return x;
}

int main(int argc, char* argv[])
{
    printf("%d\n", func(1));
    printf("%d\n", func(2, 3));

    return 0;
}



