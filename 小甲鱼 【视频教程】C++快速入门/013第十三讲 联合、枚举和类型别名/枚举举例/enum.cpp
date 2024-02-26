#include <iostream>

int main()
{
	enum  weekdays{ Monday, Tuesday, Wednesday, Thursday, Friday };
	
	weekdays today;
	
	today = Monday1;
	std::cout << today << "\n"; // 0
	
	today = Tuesday;
	std::cout << today << "\n"; // 1
}