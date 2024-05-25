#include <stdio.h>

#define FirstValue 1u
#define SecondValue 2.2f

enum
{
    ThirdValue = 333,
    FourthValue = 444,
    // TestValue = 5.5  /* ERROR */
};

int main()
{
    unsigned ui = FirstValue;
    int si = FourthValue;

    printf("FirstValue = %u\n", FirstValue);
    printf("SecondValue = %f\n", SecondValue);

    printf("ThirdValue = %d\n", ThirdValue);
    printf("FourthValue = %d\n", FourthValue);

    printf("ui = %u\n", ui);
    printf("si = %d\n", si);

    /* ERROR:
    0.001f = 1.0;
    FirstValue = 28;
    ThirdValue = 555;
    */
    return 0;
}
