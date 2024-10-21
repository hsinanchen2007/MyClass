#include <iostream>

using namespace std;

int func(int a[], int len)       // ==> (n*n + 2)
{
    int ret = 0;      // 1
    
    for(int i=0; i<len; i++)     
    {
        for(int j=0; j<len; j++) 
        {
            ret += a[i] * a[j];  // n * n
        }
    }
    
    return ret;      // 1
}

int main()
{
    int array[] = {1, 2, 3, 4, 5};
    
    cout << func(array, 5) << endl;
    
    return 0;
}

