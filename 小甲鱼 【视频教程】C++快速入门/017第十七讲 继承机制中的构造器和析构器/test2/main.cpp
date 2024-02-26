#include <iostream>
#include <string>

class Animal
{
public:
    std::string mouth;
    std::string name;

    Animal(std::string theName);
    void eat();
    void sleep();
    void drool();
};

class Pig : public Animal
{
public:
    void climb();
    Pig(std::string theName);
};

class Turtle : public Animal
{
public:
    void swim();
    Turtle(std::string theName);
};

Animal::Animal(std::string theName)
{
    name = theName;
}

void Animal::eat()
{
    std::cout << "I'm eatting!" << std::endl;
}

void Animal::sleep()
{
    std::cout << "I'm sleeping!Don't disturb me!" << std::endl;
}

void Animal::drool()
{
    std::cout << "���ǹ��ģ�����ĸ���һ�����ˮ������������ˮ������" << std::endl;
}

Pig::Pig(std::string theName) : Animal(theName)
{
}

void Pig::climb()
{
    std::cout << "����һ��ֻƯ����Сĸ�����һ��������������������ꡣ����" << std::endl;
}

Turtle::Turtle(std::string theName) : Animal(theName)
{
}

void Turtle::swim()
{
    std::cout << "����һֻС���㣬��ĸ����ץ�ҵ�ʱ���Ҿ��ε��������������" << std::endl;
}

int main()
{
    Pig pig("С����");
    Turtle turtle("С����");

    std::cout << "��ֻ���������: " << pig.name << std::endl;
    std::cout << "ÿֻ�ڹ궼�и�ΰ�������: " << turtle.name << std::endl;

    pig.eat();
    turtle.eat();
    pig.climb();
    turtle.swim();

    return 0;
}
