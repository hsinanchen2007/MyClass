#include <iostream>

void swap( int *x, int *y );

main()
{
	int x, y;
	
	std::cout << "������������ͬ��ֵ��";	
	std::cin >> x >> y;
	
	swap( &x, &y );
	
	std::cout << "�����������" << x << ' ' << y << "\n\n"; 
}

void swap( int *x, int *y )
{
	*x ^= *y;
	*y ^= *x;
	*x ^= *y;
}