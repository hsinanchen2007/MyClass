#include <iostream>

using namespace std;

template <typename T>
void Swap(T& a, T& b)
{
    T t = a;
    a = b;
    b = t;
}

template <typename T>
class Op
{
public:
    T process(T v)
    {
        return v * v;
    }
};

int main()
{
    int a = 2;
    int b = 1;

    Swap(a, b);

    cout << "a = " << a << " " << "b = " << b << endl;

    double c = 0.01;
    double d = 0.02;

    Swap<double>(d, c);

    cout << "c = " << c << " " << "d = " << d << endl;

    Op<int> opInt;
    Op<double> opDouble;

    cout << "5 * 5 = " << opInt.process(5) << endl;
    cout << "0.3 * 0.3 = " << opDouble.process(0.3) << endl;

    return 0;
}
