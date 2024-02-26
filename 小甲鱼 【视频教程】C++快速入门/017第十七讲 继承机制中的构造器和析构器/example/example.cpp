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
    std::cout << "������๹��������������\n";
    std::cout << "���ڻ��๹������߸���ĳЩ�¡�������\n\n";
}

BaseClass::~BaseClass()
{
    std::cout << "�������������.......\n";
    std::cout << "���ڻ������������Ҳ����ĳЩ�¡�������\n\n";
}

void BaseClass::doSomething()
{
    std::cout << "�Ҹ���ĳЩ�¡�������\n\n";
}

SubClass::SubClass()
{
    std::cout << "�������๹����.....\n";
    std::cout << "�������๹������߻�����ĳЩ�£���������\n\n";
}

SubClass::~SubClass()
{
    std::cout << "��������������......\n";
}

int main()
{
    SubClass subclass;
    subclass.doSomething();

    std::cout << "���£��չ�!\n";

    return 0;
}
