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

//插入排序法 -升序
void   InsertSort(int arr[], int  N)
{
	//循环N-1趟,  默认第一个元素有序
	for (int  i = 1; i < N; i++)
	{
		//从第二个元素开始，加到前面的部分，让其有序
		for (int j = i; j > 0; --j)
		{
			if (arr[j] < arr[j - 1])
			{//如果后面的元素与前面的元素比较，不是升序就交换
				int  tmp = arr[j];
				arr[j] =arr[j - 1];
				arr[j - 1] = tmp;
			}
		}

		Print(arr, N);
	}

}

void main()
{
	int arr[5] = { 5,3,4,2,1 };

	//插入排序-从大到小
	InsertSort(arr, 5);
}