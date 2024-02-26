#include <iostream>

class ClxBase
{
public:
    ClxBase()
    {
    };

    ~ClxBase()
    {
    };

    virtual void doSomething()
    {
        std::cout << "Do something in class ClxBase!\n";
    }
};

class ClxDerived : public ClxBase
{
public:
    ClxDerived()
    {
    };

    ~ClxDerived()
    {
        std::cout << "Output from the destructor of class ClxDerived!\n";
    };

    void doSomething()
    {
        std::cout << "Do something in class ClxDerived!\n";
    };
};

int main()
{
    ClxBase *pTest = new ClxDerived;

    pTest -> doSomething();

    delete pTest;

    return 0;
}
