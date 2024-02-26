#include <iostream>

int main()
{
	const unsigned short ITEMS = 5;
	
	int intArray[ITEMS] = {1, 2, 3, 4, 5};
	char charArray[ITEMS] = {'F', 'i', 's', 'h', 'C'};
	
	int *intPtr = intArray;
	char *charPtr = charArray;
	
	std::cout << "整型数组输出: " << '\n';
	for( int i=0; i < ITEMS; i++ )
	{
		std::cout << *intPtr << " at " << intPtr << '\n';
		intPtr++;
	}
	
	std::cout << "字符型数组输出: " << '\n';
	for( int i=0; i < ITEMS; i++ )
	{
		std::cout << *charPtr << " at " << charPtr << '\n';
		charPtr++;
	}
	return 0;
}