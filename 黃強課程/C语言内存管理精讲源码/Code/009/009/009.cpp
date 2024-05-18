#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//为了代码的可读性，将设计为C++中的类 ，  利用struct 代替

//动态数组
struct  Array
{
	//自动构造函数，它初始化
	Array()
	{
		grow = 3;
		size = 3;
		n = 0;
		//分配并初始化内存
		pHead = (int  *)calloc(size  , sizeof(int));
		assert(pHead != NULL); 
	}

	void   AddElem(int  e)
	{
		if (n >= size)//说明数组满了
		{
			//需要扩大内存
			size += grow; 
			pHead = (int  *)realloc( pHead,   size * sizeof(int)  );
			assert(pHead != NULL);
		}

		pHead[n++] = e; //添加元素
	}
	 

	void  Print()
	{
		printf("\n\n数组总空间：%d   ,   元素个数: %d  \n",  size,  n);
		for (int i = 0; i < n; ++i)
		{
			printf("%d  " ,  pHead[i]);
		} 
	}


	int    size;//总空间， 不是固定的，可以增大的
	int    n;//当前数组的元素个数
	int   grow;//每次数组内存满了的时候，增长量

	int   *pHead;//数组的起始地址
};



int  main()
{

	Array  arr; 

	arr.AddElem(1);
	arr.AddElem(2);
	arr.AddElem(3);
	arr.AddElem(4);
	arr.AddElem(5);
	arr.AddElem(6);
	arr.AddElem(7);
	arr.AddElem(8);  
	arr.Print(); 

	arr.AddElem(11);
	arr.AddElem(22);
	arr.AddElem(33);
	arr.AddElem(44);
	arr.AddElem(55);  
	arr.Print();

	return  0;
}