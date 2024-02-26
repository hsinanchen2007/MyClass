#include <iostream>
#include "includes\\fishc.h"

int main()
{
    call_love_fishc();

    return 0;
}

void call_love_fishc()
{
    int i, j;
	int n = 10;

	for( i=1-(n>>1); i <= n; i++)
	{
		std::cout << "I love FISHC.com";
		if( i >= 0 )
		{
			for( j=0; j < i; j++)
				std::cout << "  ";
			for( j=1; j <= 2*(n-i)+1; j++ )
		 		std::cout << " *";
			std::cout << std::endl;
		}
		else
		{
			for( j=i; j < 0; j++)
				std::cout << "  ";
			for( j=1; j <= n+2*i+1; j++ )
				std::cout << " *";
			for( j=1; j <= -1-2*i; j++ )
				std::cout << "  ";
			for( j=1; j <= n+2*i+1; j++)
				std::cout << " *";
			std::cout << std::endl;
		}
	}
}
