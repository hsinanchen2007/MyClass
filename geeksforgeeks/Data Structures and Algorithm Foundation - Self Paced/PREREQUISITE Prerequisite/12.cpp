// https://ide.geeksforgeeks.org/wbk0bUdN28

#include <iostream>
using namespace std;

int main() {
    char arr[] = {1, 2, 3};
    char *ptr = arr;
    cout << sizeof(arr) << " ";
    cout << sizeof(ptr) << " ";
    return 0;
}

// 3 8
