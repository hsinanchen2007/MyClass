#include<stdio.h>
#include<stdlib.h>


//��ӡ����
void Print(int arr[], int  N) 
{ 
	printf("\n");

	for (int i = 0; i < N; ++i)
	{
		printf("%d   ", arr[i]);
	} 
}

//ѡ������ -����
void   SelectionSort(int arr[] ,int  N)
{

	//��Ҫ�Ƚ�N-1�� 
	for (int i = 0; i < N - 1; ++i)
	{
		//Ҫ��δ�����Ԫ�����棬�ҳ���С��һ��Ԫ�أ�
		//�͵�i��Ԫ�ؽ���
		int min = i; //�����i��������С��
		for (int j = i + 1; j < N; ++j)
		{
			//�ӵ�i+1����ʼ�Ƚ�
			if (arr[min] > arr[j])
			{
				min = j;
			}
		}

		//��ʱminΪδ������������С��Ԫ�ص��±�����
		//�͵�i��Ԫ�ؽ���
		int  tmp = arr[i];
		arr[i] = arr[min];
		arr[min] = tmp; 

		Print(arr, 5);
	}
	 
}

void main()
{
	int arr[5] = { 5,3,4,2,1 };

	//ѡ������-�Ӵ�С
	SelectionSort(arr, 5);
}