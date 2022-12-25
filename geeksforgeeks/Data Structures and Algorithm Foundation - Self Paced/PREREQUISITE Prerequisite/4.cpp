// https://ide.geeksforgeeks.org/HHHgQBRJrD

#include <iostream>
using namespace std;

int main() {
    int x = 10;
    int *ptr = &x;
    cout << *ptr << " ";
    x = x + 30;
    cout << *ptr << " ";
    cout << ptr << " ";
    *ptr = *ptr + 40;
    cout << x << " ";
    return 0;
}

// 10 40 0x7ffd0b82cdec 80 
