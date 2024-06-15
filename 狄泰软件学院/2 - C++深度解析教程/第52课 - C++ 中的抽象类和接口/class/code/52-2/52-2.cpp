#include <iostream>
#include <string>

using namespace std;

// This class is just a demo where
// all its member functions are public,
// no data member, all pure virtual 
// member functions, and no real 
// implementation, so this class cannot
// be created with an individual object,
// and this class can be only inherted
// by other class, and the child class
// MUST have real implementation, otherwise
// that child class will be also another
// abstract class. 
// This is a special class called "channel"
// or say it's a general API called by
// different class objects and it will 
// find the corresponding API based on
// given class. 
class Channel
{
public:
    virtual bool open() = 0;
    virtual void close() = 0;
    virtual bool send(char* buf, int len) = 0;
    virtual int receive(char* buf, int len) = 0;
};

int main()
{
    return 0;
}
