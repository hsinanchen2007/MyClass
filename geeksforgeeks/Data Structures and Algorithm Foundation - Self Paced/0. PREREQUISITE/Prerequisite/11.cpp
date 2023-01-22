// https://ide.geeksforgeeks.org/B2gdqFupVI

#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3};
    int *ptr = arr;
    cout << sizeof(arr) << " ";
    cout << sizeof(ptr) << " ";
    return 0;
}

// 12 8
