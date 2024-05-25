#include <stdio.h>

int main()
{
    int esum = 0;
    int osum = 0;
    int i = 0;

    for(i=1; i<=100; i=i+2)
    {
        osum = osum + i;
        esum = esum + (i + 1);
    }

    printf("osum = %d\n", osum);
    printf("esum = %d\n", esum);

    return 0;
}
