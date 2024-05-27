#include <stdio.h>

int i = 1;

struct Test
{
    // only by Test public API can access this variable "i" outside Test class
private:
    int i;

public:
    // The variable "j" can be access public
    int j;

    int getI()
    {
        i = 3;

        return i;
    }
};

int main()
{
    int i = 2;

    Test test;

    test.j = 4;
    // i = 2; The local variable here
    printf("i = %d\n", i);               

    // ::i = 1; The Global variable defined at the beginning
    printf("::i = %d\n", ::i);       

    // Error, class's variable "i" is set inside private
    // printf("test.i = %d\n", test.i);     

    // test.j = 4, class's variable "j" is set as public member
    printf("test.j = %d\n", test.j);   

    // test.getI() = 3, can access Test's public API getI(), then access
    // its private member "i"
    printf("test.getI() = %d\n", test.getI());  

    return 0;
}
