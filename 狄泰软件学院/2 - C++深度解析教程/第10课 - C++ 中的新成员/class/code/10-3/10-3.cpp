#include <stdio.h>

namespace First
{
    int i = 0;
}

namespace Second
{
    int i = 1;

    namespace Internal
    {
        struct P
        {
            int x;
            int y;
        };
    }
}

int main()
{
    // make it available to First's i
    using namespace First;

    // make it available to Second::Internal::P
    using Second::Internal::P;

    // To access i, as using namespace First is already set,
    // we can access First's i directly
    printf("First::i = %d\n", i);

    // To access Second's i, we need to specify Second::i
    printf("Second::i = %d\n", Second::i);

    // Due to using Second::Internal::P, we can access P
    // directly
    P p = { 2, 3 };

    printf("p.x = %d\n", p.x);
    printf("p.y = %d\n", p.y);

    return 0;
}