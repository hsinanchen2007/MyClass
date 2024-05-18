#include<stdio.h>
#include<stdlib.h>

typedef  int ElemType;
 
#define  QUEUESIZE  5


//���нṹ�Ķ���-����ʵ��
typedef  struct Queue
{
	//���Ԫ�ص�����
	ElemType  elem[QUEUESIZE];
	
	int  front;//��ͷ���±����� ��ɾ��
	int  rear;//��β���±����� �� ����
}Queue;


//��ʼ������
void Init(Queue* queue)
{
	//��ΪԼ����
	queue->front = -1;
	queue->rear = -1;

	printf("��ʼ�����гɹ�!\n");
}

//�ж��Ƿ�Ϊ�ն���
int  IsEmpty(Queue* queue)
{
	return  (queue->front == -1 && queue->rear == -1);
}

//�ж϶����Ƿ�������
int  IsFull(Queue* queue)
{
	return  (queue->rear  - queue->front +1 ==  QUEUESIZE);
}

//���ض��еĳ���
int  Size(Queue* queue)
{
	//�ն��г���Ϊ0
	if (IsEmpty(queue)) return 0;

	return  queue->rear - queue->front + 1;
}


//�ƶ����ݵ������
void Move(Queue* queue)
{
	if (queue->front > 0)
	{
		int n = Size(queue);

		//�������Ԫ���ƶ�����0��ʼ�ĵط�
		for (int i = 0; i < n; ++i)
		{ 
			queue->elem[i] = queue->elem[queue->front + i];
		}
		//�����±�����
		queue->front = 0;
		queue->rear =n-1;
	}
}


//��β-���롢���
void EnQueue(Queue* queue, ElemType  e)
{
	if (IsFull(queue))
	{
		printf("���ʧ�ܡ���������!\n");
	}
	else
	{
		
		if ( IsEmpty( queue) )
		{//���������ֻ��һ��Ԫ�أ����Ƕ�ͷ��Ҳ�Ƕ�β 
			queue->front = 0;
			queue->rear = 0;
		}
		else
		{
			//����û����rear�������±�������˵��ǰ���п��еĿռ�
			if (queue->rear == QUEUESIZE - 1)
			{
				//��Ҫ��ǰ�ƶ�����
				Move(queue);
			}
			 
			//��β��������ƶ�һλ
			++queue->rear;
		}

		//�����β
		queue->elem[queue->rear] = e; 
	}
}

//��ͷ ɾ��������
ElemType   DeQueue(Queue* queue)
{
	if (IsEmpty(queue))
	{
		printf("����ʧ�ܡ������ǿյ�!\n");
		return -1;//Լ��-1Ϊ��Чֵ
	}
	else
	{
		//˵��������ֻ��һ��Ԫ��
		if (queue->front == queue->rear)
		{
			//�ȱ���Ҫ���ӵ�Ԫ��
			ElemType e = queue->elem[queue->front];
			//�ö��б�ɿն���
			queue->front = queue->rear = -1;

			//���س��ӵ�Ԫ��
			return e;
		}

		//��front����һλ
		return  queue->elem[queue->front ++];
	}
}


//��ն���
void Clear(Queue* queue)
{
	//��ΪԼ����
	queue->front = -1;
	queue->rear = -1;

	printf("��ն��гɹ�!\n");
}

//��ӡ����
void Print(Queue* queue)
{
	if (!IsEmpty(queue))
	{
		printf("�Ӷ�ͷ����β: ");
		for (size_t i = queue->front; i <= queue->rear; i++)
		{
			printf("%d   ", queue->elem[i]);
		}
	} 
	printf("\n");
}
  
void main()
{
	  //�������
	Queue  queue;
	//��ʼ��
	Init(&queue);

	//�ж�Ϊ��
	printf("�Ƿ�Ϊ��:%d\n", IsEmpty(&queue));

	 
	//�������
	for (size_t i = 1; i <= 5; i++)
	{
		EnQueue(&queue, i);
		Print(&queue);
	}

	//���Զ������������
	EnQueue(&queue, 6);
	Print(&queue);

	//�ж϶����Ƿ�����
	printf("�Ƿ�����:%d\n", IsFull(&queue));


	//���Գ���
	for (size_t i = 0; i <3; i++)
	{
		ElemType e = DeQueue(&queue );
		printf("���ӵ�Ԫ����:%d\n", e);
		Print(&queue);
	}

	//�����
	EnQueue(&queue, 6);
	Print(&queue);

	//�����
	EnQueue(&queue, 7);
	Print(&queue);

	//�����
	EnQueue(&queue, 8);
	Print(&queue);

	//�����
	EnQueue(&queue, 9);
	Print(&queue);


	//��ն���
	Clear(&queue);
	Print(&queue);
}
