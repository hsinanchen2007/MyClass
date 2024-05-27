#include <stdio.h>

typedef void(PF)(int);

struct Point
{
    int x;
    int y;
};

int main()
{
    // The root cause is below fake address
    // which is not real one in the program
    // This can cause any fatal or unexpected
    // result 
    int v = 0x12345;

    PF* pf = (PF*)v;
    char c = char(v);
    Point* p = (Point*)v;

    pf(5);

    printf("p->x = %d\n", p->x);
    printf("p->y = %d\n", p->y);

    return 0;
}
