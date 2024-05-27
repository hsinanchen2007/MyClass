#include <stdio.h>

class Test
{
public:
    Test()
    {
        printf("Test()\n");
    }
    Test(int v)
    {
        printf("Test(int v), v = %d\n", v);
    }
    Test(int v1, int v2)
    {
        printf("Test(int v1, int v2), v1 = %d, v2 = %d\n", v1, v2);
    }
    Test(char c)
    {
        printf("Test(char c), c = %c\n", c);
    }
    Test(char c1, char c2)
    {
        printf("Test(char c1, char c2), c1 = %c, c2 = %c\n", c1, c2);
    }
};

int main()
{
    // C++ constructor can initialize data members
    // by (...) or = {...} ways 
    Test t;                 // Test()
    Test t1(1);             // Test(int v)
    Test t2 = 2;            // Test(int v)
    Test t3 = 'Z';          // Test(char c)
    Test t4 = { 'A', 'B'};  // Test(char c1, char c2)
    Test t5{'c', 'd'};      // Test(char c1, char c2)
    Test t6('e', 'f');      // Test(char c1, char c2)
    Test t7 = { 101, 201 }; // Test(int v1, int v2)
    Test t8(301, 401);      // Test(int v1, int v2)

    int i(100);

    printf("i = %d\n", i);

    return 0;
}
