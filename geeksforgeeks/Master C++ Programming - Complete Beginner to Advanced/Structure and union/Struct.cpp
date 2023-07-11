#include<iostream>
using namespace std;

typedef struct Point
{
  int x;
  int y;
}P;

int main()
{
    P p;
    p.x = 10;
    p.y = 20;
    cout << p.x << " "
         << p.y;
    return 0;
}



#include<iostream>
using namespace std;

struct Student
{
    int rollNo;
    string name;
    string address;
};

int main()
{
    Student s = {101, "ABC", "xyz"};
    cout << s.rollNo << " " 
         << s.name   << " "
         << s.address<< "\n";
    return 0;
}



#include<stdio.h>

struct Point
{
  int x;
  int y;
};

int main()
{
    struct Point p = {.y = 10, .x = 20};
    printf("%d %d", p.x, p.y);
    return 0;
}



#include<stdio.h>

struct Point
{
  int x;
  int y;
};

int main()
{
    struct Point p = {.y = 10};
    struct Point t;
    printf("%d %d", t.x, p.x);
    return 0;
}



