#include<iostream>
using namespace std;

int getMax(int x, int y)
{
    return (x>y) ? x : y;
}
int getMax(int x, int y, int z)
{
    return getMax(getMax(x,y),z);
}
void print(int x)
{
    cout << x << endl;
}
void print(string s)
{
    cout << s << endl;
}
int main()
{
    cout << getMax(3,4)  << endl;
    cout << getMax(2,5,3)<< endl;
    print(23);
    print('a');
    print("abcd");
    return 0;
}

