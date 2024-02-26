#include <iostream>

unsigned long returnFactorial(unsigned short num);

int main()
{
    unsigned short num;

    std::cout << "请输入一个整数: ";
    std::cin >> num;
    std::cout << num << "的阶乘结果是: " << returnFactorial(num) << "\n";

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
