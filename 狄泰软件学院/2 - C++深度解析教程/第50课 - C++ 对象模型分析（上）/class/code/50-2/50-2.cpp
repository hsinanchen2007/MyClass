#include <iostream>
#include <string>

/*
    Data alignment in class/struct
    https://blog.csdn.net/feng__shuai/article/details/130476654
    https://zh.wikipedia.org/wiki/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E5%AF%B9%E9%BD%90
    https://en.cppreference.com/w/cpp/language/alignof
    https://en.cppreference.com/w/cpp/language/alignas
*/

using namespace std;

class Demo
{
    int mi;
    int mj;
public:
    Demo(int i, int j)
    {
        mi = i;
        mj = j;
    }

    int getI()
    {
        return mi;
    }

    int getJ()
    {
        return mj;
    }

    int add(int value)
    {
        return mi + mj + value;
    }
};

int main()
{
    Demo d(1, 2);

    cout << "sizeof(d) = " << sizeof(d) << endl;
    cout << "d.getI() = " << d.getI() << endl;
    cout << "d.getJ() = " << d.getJ() << endl;
    cout << "d.add(3) = " << d.add(3) << endl;

    return 0;
}
