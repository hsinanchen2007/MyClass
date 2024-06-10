#include <iostream>
#include <string>

using namespace std;

class A
{
public:
    int i;
    int j;
    char c;
    double d;
public:
    void print()
    {
        cout << "i = " << i << ", "
             << "j = " << j << ", "
             << "c = " << c << ", "
             << "d = " << d << endl;
    }
};

struct B
{
    int i;
    int j;
    char c;
    double d;
};

int main()
{
    A a;

    cout << "sizeof(A) = " << sizeof(A) << endl;    // 24 bytes
    cout << "sizeof(a) = " << sizeof(a) << endl;
    cout << "sizeof(B) = " << sizeof(B) << endl;    // 24 bytes

    cout << "sizeof(A.i) = " << sizeof(a.i) << endl;
    cout << "sizeof(A.j) = " << sizeof(a.j) << endl;
    cout << "sizeof(A.c) = " << sizeof(a.c) << endl;
    cout << "sizeof(A.d) = " << sizeof(a.d) << endl;

    a.print();

    // class and struct are basically 
    // structure same saved in memory
    // so by using reinterpret_cast,
    // we can access data members
    // from p as well
    B* p = reinterpret_cast<B*>(&a);

    p->i = 1;
    p->j = 2;
    p->c = 'c';
    p->d = 3;

    a.print();

    p->i = 100;
    p->j = 200;
    p->c = 'C';
    p->d = 3.14;

    a.print();

    return 0;
}
