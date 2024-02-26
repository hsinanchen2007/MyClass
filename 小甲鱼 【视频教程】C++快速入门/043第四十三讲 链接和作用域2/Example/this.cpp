#include "header.h"
#include <iostream>

extern unsigned short thatNum;
static bool printMe = false;

int main()
{
    unsigned short thisNum = 10;

    std::cout << thisNum << "! is equal to " << returnFactorial(thisNum) << "\n\n";

    std::cout << thatNum << "! is equal to " << returnFactorial(thatNum) << "\n\n";

    std::cout << headerNum << "! is equal to " << returnFactorial(headerNum) << "\n\n";

    if(printMe)
    {
        std::cout << "Ð¡¼×ÓãÕæË§£¡\n\n";
    }

    return 0;
}
