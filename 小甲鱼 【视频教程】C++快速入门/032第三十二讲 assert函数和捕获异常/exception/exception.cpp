#include <iostream>
#include <climits>

unsigned long returnFactorial(unsigned short num) throw (const char *);

int main()
{
    unsigned short num = 0;

    std::cout << "������һ������: ";
    while( !(std::cin>>num) || (num<1) )
    {
        std::cin.clear();             // ���״̬
        std::cin.ignore(100, '\n');   // ���������
        std::cout << "������һ��������";
    }
    std::cin.ignore(100, '\n');

    try
    {
        unsigned long factorial = returnFactorial(num);
        std::cout << num << "�Ľ׳�ֵ��: " << factorial;
    }
    catch(const char *e)
    {
        std::cout << e;
    }

    return 0;
}

unsigned long returnFactorial(unsigned short num) throw (const char *)
{
    unsigned long sum = 1;
    unsigned long max = ULONG_MAX;

    for( int i=1; i <= num; i++ )
    {
        sum *= i;
        max /= i;
    }

    if( max < 1 )
    {
        throw "���ߡ������û���̫���޷��ڸü������������׳�ֵ��\n";
    }
    else
    {
        return sum;
    }
}
