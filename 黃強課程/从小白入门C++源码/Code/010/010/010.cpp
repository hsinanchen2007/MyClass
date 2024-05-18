#include<iostream> 
using  namespace  std; 
 

int  main()
{
	//分配堆内存，4个字节
	int  *pA = new int;
	*pA = 123;
	cout << *pA << endl;

	//分配堆内存时，初始化
	int  *pB = new int(456);
	cout << *pB << endl;

	//分配数组堆内存，并初始化
	int  *pC = new int[3]{66,77,88};
	for (int i = 0; i < 3; ++i)
	{
		cout<<pC[i] << "    ";
	}
	cout <<endl;


	delete  pA;//释放堆内存
	delete  pB;

	delete  []pC;//释放数组堆内存
	 
	return 0;
}