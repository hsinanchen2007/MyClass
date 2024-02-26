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
    std::cout << "我是公的，看到母的我会流口水，我正在流口水。。。\n" << std::endl;
}

Pig::Pig(std::string theName) : Animal(theName)
{
}

void Pig::climb()
{
    std::cout << "我是一个只漂亮的小母猪猪，我会上树，我正在爬树，嘘。。。\n" << std::endl;
}

void Pig::eat(int eatCount)
{
    std::cout << "我吃了" << eatCount << "碗馄饨!\n\n";
}

Turtle::Turtle(std::string theName) : Animal(theName)
{
}

void Turtle::swim()
{
    std::cout << "我是一只小甲鱼，当母猪想抓我的时候，我就游到海里。。哈哈。。\n" << std::endl;
}

int main()
{
    Pig pig("小猪猪");
    Turtle turtle("小甲鱼");

    // std::cout << "这只猪的名字是: " << pig.name << std::endl;                // 错误
    // std::cout << "每只乌龟都有个伟大的名字: " << turtle.name << std::endl;   // 错误

    pig.eat();
    turtle.eat();

    pig.eat(15);
    pig.climb();
    turtle.swim();

    return 0;
}
