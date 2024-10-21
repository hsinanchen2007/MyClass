#include <iostream>

using namespace std;

double divide(double a, double b)
{
    const double delta = 0.000000000000001;
    double ret = 0;

    if( !((-delta < b) && (b < delta)) ) {
        ret = a / b;
    }
    else {
        throw 0;   // 产生除 0 异常
    }

    return ret;
}

void Demo1()
{
    try
    {
        throw 'c';
    }
    catch(int i)
    {
        cout << "catch(int i)" << endl;
    }
    catch(double d)
    {
        cout << "catch(double d)" << endl;
    }
    catch(char c)
    {
        cout << "catch(char c)" << endl;
    }
}

void Demo2()
{
    throw 0.0001; // "D.T.Software";   // const char*
}

int main()
{
    cout << "main() begin" << endl;

    try
    {
        double c = divide(1, 1);

        cout << "c = " << c << endl;
    }
    catch(...)
    {
        cout << "Divided by zero..."  << endl;
    }

    Demo1();

    try
    {
        Demo2();
    }
    catch(char* c)
    {
        cout << "catch(char* c)" << endl;
    }
    catch(const char* cc)
    {
        cout << "catch(char* cc)" << endl;
    }
    catch(...)
    {
        cout << "catch(...)" << endl;
    }

    cout << "main() end" << endl;

    return 0;
}
