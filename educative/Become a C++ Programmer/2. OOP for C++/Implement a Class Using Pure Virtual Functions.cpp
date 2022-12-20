/*

https://www.educative.io/module/lesson/oop-in-cpp/g7oRzYA67WG

Challenge 2: Implement a Class Using Pure Virtual Functions
In this challenge, we'll implement an account class along with two derived classes saving and current.

We'll cover the following

Problem Statement
Input
Sample Input
Sample Output
Coding Exercise
Solution Review
Problem Statement
Write a code that has:

A parent class named Account.
Inside it define:
a protected float member balance
We have three pure virtual functions:
void Withdraw(float amount)
void Deposit(float amount)
void printBalance()
Then, there are two derived classes
Savings class
has a private member interest_rate set to 0.8
Withdraw(float amount) deducts amount from balance with interest_rate
Deposit(float amount) adds amount in balance with interest_rate
printBalance() displays the balance in the account
Current class
Withdraw(float amount) deducts amount from balance
Deposit(float amount) adds amount in balance
printBalance() displays the balance in the account`
Input
In Savings class, balance is set to 50000 in parametrized constructor of Savings object called by Account class
In Current class, balance is set to 50000 in parametrized constructor of Current object called by Account class
Here’s a sample result which you should get.

Sample Input
  Account * acc[2];
  acc[0] = new Savings(50000);  
  acc[0]->Deposit(1000);
  acc[0]->printBalance();
  
  acc[0]->Withdraw(3000);
  acc[0]->printBalance();
  
  acc[1] = new Current(50000);
  acc[1]->Deposit(1000);
  acc[1]->printBalance();
  
  acc[1]->Withdraw(3000);
  acc[1]->printBalance();   
Sample Output
widget
Coding Exercise
Implement the code in the problem tab.

Good Luck!

Solution Review
We have implemented Account class which has balance float variable, and three pure virtual functions Deposit
(float amount), Withdraw(amount) and printBalance()

Now implement Savings and Current classes inherited publicly from Account class

Savings has private float interest_rate variable and functions:

Withdraw(float amount) deducts amount from balance with interest_rate

Deposit(float amount) adds amount in balance with interest_rate

printBalance() displays the balance in the account

Current has functions:

Withdraw(float amount) deducts amount from balance
Deposit(float amount) adds amount in balance
printBalance() displays the balance in the account`
Create Savings and Current object by calling parametrized constructors of the classes and print their balance 
by calling their respective functions

*/

#include <iostream>
using namespace std;

class Account {
  protected:
  float balance;

  public:
  Account(float bal) {
    balance = bal;
  }

  virtual void Deposit(float amount) = 0;
  virtual void Withdraw(float amount) = 0;
  virtual void printBalance() = 0;
};

class Savings: public Account {
  float interest_rate = 0.8;
  
  public:
  Savings(int bal): Account(bal){}
  
  void Deposit(float amount) {
    balance += amount + (amount * interest_rate);
  }
  
  void Withdraw(float amount) {
    balance -= amount + (amount * interest_rate);
  }
  
  void printBalance() {
    cout << "Balance in your saving account: " << balance << endl;
  }
};

class Current: public Account {
  
  public:
  Current(int bal): Account(bal){}
  
  void Deposit(float amount) {
    balance += amount;
  }
  
  void Withdraw(float amount) {
    balance -= amount;
  }
  
  void printBalance() {
    cout << "Balance in your current account: " << balance << endl;
  }
};

int main() {
  // creating savings account object by calling account pointer
  Account * acc[2];
  acc[0] = new Savings(50000);   // pointing acc to savings object
  acc[0]->Deposit(1000);
  acc[0]->printBalance();
  
  acc[0]->Withdraw(3000);
  acc[0]->printBalance();
  
  cout << endl;
  
  // creating current account object by calling account pointer
  
  acc[1] = new Current(50000);     //// pointing acc to current object
  acc[1]->Deposit(1000);
  acc[1]->printBalance();
  
  acc[1]->Withdraw(3000);
  acc[1]->printBalance();  
}

// Balance in your saving account: 51800
// Balance in your saving account: 46400
// 
// Balance in your current account: 51000
// Balance in your current account: 48000
