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

int Pet::count = 0;         // 注意这一句：他起码做了两件事

Pet::Pet(std::string theName)
{
    name = theName;
    count++;

    std::cout << "一只宠物出生了,名字叫做: " << name << "\n";
}

Pet::~Pet()
{
    count--;
    std::cout << name << "挂掉了\n";
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

    std::cout << "\n已经诞生了" << Pet::getCount() << "只宠物!\n\n";


        Dog dog_2("Tom_2");
        Cat cat_2("Jerry_2");

        std::cout << "\n现在呢，已经诞生了" << Pet::getCount() << "只宠物!\n\n";


    std::cout << "\n现在还剩下 " << Pet::getCount() << " 只宠物!\n\n";

    return 0;
}
