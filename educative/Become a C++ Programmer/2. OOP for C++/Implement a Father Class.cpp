/*

https://www.educative.io/module/lesson/oop-in-cpp/qVZJD2OJDrp

Challenge 3: Implement a Father Class
In this challenge, we'll implement a base class father and derived classes, son and daughter.

We'll cover the following

Problem Statement
Input
Sample Input
Expected Output
Coding Exercise
Solution Review
Problem Statement
Implement a code which have:

A parent class named Father.
Inside it define:
eye_color
hair_color
void Father_traits() function:
It prints the eye_color and hair_color of the called object
Then, there are two derived classes
Son class
has a private member name
has a function named Son_traits() which prints traits of the Son
Daughter class
has a private member name
has a function named Daughter_traits() which prints traits of the Daughter
The derived classes should
call the method of the Father class which prints the eye_color and the hair_color and for Son 
and Daughter classes prints the name of a respective object.
Input
In Sonclass, eye_color is set to Brown and the hair_color is set to Black and name is set to 
Ralph in parametrized constructor of Son object

In Daughterclass, eye_color is set to Green and the hair_color is set to Golden and name is set 
to Rapunzel in parametrized constructor of Daughter object

Now, print Son_traits and Daughter_traits from their respective objects

Here’s a sample result which you should get.

Sample Input
Daughter obj("Rapunzel","Green","Golden");
obj.Daughter_traits();

Son Obj("Ralph","Brown","Black");
Obj.Son_traits();
Expected Output


Coding Exercise
Implement the code in the problem tab.

Good Luck!

Solution Review
We have implemented Father class which have eye_color and hair_color variables, and a function 
Father_traits() which prints eye_color and hair_color of animal

Now implement Daughter and Son classes inherited publicly from Father class

Daughter has private string name variable and a function Daughter_traits() which calls Father_traits() 
function and prints name of the Daughter

Son has private string name variable and a function Son_traits() which calls Father_traits() 
function and prints name of the Son

Create Son and Daughter object by calling parametrized constructors of the classes and print 
their traits by calling their respective functions

*/

#include <iostream>
using namespace std;

class Father {
  string eye_color;
  string hair_color;
public:
	Father(string eye, string hair) {
    eye_color = eye;
    hair_color = hair;
  }
  
  void father_traits(){
    cout << "Eye color: " << eye_color << endl;
    cout << "Hair color: " << hair_color << endl;
  }
};

class Daughter : public Father {
  string name;
  public:
	Daughter(string nam, string eye, string hair) : Father(eye, hair) {
    name = nam;
  }
  
  void Daughter_traits(){
    father_traits();
    cout << name << " has long hair!\n";
  }
};

class Son : public Father {
  string name;
  public:
	Son(string nam,string eye, string hair): Father(eye, hair) {
    name = nam;
  }
  
  void Son_traits(){
    father_traits();
    cout << name << " has beard!\n";
  }
};

int main ()
{
	Daughter obj("Rapunzel","Green","Golden");
	obj.Daughter_traits();
  
	cout << endl;
  
  Son Obj("Ralph","Brown","Black");
	Obj.Son_traits();
}

// Eye color: Green
// Hair color: Golden
// Rapunzel has long hair!
// 
// Eye color: Brown
// Hair color: Black
// Ralph has beard!