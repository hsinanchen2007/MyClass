#include <stdio.h>

#define _ADD_(a, b) a + b
#define _MUL_(a, b) a * b
#define _MIN_(a, b) ((a) < (b) ? (a) : (b))

int main()
{
    int i = 1;
    int j = 10;
    
    // 1 + 2 * 3 + 4 = 11
    printf("%d\n", _MUL_(_ADD_(1, 2), _ADD_(3, 4)));

    // 1 < 10 ? 1 : 10 = 2
    printf("%d\n", _MIN_(i++, j));
    
    return 0;
}
