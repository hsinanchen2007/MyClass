#include <iostream>

union mima
{
	unsigned long	birthday;
	unsigned short  ssn;
	char*	pet;
};

int main()
{
	mima mima_1;
	
	mima_1.birthday = 19881301;
	std::cout << mima_1.birthday << "\n";
	
	mima_1.pet = "Chaozai";
	std::cout << mima_1.pet << "\n";
	std::cout << mima_1.birthday << "\n";
	
	return 0;
}