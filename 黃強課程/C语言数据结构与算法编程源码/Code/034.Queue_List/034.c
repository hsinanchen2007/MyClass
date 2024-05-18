#include<stdio.h>
#include<stdlib.h>

typedef  int ElemType;
 
//定义链表节点
typedef struct  Node
{
	ElemType  e;//节点元素
	struct  Node* next;//下一个节点指针
}Node;
 
//队列结构的定义-链表实现
typedef  struct Queue
{
	Node* front;//指向队头节点（队头删除元素）
	Node* rear;//指向队尾节点  (队尾插入元素)
}Queue;


//初始化队列
void Init(Queue* queue)
{
	queue->front = NULL;
	queue->rear = NULL;

	printf("初始化空队列成功!\n");
}

//判断是否为空队列
int  IsEmpty(Queue* queue)
{
	return  (queue->front == NULL) 
		&& (queue->rear == NULL);
		     
}
 

//返回队列的长度
int  Size(Queue* queue)
{
     
}

  

//队尾-插入、入队 （链表的尾插法）
void EnQueue(Queue* queue, ElemType  e)
{
	//创建新插入的节点内存
	Node* n = (Node*)malloc(sizeof(Node));
	n->e = e;
	n->next = NULL; //因为最后一个节点的next就是NULL

    if(IsEmpty(queue))
	{
	  //空队列
		queue->front = n;
		queue->rear = n;
	}
	else
	{
		//放到链表的末尾，rear正好指向最后一个节点
		queue->rear->next = n;
		//更新rear指向最后一个节点
		queue->rear = n;
	}
}

//队头 删除、出队 -  (链表的头删法)
ElemType   DeQueue(Queue* queue)
{
	if (IsEmpty(queue))
	{
		printf("出队失败、队列是空的!\n");
		return -1;//约定-1为无效值
	}
	else
	{ 
         //先保存头节点的下一个节点的位置
		Node* tmp = queue->front->next;
		//保存头结点的元素值
		ElemType  e = queue->front->e;

		//可以放心的删除 头结点,销毁内存
		free(queue->front);

		//让front指向最新的头节点
		queue->front = tmp;

		//如果出队之前，队列只有一个节点，那么tmp就是NULL
		//出队之后，整个队列是空队列
		if (queue->front == NULL)
		{
			//手动将front 和  rear都设置为NULL
			queue->rear = NULL; 
		}

		//返回出队的元素
		return e;
	}
}


//清空队列 - 链表的遍历删除
void Clear(Queue* queue)
{
	Node* p = queue->front;

	while (p != NULL)
	{
		//先保存next的值，也就是下一个节点的地址
		Node* tmp = p->next;

		//释放节点内存，next指针域也被释放了
		free(p);

		//让节点变成下一个
		p =  tmp;
	}

	//设置为空队列
	queue->front = NULL;
	queue->rear = NULL;

	printf("清空队列成功!\n");
}

//打印队列-  循环遍历链表
void Print(Queue* queue)
{
	if (!IsEmpty(queue))
	{
		printf("从队头到队尾: ");
		Node* p = queue->front;
		while (p != NULL)
		{
			printf("%d   ", p->e);
			//指向下一个
			p = p->next;
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

	//判断空队列
	printf("队列是否为空：%d\n", IsEmpty(&queue));

	//入队操作
	for (int i = 1; i <= 10; ++i)
	{
		EnQueue(&queue, i);
		Print(&queue);
	}


	//出队操作
	for (int i = 1; i <= 11; ++i)
	{
		ElemType e= DeQueue(&queue );
		printf("出队的是：%d\n", e);
		Print(&queue);
	}


	//清空队列
	Clear(&queue);
}
