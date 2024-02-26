#include <iostream>
#include <string>

class Pet
{
public:
    Pet(std::string theName);
    ~Pet();

    static int getCount();

protected:
    std::string name;

private:
    static int count;
};

class Dog : public Pet
{
public:
    Dog(std::string theName);
};

class Cat : public Pet
{
public:
    Cat(std::string theName);
};

int Pet::count = 0;         // ע����һ�䣺����������������

Pet::Pet(std::string theName)
{
    name = theName;
    count++;

    std::cout << "һֻ���������,���ֽ���: " << name << "\n";
}

Pet::~Pet()
{
    count--;
    std::cout << name << "�ҵ���\n";
}

int Pet::getCount()
{
    return count;
}

Dog::Dog(std::string theName) : Pet(theName)
{
}

Cat::Cat(std::string theName) : Pet(theName)
{
}

int main()
{
    Dog dog("Tom");
    Cat cat("Jerry");

    std::cout << "\n�Ѿ�������" << Pet::getCount() << "ֻ����!\n\n";


        Dog dog_2("Tom_2");
        Cat cat_2("Jerry_2");

        std::cout << "\n�����أ��Ѿ�������" << Pet::getCount() << "ֻ����!\n\n";


    std::cout << "\n���ڻ�ʣ�� " << Pet::getCount() << " ֻ����!\n\n";

    return 0;
}
