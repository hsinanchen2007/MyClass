// https://ide.geeksforgeeks.org/KnQXhmFWcm

#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20};
    int *p3 = arr;
    cout << *++p3 << " ";
    cout << arr[0] << " " <<
        arr[1] << " " << *p3;
    return 0;
}

// 20 10 20 20
