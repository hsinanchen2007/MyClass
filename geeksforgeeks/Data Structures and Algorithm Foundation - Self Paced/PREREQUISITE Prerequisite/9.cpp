// https://ide.geeksforgeeks.org/XKFwFPmYk2

#include <iostream>
using namespace std;

int main() {
    int arr[] = {20, 30, 40, 50};
    int *ptr = arr;
    cout << *(ptr + 2);
}

// 40
