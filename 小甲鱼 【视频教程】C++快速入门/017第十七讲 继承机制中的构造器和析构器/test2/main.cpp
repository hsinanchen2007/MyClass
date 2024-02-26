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
    std::cout << "我是公的，看到母的我会流口水，我正在流口水。。。" << std::endl;
}

Pig::Pig(std::string theName) : Animal(theName)
{
}

void Pig::climb()
{
    std::cout << "我是一个只漂亮的小母猪猪，我会上树，我正在爬树，嘘。。。" << std::endl;
}

Turtle::Turtle(std::string theName) : Animal(theName)
{
}

void Turtle::swim()
{
    std::cout << "我是一只小甲鱼，当母猪想抓我的时候，我就游到海里。。哈哈。。" << std::endl;
}

int main()
{
    Pig pig("小猪猪");
    Turtle turtle("小甲鱼");

    std::cout << "这只猪的名字是: " << pig.name << std::endl;
    std::cout << "每只乌龟都有个伟大的名字: " << turtle.name << std::endl;

    pig.eat();
    turtle.eat();
    pig.climb();
    turtle.swim();

    return 0;
}
