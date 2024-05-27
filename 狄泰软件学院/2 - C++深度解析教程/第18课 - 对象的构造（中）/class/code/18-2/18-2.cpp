#include <stdio.h>

class Test
{
private:
    int m_value;
public:
    Test()
    {
        printf("Test()\n");

        m_value = 0;
    }
    Test(int v)
    {
        printf("Test(int v), v = %d\n", v);

        m_value = v;
    }
    int getValue()
    {
        return m_value;
    }
};

int main()
{
    // Define 3 Test objects arrary where each will be initialized
    // by = {...} way
    Test ta[3] = { Test(), Test(1), Test(2) };

    for (int i = 0; i < 3; i++)
    {
        printf("ta[%d].getValue() = %d\n", i, ta[i].getValue());
    }

    Test t = Test(100);

    printf("t.getValue() = %d\n", t.getValue());

    // Use class{} way to initialize its data members
    Test tb[3] = { Test{}, Test{199}, Test{299} };
    for (int i = 0; i < 3; i++)
    {
        printf("tb[%d].getValue() = %d\n", i, tb[i].getValue());
    }
    return 0;
}
