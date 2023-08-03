#include <iostream>
using namespace std;
int main()
{
	int a = 10, b = 20;
	cout << a << " " << b << "\n";
	int temp = a;
	a = b;
	b = temp;
	cout << a << " " << b << "\n";
	return 0;
}
