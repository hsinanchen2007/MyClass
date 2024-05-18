#include<stdio.h>
#include<string.h>


//一个内存块
struct  A
{
	int  a;
	char b[10];
};


#define  MaxPoolSize  3

//内存池
struct   MemPool
{

	void  InitPool()
	{
		pArr = new   A[MaxPoolSize]; 
		for (size_t i = 0; i < MaxPoolSize; i++)
		{
			freeArr[i] = &pArr[i]; //把每个块内存的地址赋给未分配的数组
			usedArr[i] = NULL;
		}   
		freeCount = MaxPoolSize; //初始空闲内存大小
		usedCount = 0; 
	}


	A  *Alloc()
	{
		if (freeCount > 0)
		{
			  //从最后一个开始分配，总保证空闲指针数组前部分连续有值
			  A  *ret= freeArr[ --freeCount ];
			  freeArr[freeCount] =NULL;//分配后置NULL
			  usedArr[usedCount++] = ret;
			  return   ret;
		}
		else
		{
			printf("暂无空闲内存！\n");
			return NULL;
		} 
	}


	void  Free(A  *p)
	{ 
		//从已分配的内存中查找
		for (size_t   i = 0; i <  usedCount  ; i++)
		{
			if (p == usedArr[i])
			{
				//说明要释放的是usedArr指针数组最后一个元素
				if (i == usedCount - 1)
				{
					freeArr[freeCount++] = p;
					usedArr[i] = NULL; 
					--usedCount;
				}
				else //不是最后一个
				{
					freeArr[freeCount++] = p;
					usedArr[i] = usedArr[usedCount -1]; 
					usedArr[--usedCount] = NULL;
				}

				return;
			}
		}

		printf("这块内存不是由内存池分配的！\n");

	}


	void  Print()
	{
		printf("\n--------------------------------------\n");
		
		printf("空闲   ：");
		for (size_t i = 0; i <  MaxPoolSize; i++)
		{ 
			freeArr[i] == NULL ? printf("NULL     ") : printf("%p   ", freeArr[i]);
		}

		printf("\n");
		printf("已分配：");
		for (size_t i = 0; i < MaxPoolSize; i++)
		{
			usedArr[i] == NULL ? printf("NULL     "):printf("%p   ", usedArr[i]);
		}

		printf("\n--------------------------------------\n");
	
	}



	//需要一块连续的内存
	A  * pArr;
	//未分配的内存块数量
	int    freeCount;
	int    usedCount;

	A *freeArr[MaxPoolSize];
	A *usedArr[MaxPoolSize];
};


int  main()
{

	MemPool  pool;
	pool.InitPool();//初始化

	pool.Print();

	A  *p1 = pool.Alloc();
	p1->a = 11;
	strcpy(p1->b, "1111");
	printf("%d , %s \n" , p1->a,p1->b);

	pool.Print();


	A  *p2= pool.Alloc();
	p2->a = 22;
	strcpy(p2->b, "2222");
	printf("%d , %s \n", p2->a, p2->b);

	pool.Print();

	A  *p3 = pool.Alloc();
	p3->a = 33;
	strcpy(p3->b, "3333");
	printf("%d , %s \n", p3->a, p3->b);

	pool.Print();

	A*p4 = pool.Alloc();
	printf("%p \n", p4);


	pool.Free(p1);
 
	pool.Print();

	A*p5 = pool.Alloc();
	p5->a = 55;
	strcpy(p5->b, "5555");
	printf("%d , %s \n", p5->a, p5->b);

	pool.Print();

	pool.Free(p2);

	pool.Print();

	return  0;
}