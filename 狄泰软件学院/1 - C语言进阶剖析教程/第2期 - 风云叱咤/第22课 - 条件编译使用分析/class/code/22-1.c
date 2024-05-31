// #include <stdio.h>

#define C 1

int main()
{
    const char* s;

    #if( C == 1 )
        s = "This is first printf...\n";
    #else
        s = "This is second printf...\n";
    #endif

    // printf("%s", s);
    
    return 0;
}
