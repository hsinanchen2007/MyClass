#include <iostream>
#include <string>

using namespace std;

class Parent
{
    // if m_a is private, child class will not
    // be able to access it
protected:
    int m_a;
protected:
    int m_b;
public:
    int m_c;

    void set(int a, int b, int c)
    {
        m_a = a;
        m_b = b;
        m_c = c;
    }
};

class Child_A : public Parent
{
public:
    void print()
    {
        cout << "m_a" << m_a << endl;
        cout << "m_b" << m_b << endl;
        cout << "m_c" << m_c << endl;
    }
};

class Child_B : protected Parent
{
public:
    void print()
    {
        cout << "m_a" << m_a << endl;
        cout << "m_b" << m_b << endl;
        cout << "m_c" << m_c << endl;
    }
};

class Child_C : private Parent
{
public:
    void print()
    {
        cout << "m_a" << m_a << endl;
        cout << "m_b" << m_b << endl;
        cout << "m_c" << m_c << endl;
    }
};

int main()
{
    Child_A a;
    Child_B b;
    Child_C c;

    a.m_c = 100;
    // b.m_c = 100;    // Child_B �����̳��� Parent�� �������е� public ��Աȫ������� protected ��Ա�� �������޷�����
    // c.m_c = 100;    // Child_C ˽�м̳��� Parent�� �������еĳ�Աȫ������� private ��Ա�� �������޷�����

    a.set(1, 1, 1);
    // b.set(2, 2, 2);
    // c.set(3, 3, 3);

    a.print();
    b.print();
    c.print();

    return 0;
}
