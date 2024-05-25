#include <stdio.h>

int main()
{
    char dt[] = "abcd";
    char name[] = { "efg" };
    int ds = sizeof(dt);
    int ns = sizeof(name);

    int i = 0;

    printf("dt = %s\n", dt);
    printf("name = %s\n", name);
    printf("dt size = %d\n", ds);
    printf("name size = %d\n", ns);

    printf("dt array value:\n");

    for(i=0; i<ds; i++)
        printf("%d ", dt[i]);

    printf("\n");

    i = 0;

    while( dt[i] != 0 )
        i++;

    printf("dt length = %d\n", i);

    name[0] = 'x';
    name[1] = 'y';
    name[2] = 'z';

    printf("name = %s\n", name);

    return 0;
}
