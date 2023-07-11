#include<iostream>
using namespace std;

void print(const string &s)
{
    cout << s << '\n';
}
void editAndPrint(string &&s)
{
    s = "Hi, " + s;
    cout << s << "\n";
}
int main()
{
    print("Welcome to GeeksforGeeks");
    editAndPrint("Welcome to GeeksforGeeks");
    return 0;
}

