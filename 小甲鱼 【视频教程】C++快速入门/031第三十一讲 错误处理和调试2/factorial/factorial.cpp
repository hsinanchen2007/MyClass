#include <iostream>

unsigned long returnFactorial(unsigned short num);

int main()
{
    unsigned short num;

    std::cout << "������һ������: ";
    std::cin >> num;
    std::cout << num << "�Ľ׳˽����: " << returnFactorial(num) << "\n";

    return 0;
}

unsigned long returnFactorial(unsigned short num)
{
    unsigned long sum = 1;

    for( int i=1; i <= num; i++ )
    {
        sum *= i;
    }

    return sum;
}
