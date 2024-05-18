#include<iostream> 
using  namespace  std;
 

//主模板
template<int  N>//非类型的参数
struct For
{ 
	static  void  F()
	{
		 cout << "循环的执行语句"<<N<<endl;
		  For<N - 1>::F();//这句是触发递归的核心，从而产生循环
	} 
};
 
//利用全特化终止递归,如果没有这个全特化，将一直死循环递归
template<>
struct For<1>
{
	static  void  F()
	{
		cout << "循环的执行语句" << 1 << endl;
	}
};

void  main()
{
	  //编译期的for循环
	   For<100>::F();
}