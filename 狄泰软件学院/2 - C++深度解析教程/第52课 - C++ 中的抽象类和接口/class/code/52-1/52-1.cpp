#include <iostream>
#include <string>

using namespace std;

class Shape
{
public:
    // Here we define a pure abstract class
    // this class can be inherited only
    // and cannot create any class object
    virtual double area() = 0;
};

class Rect : public Shape
{
    int ma;
    int mb;
public:
    Rect(int a, int b)
    {
        ma = a;
        mb = b;
    }
    // real object that can calculate
    // its area
    double area()
    {
        return ma * mb;
    }
};

class Circle : public Shape
{
    int mr;
public:
    Circle(int r)
    {
        mr = r;
    }
    // real object that can calculate
    // its area
    double area()
    {
        return 3.14 * mr * mr;
    }
};

// To achieve Polymorphism, by given object, 
// return its corresponding area()
void area(Shape* p)
{
    double r = p->area();

    cout << "r = " << r << endl;
}

int main()
{
    Rect rect(1, 2);
    Circle circle(10);

    area(&rect);
    area(&circle);

    return 0;
}
