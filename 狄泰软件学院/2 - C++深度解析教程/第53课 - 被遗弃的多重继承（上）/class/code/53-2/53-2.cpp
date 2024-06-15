#include <iostream>
#include <string>

using namespace std;

class People
{
    string m_name;
    int m_age;
public:
    People(string name, int age)
    {
        m_name = name;
        m_age = age;
    }
    void print()
    {
        cout << "Name = " << m_name << ", "
             << "Age = " << m_age << endl;
    }
};

// Here is to demonstrate the multiple parent class
// by using "virtual" inherit, note that this is in 
// the middle class, not child or parent class
class Teacher : virtual public People
{
public:
    Teacher(string name, int age) : People(name, age)
    {
    }
};

// Here is to demonstrate the multiple parent class
// by using "virtual" inherit, note that this is in 
// the middle class, not child or parent class
class Student : virtual public People
{
public:
    Student(string name, int age) : People(name, age)
    {
    }
};

class Doctor : public Teacher, public Student
{
public:
    Doctor(string name, int age) : Teacher(name, age), Student(name, age), People(name, age)
    {
    }
};

int main()
{
    Doctor d("Delphi", 33);

    // This will call original parent class's print()
    // and we don't need to specify middle class
    d.print();

    // With virtual inherit, we can still specify the 
    // scope resolution, it will still call parent 
    // print() accordingly without any problem
    // However, if we don't have virtual inhert, 
    // the class objects in the middle will have 
    // duplicated member functions, and child class
    // object will have to specify the middle class
    d.Teacher::print();
    d.Student::print();

    return 0;
}
