#include <stdio.h>
#include <string.h>

union UTest
{
    int a;
    float f;
};

struct STest
{
    int a;
    float f;
};

int isLittleEndian()
{
    union
    {
        int i;
        char a[4];
    } test = {0};

    test.i = 1;

    return (test.a[0] == 1);
}

int main()
{
    union UTest ut = {987654321};
    struct STest st = {987654321, 0.1f};

    printf("union UTest size = %d\n", sizeof(union UTest));
    printf("&ut.a = %p\n", &ut.a);
    printf("&ut.f = %p\n", &ut.f);

    printf("struct STest size = %d\n", sizeof(struct STest));
    printf("&st.a = %p\n", &st.a);
    printf("&st.f = %p\n", &st.f);

    printf("ut.a = %d\n", ut.a);
    printf("ut.f = %f\n", ut.f);

    ut.f = 987654321.0f;

    printf("ut.a = %d\n", ut.a);
    printf("ut.f = %f\n", ut.f);

    printf("System Endian: %d\n", isLittleEndian());

    return 0;
}

