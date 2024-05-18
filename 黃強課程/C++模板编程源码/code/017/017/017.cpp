#include<iostream> 
#include <type_traits>

using  namespace  std;

 
void  main()
{
	//判断是否为void类型
	cout << boolalpha;
	cout << is_void<void>::value << '\n';
	cout << is_void<int>::value << '\n';

	//判断是否是指针
	std::cout << std::boolalpha; 
	std::cout << "int: " << std::is_pointer<int>::value << std::endl;
	std::cout << "int*: " << std::is_pointer<int*>::value << std::endl;
	std::cout << "int**: " << std::is_pointer<int**>::value << std::endl;
	std::cout << "int(*)(int): " << std::is_pointer<int(*)(int)>::value << std::endl;


	//判断是否是数组
	std::cout << boolalpha; 
	std::cout << "int: " << is_array<int>::value << std::endl;
	std::cout << "int[3]: " << is_array<int[3]>::value << std::endl;
	std::cout << "array<int,3>: " << is_array<array<int, 3>>::value << std::endl;
	std::cout << "string: " << is_array<string>::value << std::endl;
	std::cout << "string[3]: " << is_array<string[3]>::value << std::endl;



	struct A {};
	struct B : A {}; 
	//判断是否是基类
	std::cout << std::boolalpha; 
	std::cout << "int, int: " << std::is_base_of<int, int>::value << std::endl;
	std::cout << "A, A: " << std::is_base_of<A, A>::value << std::endl;
	std::cout << "A, B: " << std::is_base_of<A, B>::value << std::endl;
	std::cout << "A, const B: " << std::is_base_of<A, const B>::value << std::endl;
	std::cout << "A&, B&: " << std::is_base_of<A&, B&>::value << std::endl;
	std::cout << "B, A: " << std::is_base_of<B, A>::value << std::endl;
 
	//判断是否是const
	std::cout << std::boolalpha;
	std::cout << std::is_const<int>::value << '\n'; // false
	std::cout << std::is_const<const int>::value << '\n'; // true
	std::cout << std::is_const<const int*>::value << '\n'; // false
	std::cout << std::is_const<int* const>::value << '\n'; // true
	std::cout << std::is_const<const int&>::value << '\n'; // false


	std::cout << "------------------------"<<endl;

	//判断是否是对象
	std::cout << std::boolalpha;
	std::cout << std::is_object<int>::value << '\n';
	std::cout << std::is_object<int&>::value << '\n';
	std::cout << std::is_object<string>::value << '\n';
	std::cout << std::is_object<string&>::value << '\n';
	std::cout << std::is_object<A>::value << '\n';
	std::cout << std::is_object<A&>::value << '\n';

}