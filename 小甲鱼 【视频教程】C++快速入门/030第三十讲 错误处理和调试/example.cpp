#include <iostream>

int main()
{
    int a = 1, b;

    if( b = a-- )     // �˴���a��ֵ-1��ֵ��b
    {
        std::cout << "Yeah!\n";
    }
    else
    {
        std::cout << "Out!\n";
    }

    return 0;
}
