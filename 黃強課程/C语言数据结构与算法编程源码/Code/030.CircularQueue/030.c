#include<stdio.h>
#include<stdlib.h>

typedef  int ElemType;
 
#define  QUEUESIZE  5


//ѭ�����нṹ�Ķ���-����ʵ��
typedef  struct CircularQueue
{
	//���Ԫ�ص�����
	ElemType  elem[QUEUESIZE];
	
	int  front;//��ͷ���±����� ��ɾ��
	int  rear;//��β���±����� �� ����
}CircularQueue;


//��ʼ������
void Init(CircularQueue* queue)
{
	//����ط���һ����0������ĺϷ�����������
	//��Ϊ����������ǻ�״�ģ���״����һ��λ�ö����������
	queue->front = 0;
	queue->rear = 0;

	printf("��ʼ��ѭ�����гɹ�!\n");
}

//�ж��Ƿ�Ϊ�ն���
int  IsEmpty(CircularQueue* queue)
{
	return  (queue->front ==  queue->rear  );
}

//�ж϶����Ƿ�������
int  IsFull(CircularQueue* queue)
{
	//��Ҫ����һ��Ԫ�ؿռ䣬���ж��Ƿ�����
	return  (queue->rear +1)% QUEUESIZE == queue->front  ;
}

//���ض��еĳ���
int  Size(CircularQueue* queue)
{
    //ѭ�����м��㳤�ȵķ���
	return   (queue->rear - queue->front + QUEUESIZE )% QUEUESIZE;
}

  

//��β-���롢���
void EnQueue(CircularQueue* queue, ElemType  e)
{
	if (IsFull(queue))
	{
		printf("���ʧ�ܡ���������!\n");
	}
	else
	{
		//�ڶ�β����Ԫ��
		queue->elem[queue->rear] = e;
	 
		//��ѭ����ָ����һ��λ��
		queue->rear = (queue->rear + 1) % QUEUESIZE;
	}
}

//��ͷ ɾ��������
ElemType   DeQueue(CircularQueue* queue)
{
	if (IsEmpty(queue))
	{
		printf("����ʧ�ܡ������ǿյ�!\n");
		return -1;//Լ��-1Ϊ��Чֵ
	}
	else
	{ 
        //�ȱ����ͷԪ��ֵ
		ElemType  e = queue->elem[queue->front];
		//front�±���ƣ���ס�����Ǽ򵥵�+1
		queue->front = (queue->front + 1) % QUEUESIZE;

		return e;
	}
}


//��ն���
void Clear(CircularQueue* queue)
{
	//ѭ�����в�һ���Ǵ�0��ʼ��
	//ֻҪ front��rear��ȼ�����Ϊ�ǿն���
	queue->front = 0;
	queue->rear = 0;

	printf("��ն��гɹ�!\n");
}

//��ӡ����
void Print(CircularQueue* queue)
{
	if (!IsEmpty(queue))
	{
		printf("�Ӷ�ͷ����β: ");
		 
		for (size_t i =  0; i < Size(queue); i++)
		{
			//ע��������front���ܴ���rear
			int index = (queue->front + i) % QUEUESIZE;
			printf("%d   ", queue->elem[index]);
		}
	} 
	printf("\n");
}
  
void main()
{
	  //�������
	CircularQueue  queue;
	//��ʼ��
	Init(&queue);

	//�ж�Ϊ��
	printf("�Ƿ�Ϊ��:%d\n", IsEmpty(&queue));

	//ѭ���������
	for (int i = 1; i <=5 ; ++i)
	{
		EnQueue(&queue, i);
		Print(&queue);
	}


	//ѭ�����г���
	for (int i = 1; i <= 5; ++i)
	{
		ElemType e=DeQueue(&queue );
		printf("���ӵ�Ԫ����%d \n", e);
		Print(&queue);
	}

	//��ն���
	Clear(&queue);
	Print(&queue);


}
