#include<iostream>
using namespace std;

class Point{
    private:
        int x, y;
    public:
        Point(){
            x = 0;
            y = 0;
        }
        Point(int x1, int y1){
            x = x1;
            y = y1;
        }
        void print(){
            cout << x << " " << y << endl;
        }
};

int main()
{
    Point p1, p2(10, 20);
    p1.print();
    p2.print();
    Point *ptr = new Point(5, 10);
    ptr -> print();
    return 0;
}



#include<iostream>
using namespace std;

class Point{
    private:
        int x, y;
    public:
        Point() : x(0), y(0){
           
        }
        Point(int x1, int y1) : x(x1), y(y1){
            
        }
        void print(){
            cout << x << " " << y << endl;
        }
};

int main()
{
    Point p1, p2(10, 20);
    p1.print();
    p2.print();
    Point *ptr = new Point(5, 10);
    ptr -> print();
    return 0;
}



#include<iostream>
using namespace std;

class Test{
    public:
        Test(){cout << "Default\n"; }
        Test(int x){cout << "Parameterised\n"; }
};

class Main{
    Test t;
    public:
        Main(){
            t=Test(10);
        }
};

int main()
{
    Main m;
    return 0;
}



#include<iostream>
using namespace std;

class Test{
    public:
        Test(){cout << "Default\n"; }
        Test(int x){cout << "Parameterised\n"; }
};

class Main{
    Test t;
    public:
        Main(): t(10){
            
        }
};

int main()
{
    Main m;
    return 0;
}



#include<iostream>
using namespace std;

class Test{
    int *ptr;
    public:
        Test(int x){
            ptr = new int(x); 
        }
        void set(int x){
            *ptr = x;
        }
        void print(){
            cout << *ptr << " ";
        }
};

int main()
{
    Test t1(10);
    Test t2(t1);
    t2.set(20);
    t1.print();
    t2.print();
    return 0;
}



#include<iostream>
using namespace std;

class Test{
    int *ptr;
    public:
        Test(int x){
            ptr = new int(x); 
        }
        Test(const Test &t){
            int val = *(t.ptr);
            ptr = new int (val);
        }
        void set(int x){
            *ptr = x;
        }
        void print(){
            cout << *ptr << " ";
        }
};

int main()
{
    Test t1(10);
    Test t2(t1);
    t2.set(20);
    t1.print();
    t2.print();
    return 0;
}



#include<iostream>
using namespace std;

class Test{
    public:
        Test(){
            cout << "Constructor called" << endl;
        }
        ~Test(){
            cout << "Destructor called" << endl;
        }
};

int main()
{
    Test t1;
    return 0;
}



#include<iostream>
using namespace std;

class Test{
    int x;
    public:
        Test(int i) : x(i){
            cout << "Cons" << x << endl;
        }
        ~Test(){
            cout << "Dest" << x << endl;
        }
};

int main()
{
    Test t1(10);
    Test t2(20);
    return 0;
}








