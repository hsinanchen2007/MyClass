// https://ide.geeksforgeeks.org/9fmq3Siu48

#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20};
    int *p2 = arr;
    *p2++;
    cout << arr[0] << " " <<
        arr[1] << " " << *p2;
    return 0;
}

// 11 20 20 
