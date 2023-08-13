#include<iostream>
using namespace std;

void fun1 (int x)
{
    x += 2;
}
void fun2 (int &x)
{
    x += 2;
}
int main()
{
    int x = 2;
    fun1(x);
    cout << x << ' ';
    fun2(x);
    cout << x;
    return 0;
}

