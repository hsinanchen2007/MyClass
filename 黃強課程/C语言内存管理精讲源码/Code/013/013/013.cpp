#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

// C++版本
class  MemoryBlock
{
public:
	int             nSize; //该内存块的总大小 （单元个数X每个单元大小），以字节为单位

	int             nFree;  //该内存块还有多少个空闲的单元

	int             nFirst; //当前可用空闲单元的序号，从0开始

	MemoryBlock*    pNext;  //指向下一个MemoryBlock内存块

	char            aData[1]; //用于标记分配内存开始的位置  

	//.....这个结构下面全是内存


public:
	MemoryBlock(int  unitCount, int  unitSize)
	{
		 nSize = unitCount* unitSize;
		 nFree = unitCount;
		 nFirst = 0;
		 pNext = NULL;

		 char  *p = aData;//获取内存单元的首地址

		 for (int i = 0; i < unitCount -1; ++i)
		 {
			 *((short *)p) = i + 1; //第0块的下个空闲索引是不是第1块
			  p += unitSize;
		 }

		 *((short *)p) = -1;//最后一块没有下一个空闲空间了，为-1
	}



	void  *  operator new (size_t  t,  int   size)
	{
		 int  headSize = sizeof(MemoryBlock);
	      return   ::operator  new(headSize + size);
	}
};



//分配固定内存的内存池
class  MemoryPool
{

public:
	//初始大小 (每一个MemoryBlock中初始的单元个数)
	int             nInitCount; 

	//(后面增加的MemoryBlock中单元个数)   
	int             nGrowSize; 
	 
	//分配单元大小，MemoryBlock中每个单元的大小
	int             nUnitSize; 

	//内存块链表
	MemoryBlock*    pBlock;

public:
	MemoryPool( int  _nInitCount, int  _nGrowSize, int _nUnitSize)
	{
		nInitCount = _nInitCount;
		nGrowSize = _nGrowSize;
		nUnitSize = _nUnitSize;
		pBlock = NULL;
	}

	char  *  Alloc() //每次只返回 nUnitSize 大小的内存
	{
		if (pBlock == NULL)
		{
			 MemoryBlock  *   p =(MemoryBlock  *) new (nInitCount * nUnitSize) MemoryBlock(nInitCount, nUnitSize);
			 assert(p != NULL);

			 pBlock = p;
		}

		MemoryBlock  *  pB = pBlock;
		while (pB !=NULL  &&   pB->nFree==0)
		{
			pB = pB->pNext;
		}

		if (pB == NULL)//一直没找到了可以分配的MemoryBlock，说明内存池已满
		{
			pB = (MemoryBlock  *) new (nGrowSize  * nUnitSize) MemoryBlock(nGrowSize, nUnitSize);
			assert(pB != NULL);

			pB->pNext = pBlock;
			pBlock = pB; 
		}

		//得到第一个可用的空闲内存地址
		char *pFree = pB->aData + pB->nFirst * nUnitSize;
		//把nFirst值改为下一个空闲的索引 （存储在当前内存的前两个字节）
		pB->nFirst = *((short*)pFree);
		pB->nFree--;
		return  pFree;  
	}


	void   Free(void  *p)
	{
	  //考虑这个地址落在哪个 MemoryBlock 上
		MemoryBlock  *  pB = pBlock;
		while (pB  != NULL  &&   p <  pB->aData   ||  p > pB->aData+  pB->nSize   )
		{
			pB = pB->pNext;
		}
		 
		if (pB!= NULL)//找到了p所在的MemoryBlock
		{
			 //销毁之前先让它的前两个字节指向nFirst （当前空闲的索引）
			*((short*)p) = pB->nFirst;

			 //nFirst的值指向当前释放的
			 pB->nFirst = ((char *)p - pB->aData) / nUnitSize;

			 pB->nFree++;
		}
		else
		{
			printf("错误，此内存并非内存池分配的！\n");
		}
	
	
	}


	void  Print()
	{

		printf("\n\n\n");

		MemoryBlock  *  pB = pBlock;
		while (pB != NULL )
		{
			printf("\n首地址：%p   总大小：%d   空闲个数: %d   下一个空闲：%d  \n",
				pB->aData ,  pB->nSize, pB->nFree ,pB->nFirst);

			for (int i = 0; i < pB->nSize / nUnitSize; ++i)
			{
				printf("\t %d" ,  *  ((int *) ( pB->aData + i * nUnitSize )));
			}
			 
			pB = pB->pNext;

			printf("\n---------------------------------------------------------\n");
		}
	
	
	}



	 
};



int main()
{
	MemoryPool   pool(3, 3, 4);

	int  *p1 = (int *)pool.Alloc();
	*p1 = 111;

	int  *p2 = (int *)pool.Alloc();
	*p2 = 222;
	 
	int  *p3 = (int *)pool.Alloc();
	*p3 = 333;

	pool.Print();

	int  *p4 = (int *)pool.Alloc();
	*p4 = 444;

	pool.Print();


	int  *p5 = (int *)pool.Alloc();
	*p5 = 555;

	pool.Print();


	pool.Free( p1);
	pool.Free(p2);
	pool.Free(p3);
	pool.Print();

	 p1 = (int *)pool.Alloc();
	*p1 = 111;

	 p2 = (int *)pool.Alloc();
	*p2 = 222;

	 p3 = (int *)pool.Alloc();
	*p3 = 333;
	pool.Print();



	return 0;
}