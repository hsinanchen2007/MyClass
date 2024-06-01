#include <stdio.h>

class TwoPhaseCons
{
private:
    TwoPhaseCons() // 1st level constructor, private
    {
    }
    bool construct() // 2nd level constructor, private
    {
        return true;
    }
public:
    static TwoPhaseCons* NewInstance(); // public constructor API
};

TwoPhaseCons* TwoPhaseCons::NewInstance()
{
    TwoPhaseCons* ret = new TwoPhaseCons();

    // if any error, ensure to clean up data in heap memory 
    // and return NULL 
    if (!(ret && ret->construct()))
    {
        delete ret;
        ret = NULL;
    }

    return ret;
}


int main()
{
    TwoPhaseCons* obj = TwoPhaseCons::NewInstance();

    printf("obj = %p\n", obj);

    delete obj;

    return 0;
}
