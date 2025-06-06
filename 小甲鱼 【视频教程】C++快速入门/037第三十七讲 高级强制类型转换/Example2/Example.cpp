#include <iostream>
#include <string>

class Company
{
public:
    Company(std::string theName, std::string product);
    virtual void printInfo();

protected:
    std::string name;
    std::string product;
};

class TechCompany : public Company
{
public:
    TechCompany(std::string theName, std::string product);
    virtual void printInfo();
};

Company::Company(std::string theName, std::string product)
{
    name = theName;
    this->product = product;
}

void Company::printInfo()
{
    std::cout << "这个公司的名字叫：" << name <<
    "正在生产" << product << "\n";
}

TechCompany::TechCompany(std::string theName, std::string product) : Company(theName, product)
{
}

void TechCompany::printInfo()
{
    std::cout << name << "公司大量生产了 " << product << "这款产品!\n";
}

int main()
{
    Company *company = new Company("APPLE", "Iphone");
    TechCompany *tecCompany = dynamic_cast<TechCompany *>(company);

    if( tecCompany != NULL )
    {
        std::cout << "成功!\n";
    }
    else
    {
        std::cout << "悲催!\n";
    }

    delete company;

    company = NULL;
    tecCompany = NULL;

    return 0;
}
