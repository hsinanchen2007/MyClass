#include<iostream>
using namespace std ;

int main()
{
    int x, y;
    cin >> x >> y;
    try
    {
        if(y==0)
            throw 0;
        cout << "Result is " << x/y;
    }
    catch (int x)
    {
        cout << "Division with 0";
    }
    return 0 ;
}



#include<iostream>
using namespace std ;

int main()
{
    double x, y;
    cin >> x >> y;
    try
    {
        if(x == 0.0)
            throw 0;
        if(y == 0)
            throw string("Y is 0");
        if(x + y < 0.0)
            throw (x+y);
    }
    catch(int e1)
    {
        cout << e1;
    }
    catch (string &e2)
    {
        cout << e2;
    }
    catch(...)
    {
        cout << "x+y < 0";
    }
    cout << "\nBye\n";
    return 0 ;
}



#include<iostream>
using namespace std ;
int average(int arr[], int n)
{
    if(n == 0)
        throw string("Array size is 0");
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum = sum + arr[i];
    int res = sum/n;
    return res;
}
int main()
{
    int n; 
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    try 
    {
        int res = average(arr, n);    
        cout << res;
    }
    catch (string &e)
    {
        cout << e;
    }
    cout << "\nBye\n";
    
    return 0 ;
}



#include<iostream>
using namespace std ;
int average(int arr[], int n) throw (string)
{
    if(n == 0)
        throw string("Array size is 0");
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum = sum + arr[i];
    int res = sum/n;
    return res;
}
int main()
{
    int n; 
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    try 
    {
        int res = average(arr, n);    
        cout << res;
    }
    catch (string &e)
    {
        cout << e;
    }
    cout << "\nBye\n";
    
    return 0 ;
}





