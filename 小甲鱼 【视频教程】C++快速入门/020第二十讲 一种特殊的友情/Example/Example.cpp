#include <iostream>
#include <string>

class Lovers
{
public:
    Lovers(std::string theName);
    void kiss(Lovers *lover);
    void ask(Lovers *lover, std::string something);

protected:
    std::string name;

    friend class Others;    // ���������Ѳ���������������
};

class Boyfriend : public Lovers
{
public:
    Boyfriend(std::string theName);
};

class Girlfriend : public Lovers
{
public:
    Girlfriend(std::string theName);
};

class Others
{
public:
    Others(std::string theName);
    void kiss(Lovers *lover);

protected:
    std::string name;
};

Lovers::Lovers(std::string theName)
{
    name = theName;
}

void Lovers::kiss(Lovers *lover)
{
    std::cout << name << "�������Ǽҵ�" << lover->name << std::endl;
}

void Lovers::ask(Lovers *lover, std::string something)
{
    std::cout << "������" << lover->name << "����" << something << std::endl;
}

Boyfriend::Boyfriend(std::string theName) : Lovers(theName)
{
}

Girlfriend::Girlfriend(std::string theName) : Lovers(theName)
{
}

Others::Others(std::string theName)
{
    name = theName;
}

void Others::kiss(Lovers *lover)
{
    std::cout << name << "��һ��" << lover->name << std::endl;
}

int main()
{
    Boyfriend boyfriend("A��");
    Girlfriend girlfriend("B�");

    Others others("·�˼�");

    girlfriend.kiss(&boyfriend);
    girlfriend.ask(&boyfriend, "ϴ�·���");

    std::cout << "\n������������˵�е�·�˼׵ǳ�������������\n";
    others.kiss(&girlfriend);

    return 0;
}
