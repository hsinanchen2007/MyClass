#include <stdio.h>

int main()
{
    printf("c = %d\n", 5 | 2);
    printf("c = %d\n", 7 ^ 8);
    printf("c = %d\n", 2 ^ 3);

    // 15 >> 2 = ((15 / 2) / 2) = 3
    printf("15 >> 2 = %d\n", (15 >> 2));

    printf("c = %d\n", (15 >> 2) & 13);

    // 10101101 ^ 00111100 = 10010001 = 145
    printf("c = %d\n", 173 ^ 60);

    return 0;
}
