#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//Ϊ�˴���Ŀɶ��ԣ������ΪC++�е��� ��  ����struct ����

//��̬����
struct  Array
{
	//�Զ����캯��������ʼ��
	Array()
	{
		grow = 3;
		size = 3;
		n = 0;
		//���䲢��ʼ���ڴ�
		pHead = (int  *)calloc(size  , sizeof(int));
		assert(pHead != NULL); 
	}

	void   AddElem(int  e)
	{
		if (n >= size)//˵����������
		{
			//��Ҫ�����ڴ�
			size += grow; 
			pHead = (int  *)realloc( pHead,   size * sizeof(int)  );
			assert(pHead != NULL);
		}

		pHead[n++] = e; //���Ԫ��
	}
	 

	void  Print()
	{
		printf("\n\n�����ܿռ䣺%d   ,   Ԫ�ظ���: %d  \n",  size,  n);
		for (int i = 0; i < n; ++i)
		{
			printf("%d  " ,  pHead[i]);
		} 
	}


	int    size;//�ܿռ䣬 ���ǹ̶��ģ����������
	int    n;//��ǰ�����Ԫ�ظ���
	int   grow;//ÿ�������ڴ����˵�ʱ��������

	int   *pHead;//�������ʼ��ַ
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