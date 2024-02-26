#include <iostream>

int main()
{
    int a = 1, b;

    if( b = a-- )     // 此处将a的值-1赋值给b
    {
        std::cout << "Yeah!\n";
    }
    else
    {
        std::cout << "Out!\n";
    }

    return 0;
}
