#include<iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter a number:\n";
    cin >> n;
    if(n>0)
    {
        cout << "Positive ";
        if(n%2==0)
        {
            cout << "Even \n";
        }
        else 
        {
            cout << "Odd \n";
        }
    }
    else if(n<0)
    {
        cout << "Negative ";
        if(n%2==0)
        {
            cout << "Even \n";
        }
        else 
        {
            cout << "Odd \n";
        }
    }
    else 
    {
        cout <<"Zero \n" ;
    }
    return 0;
    
}

