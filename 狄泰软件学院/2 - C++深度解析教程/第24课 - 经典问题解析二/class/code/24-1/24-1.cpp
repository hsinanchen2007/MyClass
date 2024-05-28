#include <stdio.h>

class Member
{
    const char* ms;
public:
    Member(const char* s)
    {
        printf("Member(const char* s): %s\n", s);

        ms = s;
    }
    ~Member()
    {
        printf("~Member(): %s\n", ms);
    }
};

class Test
{
    Member mA;
    Member mB;
public:
    // Note that the order of definition is mA then mB. 
    // So even the initialization list is mB then mA, 
    // they will be initialized by same order of their
    // definition, which is mA then mB
    Test() : mB("mB"), mA("mA")
    {
        printf("Test()\n");
    }

    ~Test()
    {
        printf("~Test()\n");
    }
};

// For global or static objects, they will be created
// first before main()
Member gA("gA");

int main()
{
    // The program is to demonstrate that the order
    // of constructor and destructor
    // For constructor, it will try to create its
    // parent class, then class of its initialization
    // list, then finally itself
    // For destructor, the order will be reverse of 
    // its constructor

    Test t;

    return 0;
}
