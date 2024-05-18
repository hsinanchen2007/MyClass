#include<stdio.h>
#include<string.h>


//һ���ڴ��
struct  A
{
	int  a;
	char b[10];
};


#define  MaxPoolSize  3

//�ڴ��
struct   MemPool
{

	void  InitPool()
	{
		pArr = new   A[MaxPoolSize]; 
		for (size_t i = 0; i < MaxPoolSize; i++)
		{
			freeArr[i] = &pArr[i]; //��ÿ�����ڴ�ĵ�ַ����δ���������
			usedArr[i] = NULL;
		}   
		freeCount = MaxPoolSize; //��ʼ�����ڴ��С
		usedCount = 0; 
	}


	A  *Alloc()
	{
		if (freeCount > 0)
		{
			  //�����һ����ʼ���䣬�ܱ�֤����ָ������ǰ����������ֵ
			  A  *ret= freeArr[ --freeCount ];
			  freeArr[freeCount] =NULL;//�������NULL
			  usedArr[usedCount++] = ret;
			  return   ret;
		}
		else
		{
			printf("���޿����ڴ棡\n");
			return NULL;
		} 
	}


	void  Free(A  *p)
	{ 
		//���ѷ�����ڴ��в���
		for (size_t   i = 0; i <  usedCount  ; i++)
		{
			if (p == usedArr[i])
			{
				//˵��Ҫ�ͷŵ���usedArrָ���������һ��Ԫ��
				if (i == usedCount - 1)
				{
					freeArr[freeCount++] = p;
					usedArr[i] = NULL; 
					--usedCount;
				}
				else //�������һ��
				{
					freeArr[freeCount++] = p;
					usedArr[i] = usedArr[usedCount -1]; 
					usedArr[--usedCount] = NULL;
				}

				return;
			}
		}

		printf("����ڴ治�����ڴ�ط���ģ�\n");

	}


	void  Print()
	{
		printf("\n--------------------------------------\n");
		
		printf("����   ��");
		for (size_t i = 0; i <  MaxPoolSize; i++)
		{ 
			freeArr[i] == NULL ? printf("NULL     ") : printf("%p   ", freeArr[i]);
		}

		printf("\n");
		printf("�ѷ��䣺");
		for (size_t i = 0; i < MaxPoolSize; i++)
		{
			usedArr[i] == NULL ? printf("NULL     "):printf("%p   ", usedArr[i]);
		}

		printf("\n--------------------------------------\n");
	
	}



	//��Ҫһ���������ڴ�
	A  * pArr;
	//δ������ڴ������
	int    freeCount;
	int    usedCount;

	A *freeArr[MaxPoolSize];
	A *usedArr[MaxPoolSize];
};


int  main()
{

	MemPool  pool;
	pool.InitPool();//��ʼ��

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