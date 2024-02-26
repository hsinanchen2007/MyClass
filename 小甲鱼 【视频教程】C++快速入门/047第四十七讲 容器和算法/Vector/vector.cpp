#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<std::string> names;

    names.push_back("Ğ¡¼×Óã");
    names.push_back("Ğ¡ÓÉÓã");

    for( int i=0; i < names.size(); i++ )
    {
        std::cout << names[i] << "\n";
    }

    return 0;
}
