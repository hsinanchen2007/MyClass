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

    printf("union UTest size = %d\n", sizeof(union UTest));     // union UTest size = 4
    printf("&ut.a = %p\n", &ut.a);                              // &ut.a = 006FF978
    printf("&ut.f = %p\n", &ut.f);                              // &ut.f = 006FF978

    printf("struct STest size = %d\n", sizeof(struct STest));   // struct STest size = 8
    printf("&st.a = %p\n", &st.a);                              // &st.a = 00AFFCE0
    printf("&st.f = %p\n", &st.f);                              // &st.f = 00AFFCE4

    printf("ut.a = %d\n", ut.a);                                // ut.a = 987654321
    printf("ut.f = %f\n", ut.f);                                // ut.f = 0.001697

    ut.f = 987654321.0f;

    printf("ut.a = %d\n", ut.a);                                // ut.a = 1315666339
    printf("ut.f = %f\n", ut.f);                                // ut.f = 987654336.000000

    printf("System Endian: %d\n", isLittleEndian());            // System Endian: 1

    return 0;
}

