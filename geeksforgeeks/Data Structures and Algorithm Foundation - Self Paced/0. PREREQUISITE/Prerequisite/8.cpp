// https://ide.geeksforgeeks.org/2NTGVO74JA

#include <iostream>
using namespace std;

void getAddMul(int x, int y, int *mPtr, int *aPtr)
    {
        *mPtr = x * y;
        *aPtr = x + y;
    }
int main()
    {
        int x = 10, y = 20, a, m;
        getAddMul(x, y, &a, &m);
        cout << a << " " << m;
        return 0;
    }

// 200 30
