#include<stdio.h>
#include<stdlib.h>

typedef  int ElemType;
 
#define  QUEUESIZE  5


//循环队列结构的定义-数组实现
typedef  struct CircularQueue
{
	//存放元素的数组
	ElemType  elem[QUEUESIZE];
	
	int  front;//队头的下标索引 ，删除
	int  rear;//队尾的下标索引 ， 插入
}CircularQueue;


//初始化队列
void Init(CircularQueue* queue)
{
	//这个地方不一定是0，任意的合法索引都可以
	//因为它被想象成是环状的，环状任意一个位置都可以是起点
	queue->front = 0;
	queue->rear = 0;

	printf("初始化循环队列成功!\n");
}

//判断是否为空队列
int  IsEmpty(CircularQueue* queue)
{
	return  (queue->front ==  queue->rear  );
}

//判断队列是否已满了
int  IsFull(CircularQueue* queue)
{
	//需要牺牲一个元素空间，来判断是否已满
	return  (queue->rear +1)% QUEUESIZE == queue->front  ;
}

//返回队列的长度
int  Size(CircularQueue* queue)
{
    //循环队列计算长度的方法
	return   (queue->rear - queue->front + QUEUESIZE )% QUEUESIZE;
}

  

//队尾-插入、入队
void EnQueue(CircularQueue* queue, ElemType  e)
{
	if (IsFull(queue))
	{
		printf("入队失败、队列已满!\n");
	}
	else
	{
		//在队尾放入元素
		queue->elem[queue->rear] = e;
	 
		//在循环中指向下一个位置
		queue->rear = (queue->rear + 1) % QUEUESIZE;
	}
}

//队头 删除、出队
ElemType   DeQueue(CircularQueue* queue)
{
	if (IsEmpty(queue))
	{
		printf("出队失败、队列是空的!\n");
		return -1;//约定-1为无效值
	}
	else
	{ 
        //先保存队头元素值
		ElemType  e = queue->elem[queue->front];
		//front下标后移，记住不再是简单的+1
		queue->front = (queue->front + 1) % QUEUESIZE;

		return e;
	}
}


//清空队列
void Clear(CircularQueue* queue)
{
	//循环队列不一定是从0开始的
	//只要 front和rear相等即可认为是空队列
	queue->front = 0;
	queue->rear = 0;

	printf("清空队列成功!\n");
}

//打印队列
void Print(CircularQueue* queue)
{
	if (!IsEmpty(queue))
	{
		printf("从队头到队尾: ");
		 
		for (size_t i =  0; i < Size(queue); i++)
		{
			//注意索引，front可能大于rear
			int index = (queue->front + i) % QUEUESIZE;
			printf("%d   ", queue->elem[index]);
		}
	} 
	printf("\n");
}
  
void main()
{
	  //定义队列
	CircularQueue  queue;
	//初始化
	Init(&queue);

	//判断为空
	printf("是否为空:%d\n", IsEmpty(&queue));

	//循环队列入队
	for (int i = 1; i <=5 ; ++i)
	{
		EnQueue(&queue, i);
		Print(&queue);
	}


	//循环队列出队
	for (int i = 1; i <= 5; ++i)
	{
		ElemType e=DeQueue(&queue );
		printf("出队的元素是%d \n", e);
		Print(&queue);
	}

	//清空队列
	Clear(&queue);
	Print(&queue);


}
