#include<stdio.h>
#include<stdlib.h>

typedef  int ElemType;

//����ڵ�
typedef  struct Node
{
	ElemType  e;//�ڵ�Ԫ��ֵ
	struct Node* next;//ָ����һ���ڵ�
}Node;

//ջ�ṹ - ʹ��������ʵ��
typedef  struct  Stack
{ 
	  Node *  top;//ָ��ջ���ڵ�ڵ�
}Stack;


//��ʼ��ջ
void Init(Stack* stack)
{
	//Լ��top ΪNULLʱ�� Ϊ��ջ
	stack->top = NULL;

	printf("ջ��ʼ���ɹ�!\n");
}


//��ջ��ѹջ����ջ (�ȼ�������� ͷ�巨)
void Push(Stack* stack, ElemType e)
{
	//����һ���½ڵ�
	Node* n = (Node*)malloc(sizeof(Node));
	n->e = e; //Ԫ��ֵ

	//��Ԫ�ص�nextָ��ԭ����ջ��Ԫ��
	n->next = stack->top;
	//��top�ȼ��������pHead

	//�½ڵ��Ϊ ջ��Ԫ��
	stack->top = n;

	//�������������ͷ�巨���������Ƚ����������ȳ�
}


//��ջ(�ȼ��� ����� ͷɾ��)
ElemType  Pop(Stack* stack)
{

	if (stack->top != NULL)
	{
		//�ȱ���ջ���ڵ��ָ��,��������ͷ�
		Node* tmp = stack->top; 
		//����ջ���ڵ��Ԫ�أ�������淵�س�ջԪ��
		ElemType  e = stack->top->e;

		//����һ���ڵ��Ϊ�µ�ջ��
		stack->top = stack->top->next;

		//�ͷ�֮ǰ��ջ���ڵ�
		free(tmp);

		//����ջ��Ԫ��ֵ
		return e; 
	}
	else
	{
		printf("��ջʧ�ܣ�ջ�ǿյģ�\n");
		return -1; //������ΪԼ������ЧԪ��ֵ
	}

}

//���ջ���ȼ��� ����ı���ɾ����
void  Clear(Stack* stack)
{
	Node* p = stack->top;  
	while (p != NULL)
	{
		//��ǰ�������һ���ڵ�ĵ�ַ
		Node* tmp = p->next;

	    //���Է��ĵ��ͷŽڵ�
		free(p);

		 //��p��ֵΪ��һ���ڵ�ĵ�ַ
		p =  tmp ;
	}

	//��ջ��top����ΪNULL
	stack->top = NULL;

	printf("ջ��ճɹ�!\n");
}


//��ӡջ ���ȼ��� ����ı�����
void Print(Stack* stack)
{
	Node* p = stack->top;

	printf("��ջ����ջ�ף� " );
	while (p!=NULL)
	{
		printf("%d  ", p->e);
		p = p->next;
	}

	printf("\n");
}

void main()
{
	//����ջ�ṹ����
	Stack stack;

	//��ʼ��ջ
	Init(&stack);
	 

	for (size_t i = 1; i <= 5; i++)
	{
		//��ջ
		Push(&stack,  i );
		Print(&stack);
	}
	
  
	for (size_t i = 1; i <= 6; i++)
	{
		//��ջ
		ElemType  e= Pop(&stack);
		printf("��ջԪ����: %d\n", e);
		Print(&stack);
	}
 
	 

	//���ջ
	Clear(&stack); 



}
