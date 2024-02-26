#include <iostream>
#include <string>

class Animal
{
public:
    std::string mouth;

    void eat();
    void sleep();
    void drool();
};

class Pig : public Animal
{
public:
    void climb();
};

class Turtle : public Animal
{
public:
    void swim();
};

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

void Pig::climb()
{
    std::cout << "我是一个只漂亮的小母猪猪，我会上树，我正在爬树，嘘。。。" << std::endl;
}

void Turtle::swim()
{
    std::cout << "我是一只小甲鱼，当母猪想抓我的时候，我就游到海里。。哈哈。。" << std::endl;
}

int main()
{
    Pig pig;
    Turtle turtle;

    pig.eat();
    turtle.eat();
    pig.climb();
    turtle.swim();

    return 0;
}
