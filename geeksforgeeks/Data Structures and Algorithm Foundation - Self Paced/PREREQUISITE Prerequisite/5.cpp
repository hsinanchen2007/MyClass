// https://ide.geeksforgeeks.org/Nj2ndONxxo

#include <iostream>
using namespace std;

int main() {
    int *p1;
    cout << p1 << " ";
    cout << *p1 << " ";
    return 0;
}

// the program may run into fatal as we are trying to print out an uninitialized pointer
// which may point to garbage number or memory location
