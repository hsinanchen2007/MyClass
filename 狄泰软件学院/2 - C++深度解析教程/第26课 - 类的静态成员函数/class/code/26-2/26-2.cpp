#include <stdio.h>

class Demo
{
private:
    int i;
public:
    int getI();

    // now we define static member function
    // which can access either private static
    // member "i" or any task that belongs to
    // the whole class, not individual object
    static void StaticFunc(const char* s);
    static void StaticSetI(Demo& d, int v);
};

int Demo::getI()
{
    return i;
}

// Note that if we implement the static member
// function outside the class, no need to specify
// "static" at the beginning of the function 
void Demo::StaticFunc(const char* s)
{
    printf("StaticFunc: %s\n", s);
}

// by providing the class object, we can 
// also modify the private member
// Note that this private member is 
// not static member so it will need to 
// have a given class object
void Demo::StaticSetI(Demo& d, int v)
{
    d.i = v;
}

int main()
{
    Demo::StaticFunc("main Begin...");

    Demo d;

    Demo::StaticSetI(d, 10);

    printf("d.i = %d\n", d.getI());

    Demo::StaticFunc("main End...");

    return 0;
}
