#include <iostream>

void changeAge( int *age, int newAge );

// �����Ҫʵ�ּƻ����ܣ���Ҫ��ô�ģ�
 
main()
{
	int age = 24;
	std::cout << "My age is " << age << "\n";
	
	changeAge( &age, age+1 );
	
	std::cout << "Now my age is " << age << "\n";
}

void changeAge( int *age, int newAge )
{
	*age = newAge;
	std::cout << "In this , my age is " << *age << "\n";
}

