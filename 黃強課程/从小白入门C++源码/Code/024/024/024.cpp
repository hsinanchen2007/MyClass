#include<iostream>
using  namespace  std;

 
class  B
{
public:
	B(int  b1)
	{
		b = b1;
	}

	//希望print中无法改变任何成员变量的值，则把他声明为const  、常成员函数
	void  print()  const
	{
		// a = 100;//不可以，在常成员函数中，无法修改

	     b = 200; //加上了mutable，使得在常成员函数中变成例外
		cout << b << endl;
	}
	  
private:
	    int   a;
	  mutable  int   b;//可变的，易变得
};
 

int  main()
{
	B  b(111);
	b.print();

	return 0;
}