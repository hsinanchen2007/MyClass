#include <iostream>
#include <string>

using namespace std;

class Parent
{
public:
    int mi;
};

class Child : public Parent
{
public:
    int mi;
};

int main()
{
    Child c;
    
    c.mi = 100;    // mi �����������Զ���ģ����ǴӸ���̳еõ��ģ�
    
    return 0;
}