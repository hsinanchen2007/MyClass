#include "Complex.h"
#include "math.h"

Complex::Complex(double a, double b)
{
    this->a = a;
    this->b = b;
}

double Complex::getA()
{
    return a;
}

double Complex::getB()
{
    return b;
}

double Complex::getModulus()
{
    return sqrt(a * a + b * b);
}

Complex Complex::operator + (const Complex& c)
{
    double na = a + c.a;
    double nb = b + c.b;
    Complex ret(na, nb);
    
    return ret;
}

Complex Complex::operator - (const Complex& c)
{
    double na = a - c.a;
    double nb = b - c.b;
    Complex ret(na, nb);
    
    return ret;
}

Complex Complex::operator * (const Complex& c)
{
    double na = a * c.a - b * c.b;
    double nb = a * c.b + b * c.a;
    Complex ret(na, nb);
    
    return ret;
}

Complex Complex::operator / (const Complex& c)
{
    double cm = c.a * c.a + c.b * c.b;
    double na = (a * c.a + b * c.b) / cm;
    double nb = (b * c.a - a * c.b) / cm;
    Complex ret(na, nb);
    
    return ret;
}
    
bool Complex::operator == (const Complex& c)
{
    return (a == c.a) && (b == c.b);
}

bool Complex::operator != (const Complex& c)
{
    return !(*this == c);
}

// Note that here, given parameter "c" is the right hand
// side one, for example obj1 = obj2, c is obj2
// First, we need to see if obj1 and obj2 are same or not
// then assign value accordingly
// Second, we need to return "*this" and the returned
// type is "type &", not type. The reason is that
// we may have a chain assignment, for example, we can do
// obj1 = obj2 = obj3, so once we got value from obj3 to 
// obj2, we need to return obj2 itself so we can keep
// applying obj2 to obj1
// So basically, assignment operator overload should be
// syntax: type& operator = (const type& v1)
// Also, C++ assignment overload can be only within 
// class, it cannot be a global function
Complex& Complex::operator = (const Complex& c)
{
    if( this != &c )
    {
        a = c.a;
        b = c.b;
    }
    
    return *this;
}