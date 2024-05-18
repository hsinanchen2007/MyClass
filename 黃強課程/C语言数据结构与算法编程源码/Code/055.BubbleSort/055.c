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

//冒泡排序法 -升序
void   BubbleSort(int arr[] ,int  N)
{
	//需要比较N-1趟
	for (int i = 0; i < N - 1; ++i)
	{
		//每一趟需要比较N-i-1次 ,
		//因为每一趟都会让一个最大的数后移
		for (int j = 0; j < N - i - 1; ++j)
		{

			//如果前一个大于后一个
			if (arr[j] > arr[j + 1])
			{
				//交换
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}

		//打印每一趟比较的结果
		Print(arr, N);

	}

}

void main()
{
	int arr[5] = { 5,3,4,2,1 };

	//冒泡排序-从大到小
	BubbleSort(arr, 5);
}