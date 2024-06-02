#include <iostream>
#include <string>
#include "IntArray.h"

using namespace std;

int main()
{
    // use 2 level constructor way to 
    // ensure the class object is being
    // created properly
    IntArray* a = IntArray::NewInstance(5);

    if (a != NULL)
    {
        IntArray& array = a->self();

        cout << "array.length() = " << array.length() << endl;

        array[0] = 1;
        array[1] = array[0] + 1;
        array[2] = array[1] + 1;
        array[3] = array[2] + 1;
        array[4] = array[3] + 1;

        for (int i = 0; i < array.length(); i++)
        {
            cout << array[i] << endl;
        }
    }

    delete a;

    return 0;
}
