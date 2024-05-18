#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

//C语言版本

struct  MemoryBlock
{
 
	int             nSize; //该内存块的总大小 （单元个数X每个单元大小），以字节为单位

	int             nFree;  //该内存块还有多少个空闲的单元

	int             nFirst; //当前可用空闲单元的序号，从0开始

	struct MemoryBlock*    pNext;  //指向下一个MemoryBlock内存块

	char            aData[1]; //用于标记分配内存开始的位置  

	//.....这个结构下面全是内存 


};


 
 void  	InitMemoryBlock(struct  MemoryBlock * block , int  unitCount, int  unitSize)
 {
	    block->nSize = unitCount * unitSize;
		block->nFree = unitCount;
		block->nFirst = 0;
		block->pNext = NULL;

		char  *p = block->aData;//获取内存单元的首地址

		for (int i = 0; i < unitCount - 1; ++i)
		{
			*((short *)p) = i + 1; //第0块的下个空闲索引是不是第1块
			p += unitSize;
		}

		*((short *)p) = -1;//最后一块没有下一个空闲空间了，为-1
	}



 //分配MemoryBlock内存
 void  *   AllocMemoryBlock( int   size)
 {
		 int  headSize = sizeof(struct MemoryBlock);
		return    malloc(headSize + size);
 }



//分配固定内存的内存池
struct  MemoryPool
{
	 
	//初始大小 (每一个MemoryBlock中初始的单元个数)
	int             nInitCount; 

	//(后面增加的MemoryBlock中单元个数)   
	int             nGrowSize; 
	 
	//分配单元大小，MemoryBlock中每个单元的大小
	int             nUnitSize; 

	//内存块链表
	struct  MemoryBlock*    pBlock; 
};


 //初始化内存池
   void InitMemoryPool(struct MemoryPool *pool , int  _nInitCount, int  _nGrowSize, int _nUnitSize)
	{
	   pool->nInitCount = _nInitCount;
	   pool->nGrowSize = _nGrowSize;
	   pool->nUnitSize = _nUnitSize;
	   pool->pBlock = NULL;
	}


   //分配内存
	char  *  AllocPool(struct MemoryPool *pool ) //每次只返回 nUnitSize 大小的内存
	{
		if (pool->pBlock == NULL)
		{
			//分配一个内存
			struct MemoryBlock  *   p = ( struct MemoryBlock  * )AllocMemoryBlock(pool->nInitCount *  pool->nUnitSize );
			assert(p != NULL);

			//初始化
			InitMemoryBlock(p, pool->nInitCount, pool->nUnitSize);
			pool->pBlock = p;
		}

		struct MemoryBlock  *  pB = pool->pBlock;
		while (pB != NULL && pB->nFree == 0)
		{
			pB = pB->pNext;
		}

		if (pB == NULL)//一直没找到了可以分配的MemoryBlock，说明内存池已满
		{
			pB = (struct MemoryBlock  *)AllocMemoryBlock(pool->nGrowSize * pool->nUnitSize);

			//初始化
			InitMemoryBlock(pB, pool->nGrowSize, pool->nUnitSize);

			assert(pB != NULL);

			pB->pNext = pool->pBlock;
			pool->pBlock = pB;
		}

		//得到第一个可用的空闲内存地址
		char *pFree = pB->aData + pB->nFirst * pool->nUnitSize;
		//把nFirst值改为下一个空闲的索引 （存储在当前内存的前两个字节）
		pB->nFirst = *((short*)pFree);
		pB->nFree--;
		return  pFree;
	}


	void   FreePool(struct MemoryPool *pool , void  *p)
	{
		//考虑这个地址落在哪个 MemoryBlock 上
		struct  MemoryBlock  *  pB = pool->pBlock;
		while (pB != NULL && p <  pB->aData || p > pB->aData + pB->nSize)
		{
			pB = pB->pNext;
		}

		if (pB != NULL)//找到了p所在的MemoryBlock
		{
			//销毁之前先让它的前两个字节指向nFirst （当前空闲的索引）
			*((short*)p) = pB->nFirst;

			//nFirst的值指向当前释放的
			pB->nFirst = ((char *)p - pB->aData) / pool->nUnitSize;

			pB->nFree++;
		}
		else
		{
			printf("错误，此内存并非内存池分配的！\n");
		}


	}


	void  PrintPool(struct MemoryPool *pool)
	{

		printf("\n\n\n");

		struct  MemoryBlock  *  pB = pool->pBlock;
		while (pB != NULL)
		{
			printf("\n首地址：%p   总大小：%d   空闲个数: %d   下一个空闲：%d  \n",
				pB->aData, pB->nSize, pB->nFree, pB->nFirst);

			for (int i = 0; i < pB->nSize / pool->nUnitSize; ++i)
			{
				printf("\t %d", *((int *)(pB->aData + i * pool->nUnitSize)));
			}

			pB = pB->pNext;

			printf("\n---------------------------------------------------------\n");
		}


	}






int main()
{
	struct MemoryPool   pool;
	InitMemoryPool(&pool, 3, 3, 4);

	int  *p1 = (int *)AllocPool(&pool);
	*p1 = 111;

	int  *p2 = (int *)AllocPool(&pool);
	*p2 = 222;
	 
	int  *p3 = (int *)AllocPool(&pool);
	*p3 = 333;

    PrintPool(&pool);

	int  *p4 = (int *)AllocPool(&pool);
	*p4 = 444;

	PrintPool(&pool);


	int  *p5 = (int *)AllocPool(&pool);
	*p5 = 555;

	 PrintPool(&pool);


   FreePool(&pool,  p1);
   FreePool(&pool, p2);
   FreePool(&pool, p3);
   PrintPool(&pool);

	 p1 = (int *)AllocPool(&pool);
	*p1 = 111;

	 p2 = (int *)AllocPool(&pool);
	*p2 = 222;

	 p3 = (int *)AllocPool(&pool);
	*p3 = 333;
	PrintPool(&pool);



	return 0;
}