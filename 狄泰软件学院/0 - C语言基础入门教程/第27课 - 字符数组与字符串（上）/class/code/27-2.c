#include <stdio.h>

int main()
{
    char dt[] = "abcd";
    char name[] = { "efg" };
    int ds = sizeof(dt);
    int ns = sizeof(name);

    int i = 0;

    printf("dt = %s\n", dt);            // dt = abcd
    printf("name = %s\n", name);        // name = efg
    printf("dt size = %d\n", ds);       // dt size = 5
    printf("name size = %d\n", ns);     // name size = 4

    printf("dt array value:\n");        // dt array value: 97 98 99 100 0

    for(i=0; i<ds; i++)
        printf("%d ", dt[i]);

    printf("\n");

    i = 0;

    while( dt[i] != 0 )
        i++;

    printf("dt length = %d\n", i);      // dt length = 4

    name[0] = 'x';
    name[1] = 'y';
    name[2] = 'z';

    printf("name = %s\n", name);        // name = xyz

    return 0;
}
