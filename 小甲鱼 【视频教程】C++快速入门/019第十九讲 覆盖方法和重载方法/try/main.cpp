#include <iostream>
#include <string>

class Animal
{
public:
    Animal(std::string theName);
    void eat();
    void sleep();
    void drool();

protected:
    std::string name;
};

class Pig : public Animal
{
public:
    Pig(std::string theName);
    void climb();
    void eat(int eatCount);
};

class Turtle : public Animal
{
public:
    Turtle(std::string theName);
    void swim();
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
    std::cout << "I'm sleeping!Don't disturb me!\n" << std::endl;
}

void Animal::drool()
{
    std::cout << "���ǹ��ģ�����ĸ���һ�����ˮ������������ˮ������\n" << std::endl;
}

Pig::Pig(std::string theName) : Animal(theName)
{
}

void Pig::climb()
{
    std::cout << "����һ��ֻƯ����Сĸ�����һ��������������������ꡣ����\n" << std::endl;
}

void Pig::eat(int eatCount)
{
    std::cout << "�ҳ���" << eatCount << "�����!\n\n";
}

Turtle::Turtle(std::string theName) : Animal(theName)
{
}

void Turtle::swim()
{
    std::cout << "����һֻС���㣬��ĸ����ץ�ҵ�ʱ���Ҿ��ε��������������\n" << std::endl;
}

int main()
{
    Pig pig("С����");
    Turtle turtle("С����");

    // std::cout << "��ֻ���������: " << pig.name << std::endl;                // ����
    // std::cout << "ÿֻ�ڹ궼�и�ΰ�������: " << turtle.name << std::endl;   // ����

    pig.eat();
    turtle.eat();

    pig.eat(15);
    pig.climb();
    turtle.swim();

    return 0;
}
