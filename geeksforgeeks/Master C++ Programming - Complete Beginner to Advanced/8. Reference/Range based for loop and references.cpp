#include<iostream>
using namespace std;

int main()
{
    int arr[] = {10, 20, 30};
    for(int &x : arr)
        x += 2;
    for(int x : arr)
        cout << x << ' ' ;
    cout << '\n';
    string ar[] = {"GFG", "C++ Course", "learning"};
    for(const string &s: ar)
        cout << s << '\n';
    return 0;
}

