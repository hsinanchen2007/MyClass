#include<stdio.h>
#include<stdlib.h>

typedef  int ElemType;
 
//��������ڵ�
typedef struct  Node
{
	ElemType  e;//�ڵ�Ԫ��
	struct  Node* next;//��һ���ڵ�ָ��
}Node;
 
//���нṹ�Ķ���-����ʵ��
typedef  struct Queue
{
	Node* front;//ָ���ͷ�ڵ㣨��ͷɾ��Ԫ�أ�
	Node* rear;//ָ���β�ڵ�  (��β����Ԫ��)
}Queue;


//��ʼ������
void Init(Queue* queue)
{
	queue->front = NULL;
	queue->rear = NULL;

	printf("��ʼ���ն��гɹ�!\n");
}

//�ж��Ƿ�Ϊ�ն���
int  IsEmpty(Queue* queue)
{
	return  (queue->front == NULL) 
		&& (queue->rear == NULL);
		     
}
 

//���ض��еĳ���
int  Size(Queue* queue)
{
     
}

  

//��β-���롢��� �������β�巨��
void EnQueue(Queue* queue, ElemType  e)
{
	//�����²���Ľڵ��ڴ�
	Node* n = (Node*)malloc(sizeof(Node));
	n->e = e;
	n->next = NULL; //��Ϊ���һ���ڵ��next����NULL

    if(IsEmpty(queue))
	{
	  //�ն���
		queue->front = n;
		queue->rear = n;
	}
	else
	{
		//�ŵ������ĩβ��rear����ָ�����һ���ڵ�
		queue->rear->next = n;
		//����rearָ�����һ���ڵ�
		queue->rear = n;
	}
}

//��ͷ ɾ�������� -  (�����ͷɾ��)
ElemType   DeQueue(Queue* queue)
{
	if (IsEmpty(queue))
	{
		printf("����ʧ�ܡ������ǿյ�!\n");
		return -1;//Լ��-1Ϊ��Чֵ
	}
	else
	{ 
         //�ȱ���ͷ�ڵ����һ���ڵ��λ��
		Node* tmp = queue->front->next;
		//����ͷ����Ԫ��ֵ
		ElemType  e = queue->front->e;

		//���Է��ĵ�ɾ�� ͷ���,�����ڴ�
		free(queue->front);

		//��frontָ�����µ�ͷ�ڵ�
		queue->front = tmp;

		//�������֮ǰ������ֻ��һ���ڵ㣬��ôtmp����NULL
		//����֮�����������ǿն���
		if (queue->front == NULL)
		{
			//�ֶ���front ��  rear������ΪNULL
			queue->rear = NULL; 
		}

		//���س��ӵ�Ԫ��
		return e;
	}
}


//��ն��� - ����ı���ɾ��
void Clear(Queue* queue)
{
	Node* p = queue->front;

	while (p != NULL)
	{
		//�ȱ���next��ֵ��Ҳ������һ���ڵ�ĵ�ַ
		Node* tmp = p->next;

		//�ͷŽڵ��ڴ棬nextָ����Ҳ���ͷ���
		free(p);

		//�ýڵ�����һ��
		p =  tmp;
	}

	//����Ϊ�ն���
	queue->front = NULL;
	queue->rear = NULL;

	printf("��ն��гɹ�!\n");
}

//��ӡ����-  ѭ����������
void Print(Queue* queue)
{
	if (!IsEmpty(queue))
	{
		printf("�Ӷ�ͷ����β: ");
		Node* p = queue->front;
		while (p != NULL)
		{
			printf("%d   ", p->e);
			//ָ����һ��
			p = p->next;
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

	//�жϿն���
	printf("�����Ƿ�Ϊ�գ�%d\n", IsEmpty(&queue));

	//��Ӳ���
	for (int i = 1; i <= 10; ++i)
	{
		EnQueue(&queue, i);
		Print(&queue);
	}


	//���Ӳ���
	for (int i = 1; i <= 11; ++i)
	{
		ElemType e= DeQueue(&queue );
		printf("���ӵ��ǣ�%d\n", e);
		Print(&queue);
	}


	//��ն���
	Clear(&queue);
}
