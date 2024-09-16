#include <stdio.h>

struct TS
{
    // adding this member will change the size of struct TS
    // while empty struct TS is 1 byte (from GitHub Copilot) or 0 byte (from my computer)
    // cannot even compile this program
    int test;
};

int main()
{
    struct TS t1;
    struct TS t2;
    
    printf("sizeof(struct TS) = %d\n", sizeof(struct TS));  // sizeof(struct TS) = 4
    printf("sizeof(t1) = %d, &t1 = %p\n", sizeof(t1), &t1); // sizeof(t1) = 4, &t1 = 0039FC20
    printf("sizeof(t2) = %d, &t2 = %p\n", sizeof(t2), &t2); // sizeof(t2) = 4, &t2 = 0039FC1C
    
    return 0;
}
