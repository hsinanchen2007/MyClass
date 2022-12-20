/*

https://www.educative.io/module/lesson/oop-in-cpp/B1B38Q5BoON

Challenge 2: Implement an Animal Class
In this challenge, we'll implement a base class Animal and two derived classes Sheep and Dog.

We'll cover the following

Problem Statement
Input
Sample Input
Sample Output
Coding Exercise
Solution Review
Problem Statement
The code below has:

A parent class named Animal.

Inside it define:
Name
Sound
void Animal_Details() function:
It prints the name and sound of the Animal.
Then there are two derived classes

Dog class
has a private member family
has a function named Dog_detail() which prints detail of the dog
Sheep class
has a private member color
has a function named Sheep_detail() which prints detail of the Sheep
The derived classes should

call the method of the Animal class which prints the name and the sound and for Dog class prints 
the family of dog that is Carnivores and for Sheep class prints the color of sheep White.

Input
Name of Dog is set to Pongo and the Sound is set to woof woof in parametrized constructor of Dog 
object
Name of Sheep is set to Billy and the Sound is set to baaa baaa in parametrized constructor of 
Sheep object
Now, print Dog_detail and Sheep_detail from their respective objects
Here’s a sample result which you should get.

Sample Input
Dog d("Pongo", "Woof Woof");
d.Dog_detail();
Sheep s("Billy", "Baaa Baaa");
s.Sheep_detail();
Sample Output
widget
Coding Exercise
Implement the code in the problem tab.

Good Luck!

Solution Review
We have implemented Animal class which have Name and Sound variables, and a function Animal_detail() 
which prints Name and Sound of animal

Now implement Dog and Sheep classes inherited publicly from Animal class

Sheep has private string color variable and a function Sheep_detail() which calls Animal_detail() 
function and prints color of the sheep

Dog has private string family variable and a function Sheep_detail() which calls Animal_detail() 
function and prints family of the sheep

Create Dog and sheep object by calling parametrized constructors of the classes and print their traits 
by calling their respective functions

*/

#include <iostream>
using namespace std;

class Animal {
  string Name;
  string Sound;
  
  public:
  Animal() {
    Name = "";
    Sound = "";
  }
  
  Animal(string nam, string soun) {
    Name = nam;
    Sound = soun;
  }
  
  void Animal_detail() {
    cout << "Animal Name : " << Name << endl;
    cout << "Animal Sound : " << Sound << endl;
  }
};

class Dog : public Animal {
  
  string family;
  
  public:
  Dog(string N, string S): Animal(N, S) {
    family = "Carnivores";
  }
  void Dog_detail() {
    Animal_detail();
    cout << "Dog's Family : " << family  << endl; 
  }
};

class Sheep : public Animal {
  
  string color;
  
  public:
  Sheep(string N, string S): Animal(N, S) {
    color = "White";
  }
  void Sheep_detail() {
    Animal_detail();
    cout << "Sheep Color: " << color << endl; 
  }
};


int main() {
  Dog d("Pongo", "Woof Woof");
  d.Dog_detail();
  
  cout << endl;
  
  Sheep s("Billy", "Baaa Baaa");
  s.Sheep_detail();
}

// Animal Name : Pongo
// Animal Sound : Woof Woof
// Dog's Family : Carnivores
// 
// Animal Name : Billy
// Animal Sound : Baaa Baaa
// Sheep Color: White
