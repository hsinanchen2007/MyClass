#include <stdio.h>
 
int main(int argc, char *argv[])
{
    // argc will at least one, which is the program itself
    printf("argc = %d\n", argc);

    // iterate all argv elements
    for (int ndx = 0; ndx != argc; ++ndx) {
        printf("argv[%d] --> %s\n", ndx, argv[ndx]);
    }

    // last one is NULL pointer
    printf("argv[argc] = %p\n", (void*)argv[argc]);

    return 0; 
}
