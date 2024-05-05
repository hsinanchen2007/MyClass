#include <iostream>
#include <string>

using namespace std;

template < class T >
class Test
{
public:
    Test(T t) 
    { 
        cout << "t = " << t << endl;
    }
};

template < class T >
void func(T a[], int len)
{
    for(int i=0; i<len; i++)
    {
        cout << a[i] << endl;
    }
}


//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

int a = 0;

class Test_1
{
public:
    static const int TS = 1;
};

class Test_2
{
public:
    struct TS
    {
        int value;
    };
};

template
< class T >
void test_class()
{
    typename T::TS * a;        // 1. ͨ����ָ���� T �ڲ����������� TS ����ָ����� a ���Ƽ��Ľ����ʽ��
                               // 2. ʹ�÷�ָ���� T �ڲ��ľ�̬��Ա���� TS ��ȫ�ֱ��� a ���г˷�����
}


int main(int argc, char *argv[])
{
    // test_class<Test_1>();
    test_class<Test_2>();
    
    return 0;
}

