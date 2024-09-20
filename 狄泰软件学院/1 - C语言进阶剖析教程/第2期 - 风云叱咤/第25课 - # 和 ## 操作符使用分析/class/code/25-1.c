#include <stdio.h>

// the # operator can be used to convert a macro argument into a string constant
// note that it does have "side effects" in that it will convert any macros in the 
// argument into their values
#define STRING(x) #x

int main()
{
    
    printf("%s\n", STRING(Hello world!));   // Hello world!
    printf("%s\n", STRING(100));            // 100
    printf("%s\n", STRING(while));          // while
    printf("%s\n", STRING(return));         // return

    return 0;
}
