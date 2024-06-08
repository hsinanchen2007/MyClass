#include <iostream>
#include <string>

using namespace std;

class Memory
{
public:
    Memory()
    {
        cout << "Memory()" << endl;
    }
    ~Memory()
    {
        cout << "~Memory()" << endl;
    }
};

class Disk
{
public:
    Disk()
    {
        cout << "Disk()" << endl;
    }
    ~Disk()
    {
        cout << "~Disk()" << endl;
    }
};

class CPU
{
public:
    CPU()
    {
        cout << "CPU()" << endl;
    }
    ~CPU()
    {
        cout << "~CPU()" << endl;
    }
};

class MainBoard
{
public:
    MainBoard()
    {
        cout << "MainBoard()" << endl;
    }
    ~MainBoard()
    {
        cout << "~MainBoard()" << endl;
    }
};

class Computer
{
    Memory mMem;
    Disk mDisk;
    CPU mCPU;
    MainBoard mMainBoard;
public:
    Computer()
    {
        cout << "Computer()" << endl;
    }
    void power()
    {
        cout << "power()" << endl;
    }
    void reset()
    {
        cout << "reset()" << endl;
    }
    ~Computer()
    {
        cout << "~Computer()" << endl;
    }
};

// HPBook class inherts the Computer class
class HPBook : public Computer
{
    string mOS;
public:
    HPBook()
    {
        mOS = "Windows 8";
    }
    void install(string os)
    {
        mOS = os;
    }
    void OS()
    {
        cout << mOS << endl;
    }
};

// MacBook class inherts the Computer class
class MacBook : public Computer
{
public:
    void OS()
    {
        cout << "Mac OS" << endl;
    }
};

int main()
{
    HPBook hp;

    // hp has not only member functions 
    // of HPBook itself, install() and OS()
    // but also all access to public computer 
    // member functions, power()
    hp.power();
    hp.install("Ubuntu 16.04 LTS");
    hp.OS();

    cout << endl;

    MacBook mac;

    mac.OS();

    // Note that the order of constructor and 
    // destructor are reverse at the end
    return 0;
}
