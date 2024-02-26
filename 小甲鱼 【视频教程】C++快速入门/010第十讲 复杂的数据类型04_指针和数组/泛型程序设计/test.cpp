#include <iostream>

template <typename elemType>
void print( elemType *pBegin, elemType *pEnd )
{
	while( pBegin != pEnd )
	{
		std::cout << *pBegin;
		++pBegin;
	}
}

int main()
{
	int num[5] = { 0, 1, 2, 3, 4 };
	char name[5] = { 'F', 'i', 's', 'h', 'C' };
	
	print( num, num+5 );
	std::cout << '\n';
	print( name, name+5 );
	std::cout << '\n';
	
	return 0;
}

