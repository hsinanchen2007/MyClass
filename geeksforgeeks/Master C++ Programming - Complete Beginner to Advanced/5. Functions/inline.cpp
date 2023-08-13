#include<iostream>

using namespace std;

// #define add(x,y) x + y // -> Use Brackets
#define add(x,y) (x+y)

inline int getMax(int x, int y)
{
    return (x>y) ? x : y;
}

int main()
{
    cout << getMax(3,4) << endl;
    cout << 2*add(3,4);
    return 0;
}

