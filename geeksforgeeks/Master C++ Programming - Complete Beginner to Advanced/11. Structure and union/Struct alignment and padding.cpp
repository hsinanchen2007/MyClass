#include<iostream>
using namespace std;

struct S1
{
    char c1;
    double d1;
    char c2;
};

struct S2
{
    char c1;
    char c2;
    double d1;
};

struct S3
{
    double d1;
    char c1;
    char c2;
};

int main()
{
    cout << sizeof(S1) << ' '
         << sizeof(S2) << ' '
         << sizeof(S3);
    return 0;
}



#include<iostream>
using namespace std;

struct S1
{
    char c1;
    double d1;
    char c2;
};

struct S2
{
    char c1;
    char c2;
    double d1;
};

struct S3
{
    double d1;
    char c1;
    char c2;
};

int main()
{
    cout << sizeof(S1) << ' '
         << sizeof(S2) << ' '
         << sizeof(S3);
    return 0;
}
