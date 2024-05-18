#include<stdio.h>
#include<stdlib.h>

typedef  int ElemType;
 
#define  QUEUESIZE  5


//队列结构的定义-数组实现
typedef  struct Queue
{
	//存放元素的数组
	ElemType  elem[QUEUESIZE];
	
	int  front;//队头的下标索引 ，删除
	int  rear;//队尾的下标索引 ， 插入
}Queue;


//初始化队列
void Init(Queue* queue)
{
	//人为约定的
	queue->front = -1;
	queue->rear = -1;

	printf("初始化队列成功!\n");
}

//判断是否为空队列
int  IsEmpty(Queue* queue)
{
	return  (queue->front == -1 && queue->rear == -1);
}

//判断队列是否已满了
int  IsFull(Queue* queue)
{
	return  (queue->rear  - queue->front +1 ==  QUEUESIZE);
}

//返回队列的长度
int  Size(Queue* queue)
{
	//空队列长度为0
	if (IsEmpty(queue)) return 0;

	return  queue->rear - queue->front + 1;
}


//移动数据到最左端
void Move(Queue* queue)
{
	if (queue->front > 0)
	{
		int n = Size(queue);

		//将后面的元素移动到从0开始的地方
		for (int i = 0; i < n; ++i)
		{ 
			queue->elem[i] = queue->elem[queue->front + i];
		}
		//更新下标索引
		queue->front = 0;
		queue->rear =n-1;
	}
}


//队尾-插入、入队
void EnQueue(Queue* queue, ElemType  e)
{
	if (IsFull(queue))
	{
		printf("入队失败、队列已满!\n");
	}
	else
	{
		
		if ( IsEmpty( queue) )
		{//如果队列中只有一个元素，即是队头，也是队尾 
			queue->front = 0;
			queue->rear = 0;
		}
		else
		{
			//队列没满，rear是最大的下标索引，说明前面有空闲的空间
			if (queue->rear == QUEUESIZE - 1)
			{
				//需要往前移动数据
				Move(queue);
			}
			 
			//队尾索引向后移动一位
			++queue->rear;
		}

		//放入队尾
		queue->elem[queue->rear] = e; 
	}
}

//队头 删除、出队
ElemType   DeQueue(Queue* queue)
{
	if (IsEmpty(queue))
	{
		printf("出队失败、队列是空的!\n");
		return -1;//约定-1为无效值
	}
	else
	{
		//说明队列中只有一个元素
		if (queue->front == queue->rear)
		{
			//先保存要出队的元素
			ElemType e = queue->elem[queue->front];
			//让队列变成空队列
			queue->front = queue->rear = -1;

			//返回出队的元素
			return e;
		}

		//让front后移一位
		return  queue->elem[queue->front ++];
	}
}


//清空队列
void Clear(Queue* queue)
{
	//人为约定的
	queue->front = -1;
	queue->rear = -1;

	printf("清空队列成功!\n");
}

//打印队列
void Print(Queue* queue)
{
	if (!IsEmpty(queue))
	{
		printf("从队头到队尾: ");
		for (size_t i = queue->front; i <= queue->rear; i++)
		{
			printf("%d   ", queue->elem[i]);
		}
	} 
	printf("\n");
}
  
void main()
{
	  //定义队列
	Queue  queue;
	//初始化
	Init(&queue);

	//判断为空
	printf("是否为空:%d\n", IsEmpty(&queue));

	 
	//测试入队
	for (size_t i = 1; i <= 5; i++)
	{
		EnQueue(&queue, i);
		Print(&queue);
	}

	//测试队列满了再入队
	EnQueue(&queue, 6);
	Print(&queue);

	//判断队列是否满了
	printf("是否满了:%d\n", IsFull(&queue));


	//测试出队
	for (size_t i = 0; i <3; i++)
	{
		ElemType e = DeQueue(&queue );
		printf("出队的元素是:%d\n", e);
		Print(&queue);
	}

	//再入队
	EnQueue(&queue, 6);
	Print(&queue);

	//再入队
	EnQueue(&queue, 7);
	Print(&queue);

	//再入队
	EnQueue(&queue, 8);
	Print(&queue);

	//再入队
	EnQueue(&queue, 9);
	Print(&queue);


	//清空队列
	Clear(&queue);
	Print(&queue);
}
