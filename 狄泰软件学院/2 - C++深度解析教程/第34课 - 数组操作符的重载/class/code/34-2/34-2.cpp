#include <iostream>
#include <string>

using namespace std;

int main()
{
    int a[5] = { 0 };

    for (int i = 0; i < 5; i++)
    {
        a[i] = i;
    }

    for (int i = 0; i < 5; i++)
    {
        cout << *(a + i) << endl;    // cout << a[i] << endl;
        cout << i[a] << endl;
    }

    cout << endl;

    for (int i = 0; i < 5; i++)
    {
        // This is the major tricky part
        // a[n] -> *(a + n) -> *(n + a) -> n[a]
        i[a] = i + 10;    // a[i] = i + 10;
        cout << i[a] << endl;
    }

    for (int i = 0; i < 5; i++)
    {
        cout << *(i + a) << endl;  // cout << a[i] << endl;
        cout << i[a] << endl;
    }

    return 0;
}
