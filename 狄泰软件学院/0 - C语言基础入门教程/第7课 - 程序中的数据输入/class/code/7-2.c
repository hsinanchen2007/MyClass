#include <stdio.h>

int main()
{
    int i = 0;
    int j = 0;
    int k = 0;

    printf("Input 2 numbers to add:\n");

    scanf("%d%d", &i, &j);

    k = i + j;

    printf("%d + %d = %d\n", i, j, k);

    return 0;
}
