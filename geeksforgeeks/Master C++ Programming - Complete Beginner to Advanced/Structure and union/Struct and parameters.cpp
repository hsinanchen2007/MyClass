#include<iostream>
using namespace std;

struct Point
{
  int x;
  int y;
};

int main()
{
    Point p = {10, 20};
    Point *ptr = &p;
    cout << ptr -> x << ' ';
    ptr -> x = 30;
    cout << p.x;
    return 0;
}



#include<iostream>
using namespace std;

struct Point
{
  int x;
  int y;
};

int main()
{
    Point p[3];
    for(int i = 0; i < 3; i++)
    {
        p[i].x = i;
        p[i].y = i*10;
    }
    for(int i = 0; i < 3; i ++)
    {
        cout << p[i].x << ' '
             << p[i].y << '\n';
    }
    return 0;
}



#include<iostream>
using namespace std;

struct Point
{
  int x;
  int y;
};

void print(Point p)
{
    cout << p.x << ' ' << p.y << '\n'; 
}
int main()
{
    Point p = {10,20};
    print(p);
    return 0;
}



#include<iostream>
using namespace std;

struct Student
{
  int roll;
  int age;
  string name;
  string address;
};

void print(const Student &s)
{
   cout << s.roll << ' '
        << s.name << ' '
        << s.age  << ' '
        << s.address;
}

int main()
{
    Student s = {2323, 38, "Sandeep", "GFG"};
    print(s);
    return 0;
}












