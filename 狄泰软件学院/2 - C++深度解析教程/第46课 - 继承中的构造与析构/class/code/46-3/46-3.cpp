﻿#include <iostream>
#include <string>

using namespace std;

class Object
{
    string ms;
public:
    Object(string s)
    {
        cout << "Object(string s) : " << s << endl;
        ms = s;
    }
    ~Object()
    {
        cout << "~Object() : " << ms << endl;
    }
};

class Parent : public Object
{
    string ms;
public:
    Parent() : Object("Default")
    {
        cout << "Parent()" << endl;
        ms = "Default";
    }
    Parent(string s) : Object(s)
    {
        cout << "Parent(string s) : " << s << endl;
        ms = s;
    }
    ~Parent()
    {
        cout << "~Parent() : " << ms << endl;
    }
};

class Child : public Parent
{
    Object mO1;
    Object mO2;
    string ms;
public:
    Child() : mO1("Default 1"), mO2("Default 2")
    {
        cout << "Child()" << endl;
        ms = "Default";
    }
    Child(string s) : Parent(s), mO1(s + " 1"), mO2(s + " 2")
    {
        cout << "Child(string s) : " << s << endl;
        ms = s;
    }
    ~Child()
    {
        cout << "~Child() " << ms << endl;
    }
};

int main()
{
    // Object(string s) : cc
    // Parent(string s) : cc
    // Object(string s) : cc 1
    // Object(string s) : cc 2
    // Child(string s) : cc
    //
    // ~Child() cc
    // ~Object() : cc 2
    // ~Object() : cc 1
    // ~Parent() : cc
    // ~Object() : cc
    // 
    // The order of constructor and
    // destructor will be reverse
    Child cc("cc");

    cout << endl;

    return 0;
}
