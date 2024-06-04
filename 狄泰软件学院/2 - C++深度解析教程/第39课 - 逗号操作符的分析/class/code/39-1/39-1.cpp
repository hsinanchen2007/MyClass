#include <iostream>
#include <string>

using namespace std;

void func(int i)
{
    cout << "func() : i = " << i << endl;
}

int main()
{
    int a[3][3] = {
        (0, 1, 2),
        (3, 4, 5),
        (6, 7, 8)
    };

    // can also use {}
    int b[3][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8}
    };

    int c[3][3] = {0};

    int i = 0;
    int j = 0;

    while (i < 5)
        func(i),    // Note here is ",", not ";"

        i++;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            cout << a[i][j] << endl;
        }
    }

    // For , operator, check/do from left to right
    // i now is 3, nothing happened, and as j is 
    // the last one, value 6 will be assigned to 
    // j, not i
    (i, j) = 6;

    cout << "i = " << i << endl;
    cout << "j = " << j << endl;

    return 0;
}
