#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

//C���԰汾

struct  MemoryBlock
{
 
	int             nSize; //���ڴ����ܴ�С ����Ԫ����Xÿ����Ԫ��С�������ֽ�Ϊ��λ

	int             nFree;  //���ڴ�黹�ж��ٸ����еĵ�Ԫ

	int             nFirst; //��ǰ���ÿ��е�Ԫ����ţ���0��ʼ

	struct MemoryBlock*    pNext;  //ָ����һ��MemoryBlock�ڴ��

	char            aData[1]; //���ڱ�Ƿ����ڴ濪ʼ��λ��  

	//.....����ṹ����ȫ���ڴ� 


};


 
 void  	InitMemoryBlock(struct  MemoryBlock * block , int  unitCount, int  unitSize)
 {
	    block->nSize = unitCount * unitSize;
		block->nFree = unitCount;
		block->nFirst = 0;
		block->pNext = NULL;

		char  *p = block->aData;//��ȡ�ڴ浥Ԫ���׵�ַ

		for (int i = 0; i < unitCount - 1; ++i)
		{
			*((short *)p) = i + 1; //��0����¸����������ǲ��ǵ�1��
			p += unitSize;
		}

		*((short *)p) = -1;//���һ��û����һ�����пռ��ˣ�Ϊ-1
	}



 //����MemoryBlock�ڴ�
 void  *   AllocMemoryBlock( int   size)
 {
		 int  headSize = sizeof(struct MemoryBlock);
		return    malloc(headSize + size);
 }



//����̶��ڴ���ڴ��
struct  MemoryPool
{
	 
	//��ʼ��С (ÿһ��MemoryBlock�г�ʼ�ĵ�Ԫ����)
	int             nInitCount; 

	//(�������ӵ�MemoryBlock�е�Ԫ����)   
	int             nGrowSize; 
	 
	//���䵥Ԫ��С��MemoryBlock��ÿ����Ԫ�Ĵ�С
	int             nUnitSize; 

	//�ڴ������
	struct  MemoryBlock*    pBlock; 
};


 //��ʼ���ڴ��
   void InitMemoryPool(struct MemoryPool *pool , int  _nInitCount, int  _nGrowSize, int _nUnitSize)
	{
	   pool->nInitCount = _nInitCount;
	   pool->nGrowSize = _nGrowSize;
	   pool->nUnitSize = _nUnitSize;
	   pool->pBlock = NULL;
	}


   //�����ڴ�
	char  *  AllocPool(struct MemoryPool *pool ) //ÿ��ֻ���� nUnitSize ��С���ڴ�
	{
		if (pool->pBlock == NULL)
		{
			//����һ���ڴ�
			struct MemoryBlock  *   p = ( struct MemoryBlock  * )AllocMemoryBlock(pool->nInitCount *  pool->nUnitSize );
			assert(p != NULL);

			//��ʼ��
			InitMemoryBlock(p, pool->nInitCount, pool->nUnitSize);
			pool->pBlock = p;
		}

		struct MemoryBlock  *  pB = pool->pBlock;
		while (pB != NULL && pB->nFree == 0)
		{
			pB = pB->pNext;
		}

		if (pB == NULL)//һֱû�ҵ��˿��Է����MemoryBlock��˵���ڴ������
		{
			pB = (struct MemoryBlock  *)AllocMemoryBlock(pool->nGrowSize * pool->nUnitSize);

			//��ʼ��
			InitMemoryBlock(pB, pool->nGrowSize, pool->nUnitSize);

			assert(pB != NULL);

			pB->pNext = pool->pBlock;
			pool->pBlock = pB;
		}

		//�õ���һ�����õĿ����ڴ��ַ
		char *pFree = pB->aData + pB->nFirst * pool->nUnitSize;
		//��nFirstֵ��Ϊ��һ�����е����� ���洢�ڵ�ǰ�ڴ��ǰ�����ֽڣ�
		pB->nFirst = *((short*)pFree);
		pB->nFree--;
		return  pFree;
	}


	void   FreePool(struct MemoryPool *pool , void  *p)
	{
		//���������ַ�����ĸ� MemoryBlock ��
		struct  MemoryBlock  *  pB = pool->pBlock;
		while (pB != NULL && p <  pB->aData || p > pB->aData + pB->nSize)
		{
			pB = pB->pNext;
		}

		if (pB != NULL)//�ҵ���p���ڵ�MemoryBlock
		{
			//����֮ǰ��������ǰ�����ֽ�ָ��nFirst ����ǰ���е�������
			*((short*)p) = pB->nFirst;

			//nFirst��ֵָ��ǰ�ͷŵ�
			pB->nFirst = ((char *)p - pB->aData) / pool->nUnitSize;

			pB->nFree++;
		}
		else
		{
			printf("���󣬴��ڴ沢���ڴ�ط���ģ�\n");
		}


	}


	void  PrintPool(struct MemoryPool *pool)
	{

		printf("\n\n\n");

		struct  MemoryBlock  *  pB = pool->pBlock;
		while (pB != NULL)
		{
			printf("\n�׵�ַ��%p   �ܴ�С��%d   ���и���: %d   ��һ�����У�%d  \n",
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