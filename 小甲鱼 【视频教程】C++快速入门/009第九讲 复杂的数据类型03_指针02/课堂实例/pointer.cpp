#include <iostream>

int main()
{
	int a = 123;
	float b = 3.14;
	char c = 'C';
	unsigned long d = 19880808;
	std::string e = "I love FishC!";
	
	std::cout << " a ��ֵ��: " << a << "\n";
	std::cout << " b ��ֵ��: " << b << "\n";
	std::cout << " c ��ֵ��: " << c << "\n";
	std::cout << " d ��ֵ��: " << d << "\n";
	std::cout << " e ��ֵ��: " << e << "\n\n";
	
	int *aPointer = &a;
	float *bPointer = &b;
	char *cPointer = &c;
	unsigned long *dPointer = &d;
	std::string *ePointer = &e;
	
	*aPointer = 456;
	*bPointer = 4.13;
	*cPointer = 'F';
	*dPointer = 20111124;
	*ePointer = "I love Beauty!";
	
	std::cout << " a ��ֵ��: " << a << "\n";
	std::cout << " b ��ֵ��: " << b << "\n";
	std::cout << " c ��ֵ��: " << c << "\n";
	std::cout << " d ��ֵ��: " << d << "\n";
	std::cout << " e ��ֵ��: " << e << "\n\n"; 
	
	return 0; 
}