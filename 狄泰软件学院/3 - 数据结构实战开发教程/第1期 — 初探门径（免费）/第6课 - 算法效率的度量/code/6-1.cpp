/*
    问题： 
    在一个由自然数1-1000中某些数字所组成的数组中，每个数字可能出现零次或者多次。
    设计一个算法，找出出现次数最多的数字。
*/

#include <iostream>

using namespace std;

void search(int a[], int len)     // O(n)
{
    int sp[1000] = {0};
    int max = 0;
    
    for(int i=0; i<len; i++)
    {
        sp[a[i] - 1]++;
    }
    
    for(int i=0; i<1000; i++)
    {
        if( max < sp[i] )
        {
            max = sp[i];
        }
    }
    
    for(int i=0; i<1000; i++)
    {
        if( max == sp[i] )
        {
            cout << i + 1 << endl;
        }
    }
}

int main(int argc, char* argv[])
{
    int a[] = {1, 1, 3, 4, 5, 6, 6, 6, 3, 3};
    
    search(a, sizeof(a)/sizeof(*a));

    return 0;
}
