#include <stdio.h>
#include <string.h>

enum Day { MON = 1, TUE, WED, THU, FRI, SAT, SUN };
enum Season { Spring, Summer = 3, Autumn, Winter = -1 };

enum { CONSTANT = 12345 };

int main()
{
    enum Day d = TUE;
    enum Season s = Winter;

    int i = SUN;
    int j = Autumn;

    printf("d = %d\n", d);   // 2
    printf("s = %d\n", s);   // -1
    printf("i = %d\n", i);   // 7
    printf("j = %d\n", j);   // 4

    d = 0;
    s = -2;

    printf("d = %d\n", d);      // d = 0
    printf("s = %d\n", s);      // s = -2

    printf("sizeof(enum Day) = %d\n", sizeof(enum Day));            // sizeof(enum Day) = 4
    printf("sizeof(enum Season) = %d\n", sizeof(enum Season));      // sizeof(enum Season) = 4

    printf("CONSTANT = %d\n", CONSTANT);                            // CONSTANT = 12345

    // CONSTANT = 54321;

    return 0;
}

