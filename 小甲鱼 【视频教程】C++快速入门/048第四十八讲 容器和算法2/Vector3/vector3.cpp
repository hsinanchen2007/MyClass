#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<std::string> names;

    names.push_back("Larry");
    names.push_back("Rola");
    names.push_back("DingDing");
    names.push_back("Joyjoy");
    names.push_back("Michael");
    names.push_back("Lucy");
    names.push_back("Lilei");

    std::sort(names.begin(), names.end());

    std::vector<std::string>::iterator iter = names.begin();

    while( iter != names.end() )
    {
        std::cout << *iter << "\n";
        ++iter;
    }

    return 0;
}
