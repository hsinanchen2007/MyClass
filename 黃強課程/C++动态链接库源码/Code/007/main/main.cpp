#include<iostream>
using namespace std;

_declspec(dllimport)    int  Min(int a, int b);
_declspec(dllimport)     int fun666();

#pragma comment(lib,"../Debug/007.lib")

int  main()
{
	cout << Min(111,222) << endl;
	cout << fun666() << endl;
	return 0;
}