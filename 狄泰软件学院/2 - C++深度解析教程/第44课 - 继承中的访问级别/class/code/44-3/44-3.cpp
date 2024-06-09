#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// smallest object, parent
class Object
{
protected:
    string mName;
    string mInfo;
    string fromC;
public:
    Object()
    {
        mName = "Object";
        mInfo = "Info";

        char tmp[] = { "My C style arrary char for string" };
        // const char tmp[] = {"My C style arrary char for string"}; can work
        // const char *tmp = { "My C style arrary char for string" }; can work
        // char *tmp = { "My C style arrary char for string" }; cannot work as the given is a const char
        // char tmp[] = "My C style arrary char for string"; can work
        // const char *tmp = { "My C style arrary char for string" }; can work

        fromC = tmp;
        cout << fromC << endl;
    }
    string name()
    {
        return mName;
    }
    string info()
    {
        return mInfo;
    }
};

// child class, based on object
class Point : public Object
{
private:
    int mX;
    int mY;
public:
    Point(int x = 0, int y = 0)
    {
        ostringstream s;

        mX = x;
        mY = y;
        mName = "Point";

        s << "P(" << mX << ", " << mY << ")";

        mInfo = s.str();
    }
    int x()
    {
        return mX;
    }
    int y()
    {
        return mY;
    }
};

// child class, based on object
class Line : public Object
{
private:
    Point mP1;
    Point mP2;
public:
    Line(Point p1, Point p2)
    {
        ostringstream s;

        mP1 = p1;
        mP2 = p2;
        mName = "Line";

        s << "Line from " << mP1.info() << " to " << mP2.info();

        mInfo = s.str();
    }
    Point begin()
    {
        return mP1;
    }
    Point end()
    {
        return mP2;
    }
};

int main()
{
    Object o;
    Point p(1, 2);
    Point pn(5, 6);
    Line l(p, pn);

    cout << o.name() << endl;
    cout << o.info() << endl;

    cout << endl;

    cout << p.name() << endl;
    cout << p.info() << endl;

    cout << pn.name() << endl;
    cout << pn.info() << endl;

    cout << endl;

    cout << l.name() << endl;
    cout << l.info() << endl;

    return 0;
}
