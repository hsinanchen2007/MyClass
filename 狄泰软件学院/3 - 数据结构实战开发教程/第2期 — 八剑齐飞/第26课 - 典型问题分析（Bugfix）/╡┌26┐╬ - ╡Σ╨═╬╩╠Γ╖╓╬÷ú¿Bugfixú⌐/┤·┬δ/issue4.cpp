#include <iostream>
#include "StaticLinkList.h"

using namespace std;
using namespace DTLib;

int main()
{
    StaticLinkList<int, 10> list;

    for(int i=0; i<5; i++)
    {
        list.insert(i);
    }

    list.remove(3);

    for(int i=0; i<list.length(); i++)
    {
        cout << list.get(i) << endl;
    }

    return 0;
}
