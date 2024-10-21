#include <iostream>
#include "StaticLinkList.h"
#include "DynamicArray.h"

using namespace std;
using namespace DTLib;

int main()
{
    DynamicArray< DynamicArray<int> > d;

    d.resize(3);

    for(int i=0; i<d.length(); i++)
    {
        d[i].resize(i + 1);
    }

    for(int i=0; i<d.length(); i++)
    {
        for(int j=0; j<d[i].length(); j++)
        {
            d[i][j] = i + j;
        }
    }

    for(int i=0; i<d.length(); i++)
    {
        for(int j=0; j<d[i].length(); j++)
        {
            cout << d[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}

