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

//ð������ -����
void   BubbleSort(int arr[] ,int  N)
{
	//��Ҫ�Ƚ�N-1��
	for (int i = 0; i < N - 1; ++i)
	{
		//ÿһ����Ҫ�Ƚ�N-i-1�� ,
		//��Ϊÿһ�˶�����һ������������
		for (int j = 0; j < N - i - 1; ++j)
		{

			//���ǰһ�����ں�һ��
			if (arr[j] > arr[j + 1])
			{
				//����
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}

		//��ӡÿһ�˱ȽϵĽ��
		Print(arr, N);

	}

}

void main()
{
	int arr[5] = { 5,3,4,2,1 };

	//ð������-�Ӵ�С
	BubbleSort(arr, 5);
}