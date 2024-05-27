#include <stdio.h>

#include <stdio.h>

struct Biology
{
    bool living;
};

struct Animal : Biology
{
    bool movable;

    void findFood()
    {
    }
};

struct Plant : Biology
{
    bool growable;
};

struct Beast : Animal
{
    void sleep()
    {
    }
};

struct Human : Animal
{
    void sleep()
    {
        printf("I'm sleeping...\n");
    }

    void work()
    {
        printf("I'm working...\n");
    }
};

struct Girl : Human
{
    // For Girl class, they don't want to share age and weight
private:
    int age;
    int weight;

public:
    void print()
    {
        age = 22;
        weight = 48;

        printf("I'm a girl, I'm %d years old.\n", age);
        printf("My weight is %d kg.\n", weight);
    }
};

struct Boy : Human
{
    // For Boy class, they don't want to share height and salary
private:
    int height;
    int salary;

public:
    int age;
    int weight;

    void print()
    {
        height = 175;
        salary = 9000;

        printf("I'm a boy, my height is %d cm.\n", height);
        printf("My salary is %d RMB.\n", salary);
    }
};

int main()
{
    Girl g;
    Boy b;

    g.print();

    b.age = 19;
    b.weight = 120;

    // height and salary are not accessible outside the class
    // and its object
    //b.height = 180;

    b.print();

    return 0;
}
