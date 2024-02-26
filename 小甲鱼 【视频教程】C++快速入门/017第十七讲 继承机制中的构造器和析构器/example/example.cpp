#include <iostream>
#include <string>

class BaseClass
{
public:
    BaseClass();
    ~BaseClass();

    void doSomething();
};

class SubClass : public BaseClass
{
public:
    SubClass();
    ~SubClass();
};

BaseClass::BaseClass()
{
    std::cout << "进入基类构造器。。。。。\n";
    std::cout << "我在基类构造器里边干了某些事。。。。\n\n";
}

BaseClass::~BaseClass()
{
    std::cout << "进入基类析构器.......\n";
    std::cout << "我在基类析构器里边也干了某些事。。。。\n\n";
}

void BaseClass::doSomething()
{
    std::cout << "我干了某些事。。。。\n\n";
}

SubClass::SubClass()
{
    std::cout << "进入子类构造器.....\n";
    std::cout << "我在子类构造器里边还干了某些事．．．．．\n\n";
}

SubClass::~SubClass()
{
    std::cout << "进入子类析构器......\n";
}

int main()
{
    SubClass subclass;
    subclass.doSomething();

    std::cout << "完事，收工!\n";

    return 0;
}
