#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

// C++�汾
class  MemoryBlock
{
public:
	int             nSize; //���ڴ����ܴ�С ����Ԫ����Xÿ����Ԫ��С�������ֽ�Ϊ��λ

	int             nFree;  //���ڴ�黹�ж��ٸ����еĵ�Ԫ

	int             nFirst; //��ǰ���ÿ��е�Ԫ����ţ���0��ʼ

	MemoryBlock*    pNext;  //ָ����һ��MemoryBlock�ڴ��

	char            aData[1]; //���ڱ�Ƿ����ڴ濪ʼ��λ��  

	//.....����ṹ����ȫ���ڴ�


public:
	MemoryBlock(int  unitCount, int  unitSize)
	{
		 nSize = unitCount* unitSize;
		 nFree = unitCount;
		 nFirst = 0;
		 pNext = NULL;

		 char  *p = aData;//��ȡ�ڴ浥Ԫ���׵�ַ

		 for (int i = 0; i < unitCount -1; ++i)
		 {
			 *((short *)p) = i + 1; //��0����¸����������ǲ��ǵ�1��
			  p += unitSize;
		 }

		 *((short *)p) = -1;//���һ��û����һ�����пռ��ˣ�Ϊ-1
	}



	void  *  operator new (size_t  t,  int   size)
	{
		 int  headSize = sizeof(MemoryBlock);
	      return   ::operator  new(headSize + size);
	}
};



//����̶��ڴ���ڴ��
class  MemoryPool
{

public:
	//��ʼ��С (ÿһ��MemoryBlock�г�ʼ�ĵ�Ԫ����)
	int             nInitCount; 

	//(�������ӵ�MemoryBlock�е�Ԫ����)   
	int             nGrowSize; 
	 
	//���䵥Ԫ��С��MemoryBlock��ÿ����Ԫ�Ĵ�С
	int             nUnitSize; 

	//�ڴ������
	MemoryBlock*    pBlock;

public:
	MemoryPool( int  _nInitCount, int  _nGrowSize, int _nUnitSize)
	{
		nInitCount = _nInitCount;
		nGrowSize = _nGrowSize;
		nUnitSize = _nUnitSize;
		pBlock = NULL;
	}

	char  *  Alloc() //ÿ��ֻ���� nUnitSize ��С���ڴ�
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

		if (pB == NULL)//һֱû�ҵ��˿��Է����MemoryBlock��˵���ڴ������
		{
			pB = (MemoryBlock  *) new (nGrowSize  * nUnitSize) MemoryBlock(nGrowSize, nUnitSize);
			assert(pB != NULL);

			pB->pNext = pBlock;
			pBlock = pB; 
		}

		//�õ���һ�����õĿ����ڴ��ַ
		char *pFree = pB->aData + pB->nFirst * nUnitSize;
		//��nFirstֵ��Ϊ��һ�����е����� ���洢�ڵ�ǰ�ڴ��ǰ�����ֽڣ�
		pB->nFirst = *((short*)pFree);
		pB->nFree--;
		return  pFree;  
	}


	void   Free(void  *p)
	{
	  //���������ַ�����ĸ� MemoryBlock ��
		MemoryBlock  *  pB = pBlock;
		while (pB  != NULL  &&   p <  pB->aData   ||  p > pB->aData+  pB->nSize   )
		{
			pB = pB->pNext;
		}
		 
		if (pB!= NULL)//�ҵ���p���ڵ�MemoryBlock
		{
			 //����֮ǰ��������ǰ�����ֽ�ָ��nFirst ����ǰ���е�������
			*((short*)p) = pB->nFirst;

			 //nFirst��ֵָ��ǰ�ͷŵ�
			 pB->nFirst = ((char *)p - pB->aData) / nUnitSize;

			 pB->nFree++;
		}
		else
		{
			printf("���󣬴��ڴ沢���ڴ�ط���ģ�\n");
		}
	
	
	}


	void  Print()
	{

		printf("\n\n\n");

		MemoryBlock  *  pB = pBlock;
		while (pB != NULL )
		{
			printf("\n�׵�ַ��%p   �ܴ�С��%d   ���и���: %d   ��һ�����У�%d  \n",
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