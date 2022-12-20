/*

https://www.educative.io/module/lesson/oop-in-cpp/RMQO93WkwjV

What is Polymorphism?
In this lesson, we will be learning about the basics of polymorphism with the implementation 
details.

We'll cover the following

Definition
Shape Class
Implementation
Rectangle Class
Implementation
Circle Class
Implementation
Explanation of Code
The word Polymorphism is a combination of two Greek words, Poly means many and Morph means forms.

Definition
When we say polymorphism in programming that means something which exhibits many forms or behaviors. 
So far, we have learned that we can add new data and functions to a class through inheritance. 
But what about if we want our derived class to inherit a method from the base class and have a 
different implementation for it? That is when polymorphism comes in, a fundamental concept in OOP 
paradigm.

Shape Class
We are considering here the example of Shape class, which is base class for many shapes like 
Rectangle and Circle. This class contains a function getArea() which calculates the area for the 
derived classes.

Rectangle Class
Consider the Rectangle class which is derived from Shape class. It has two data members, i.e., 
width and height and it returns the Area of the rectangle by using getArea() function.

Circle Class
Consider the Circle class which is derived from Shape class. It has one data member, i.e., radius 
and it returns the Area of the circle by using getArea() function.

Explanation of Code
Polymorphism only works with a pointer and reference types, so we have created a Shape pointer, and 
pointed to the derived class objects. But due to multiple existences of the same functions in classes, 
it will get confused between which class getArea() function it’s calling. The derived classes function 
has a different implementation but the same name and that’s why we are not getting the expected output.

*/

#include <iostream>
using namespace std;

// A simple Shape interface which provides a method to get the Shape's area
class Shape {
  public:
  float getArea(){}
};

// A Rectangle is a Shape with a specific width and height
class Rectangle : public Shape {   // derived form Shape class
  private:
  float width;
  float height;

  public:
  Rectangle(float wid, float heigh) {
    width = wid;
    height = heigh;
  }

  /*
    In object-oriented programming when we allow a subclass or child class to provide a specific implementation 
    of a method that is already provided by one of its superclasses or parent classes is known as Function Overriding.
    getArea() Overridden Function
    As you have already seen the implementation of the function getArea() in the previous lesson, which depicts 
    the concept of overriding.
  */
  float getArea(){
    return width * height; 
  }
};

// A Circle is a Shape with a specific radius
class Circle : public Shape {
  private:
  float radius;

  public:
  Circle(float rad){
    radius = rad; 
  }

  /*
    In object-oriented programming when we allow a subclass or child class to provide a specific implementation 
    of a method that is already provided by one of its superclasses or parent classes is known as Function Overriding.
    getArea() Overridden Function
    As you have already seen the implementation of the function getArea() in the previous lesson, which depicts 
    the concept of overriding.
  */
  float getArea(){
    return 3.14159f * radius * radius; 
  }
};

int main() {
  Rectangle r(2, 6);    // Creating Rectangle object

  Shape* shape = &r;   // Referencing Shape class to Rectangle object

  cout << "Calling Rectangle getArea function: " << r.getArea() << endl;
  cout << "Calling Rectangle from shape pointer: " <<  shape->getArea() << endl <<endl;
  
  Circle c(5);    // Creating Circle object

  shape = &c;   // Referencing Shape class to Circle object
  
  cout << "Calling Circle getArea function: " << c.getArea() << endl;
  cout << "Calling Circle from shape pointer: " <<shape->getArea() << endl << endl; 
}

// Calling Rectangle getArea function: 12
// Calling Rectangle from shape pointer: 0
// 
// Calling Circle getArea function: 78.5397
// Calling Circle from shape pointer: 2.34181e-38

/*
    Advantages of the Method Overriding
    Method overriding is very useful in OOP and have many advantages. Some of them are stated below:

        The derived classes can give its own specific implementation to inherited methods without modifying 
        the parent class methods.

        If a child class needs to use the parent class method, it can use it, and the other classes that want 
        to have different implementation can use the overriding feature to make changes.

    Key Features of Overriding
    Here are some key features of the Method Overriding:

        Overriding needs inheritance and there should be at least one derived class.

        Derived class/es must have the same declaration, i.e., name, same parameters and same return type of 
        the function as of the base class.

        The function in derived class/es must have different implementation from each other.

        The method in the base class must need to be overridden in the derived class.
*/