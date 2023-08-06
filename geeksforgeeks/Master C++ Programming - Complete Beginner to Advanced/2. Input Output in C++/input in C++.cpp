#include<iostream>
using namespace std;
int main()
{
    string name;
    cout << "Please enter your name \n";
    getline(cin,name);
    // cin >> name; Wrong approach, try giving full name
    cout << "Hi " << name << ", \n"
         << "Welcome to GfG";
    return 0;
}

