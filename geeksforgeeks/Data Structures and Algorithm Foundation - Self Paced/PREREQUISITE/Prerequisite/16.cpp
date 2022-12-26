// https://ide.geeksforgeeks.org/tRPoIATiGz

#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20};
    int *p3 = arr;
    *++p3;
    cout << arr[0] << " " <<
        arr[1] << " " << *p3;
    return 0;
}

// 10 20 20 
