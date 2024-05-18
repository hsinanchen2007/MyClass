#include <stdio.h>

// For pointer or reference, each data member memory usage will be 8 bytes
// (x64) or 4 bytes (x86), already verified in 5-2
struct TRef
{
    char* before;
    char& ref;
    char* after;
};

int main(int argc, char* argv[])
{
    char a = 'a';
    char& b = a;
    char c = 'c';

    TRef r = { &a, b, &c };

    printf("sizeof(r) = %d\n", sizeof(r));                  // 24
    printf("sizeof(r.before) = %d\n", sizeof(r.before));    // 8
    printf("sizeof(r.after) = %d\n", sizeof(r.after));      // 8
    printf("&r.before = %p\n", &r.before);                  // 00000024D6FDFAF8
    printf("&r.after = %p\n", &r.after);                    // 00000024D6FDFB08

    return 0;
}
