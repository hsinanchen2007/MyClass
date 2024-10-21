/*
    问题：给定一个整数 n，编程求解 1 + 2 + 3 + ... + n 的和。
    
    QQ交流群： 199546072
    
    D.T.Software
*/


#include <iostream>

using namespace std;

long sum1(int n)
{
    long ret = 0;
    int* array = new int[n];
    
    for(int i=0; i<n; i++)
    {
        array[i] = i + 1;
    }
    
    for(int i=0; i<n; i++)
    {
        ret += array[i];
    }
    
    delete[] array;
    
    return ret;
}

long sum2(int n)
{
    long ret = 0;
    
    for(int i=1; i<=n; i++)
    {
        ret += i;
    }
    
    return ret;
}

long sum3(int n)
{
    long ret = 0;
    
    if( n > 0 )
    {
        ret = (1 + n) * n / 2;
    }
    
    return ret;
}

int main()
{
    cout << "sum1(100) = " << sum1(100) << endl;
    cout << "sum2(100) = " << sum2(100) << endl;
    cout << "sum3(100) = " << sum3(100) << endl;
    
    return 0;
}
