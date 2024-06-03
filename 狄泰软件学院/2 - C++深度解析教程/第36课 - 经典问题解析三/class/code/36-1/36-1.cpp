#include <iostream>
#include <string>

using namespace std;

class Test
{
    int* m_pointer;
public:
    Test()
    {
        m_pointer = NULL;
    }
    Test(int i)
    {
        m_pointer = new int(i);
    }
    // copy constructor
    Test(const Test& obj)
    {
        // Original class code example has a bug
        // where it may new one NULL pointer below
        if (obj.m_pointer)
            m_pointer = new int(*obj.m_pointer);
        else 
            m_pointer = NULL;
    }
    // assignment operator overload
    // It is similar to the copy constructor at
    // given parameter, but its return will be
    // *this itself, so its return type will be
    // "type &" as well
    Test& operator = (const Test& obj)
    {
        // for assignment operator overload, we
        // need to check whether the given one
        // is the object itself
        if (this != &obj)
        {
            // Original class code has a bug
            // where it may new one NULL pointer below
            if (m_pointer) delete m_pointer;
            if (obj.m_pointer)
                m_pointer = new int(*obj.m_pointer);
            else
                m_pointer = NULL;
        }

        return *this;
    }
    void print()
    {
        cout << "m_pointer = " << hex << m_pointer << endl;
    }
    ~Test()
    {
        delete m_pointer;
    }
};

int main()
{
    // copy constructor, m_pointer = 1
    // If we just do "Test t1;", original
    // class code has a bug and will cause
    // fatal accidently
    Test t1 = 1;

    // default constructor, m_pointer = 0
    Test t2;

    // assignment operator overload
    // it will create a seperate heap memory
    // of its m_pointer then assign value to
    // m_pointer
    t2 = t1;

    t1.print();
    t2.print();

    // Try to demonstrate the bug (but already fixed here)
    Test t3;
    Test t4 = t3;
    Test t5;
    t5 = t3;

    t3.print();
    t4.print();
    t5.print();

    return 0;
}
