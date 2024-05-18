#include<stdio.h>
#include<stdlib.h>


//打印数组
void Print(int arr[], int  N) 
{ 
	printf("\n");

	for (int i = 0; i < N; ++i)
	{
		printf("%d   ", arr[i]);
	} 
}

//选择排序法 -升序
void   SelectionSort(int arr[] ,int  N)
{

	//需要比较N-1趟 
	for (int i = 0; i < N - 1; ++i)
	{
		//要从未排序的元素里面，找出最小的一个元素，
		//和第i个元素交换
		int min = i; //假设第i个就是最小的
		for (int j = i + 1; j < N; ++j)
		{
			//从第i+1个开始比较
			if (arr[min] > arr[j])
			{
				min = j;
			}
		}

		//此时min为未排序数里面最小的元素的下标索引
		//和第i个元素交换
		int  tmp = arr[i];
		arr[i] = arr[min];
		arr[min] = tmp; 

		Print(arr, 5);
	}
	 
}

void main()
{
	int arr[5] = { 5,3,4,2,1 };

	//选择排序-从大到小
	SelectionSort(arr, 5);
}