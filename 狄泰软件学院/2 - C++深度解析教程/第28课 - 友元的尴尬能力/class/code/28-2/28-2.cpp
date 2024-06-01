#include <stdio.h>

// A->B is friend, B->C is friend
// But A->C doesn't mean they should be friend

class ClassC
{
    const char* n;
public:
    ClassC(const char* n)
    {
        this->n = n;
    }

    // tell compiler that ClassB is my friend
    // so ClassB can access everything in my 
    // ClassC class
    friend class ClassB;
};

class ClassB
{
    const char* n;
public:
    ClassB(const char* n)
    {
        this->n = n;
    }

    void getClassCName(ClassC& c)
    {
        printf("c.n = %s\n", c.n);
    }

    // tell compiler that ClassA is my friend
    // so ClassB can access everything in my 
    // ClassC class
    friend class ClassA;
};

class ClassA
{
    const char* n;
public:
    ClassA(const char* n)
    {
        this->n = n;
    }

    void getClassBName(ClassB& b)
    {
        printf("b.n = %s\n", b.n);
    }

    // A->B is friend, B->C is friend
    // That doesn't mean A-> is also friend
    /*
    void getClassCName(ClassC& c)
    {
        printf("c.n = %s\n", c.n);
    }
    */
};

int main()
{
    ClassA A("A");
    ClassB B("B");
    ClassC C("C");

    // A->B is friend
    A.getClassBName(B);

    // B->C is friend
    B.getClassCName(C);

    return 0;
}
