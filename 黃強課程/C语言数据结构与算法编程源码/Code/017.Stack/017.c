#include<stdio.h>
#include<stdlib.h>

//����ջ�Ľṹ��

#define  STACKSIZE  5

typedef  int  ElemType ;

//ջ
typedef  struct  Stack
{
	//����ʵ��ջ
	ElemType  elem[STACKSIZE];
	//ջ���������±�����
	int top; //ջ������
}Stack;

void  Init(Stack* stack)
{
	stack->top = -1;//��ʾĿǰû���κ�Ԫ��
	printf("��ʼ��ջ�ɹ�!\n");
}


//��ջ��ѹջ
void  Push(Stack* stack, ElemType e)
{
	 //�ж�ջ�Ƿ��пռ�
	if (stack->top >= STACKSIZE - 1)
	{
		//�Ѿ�������������߳����������

		printf("��ջʧ��,ջ�Ѿ����ˣ�\n");
	 }
	else
	{
		stack->elem[++(stack->top)] = e;
	}

}


//��ջ����ջ
ElemType  Pop(Stack* stack )
{
	//�ж�ջ�Ƿ�Ϊ��
	if (stack->top < 0 )
	{
		printf("��ջʧ��,ջ�ǿյģ�\n"); 
		return -1;//����һ����ΪԼ������Чֵ
	}
	else
	{
		//ֱ�ӷ���ֵ
		return   stack->elem[stack->top--]; 
	}

}


//���ջ
void Clear(Stack* stack)
{
	stack->top = -1;
	printf("ջ��ճɹ�!\n");
}

//��ӡջ
void  Print(Stack* stack )
{

	printf("��ջ����ջ�׷���");
	for ( int i = stack->top ; i >=0 ; --i)
	{
		printf("%d   ", stack->elem[i]);
	}
	printf("\n"); 

}

void main()
{

	//����ջ
	Stack stack;

	//��ʼ��ջ
	Init(&stack);

	//��ջ
	Push(&stack, 1);
	Print(&stack);

	//��ջ
	Push(&stack, 2);
	Print(&stack);

	//��ջ
	Push(&stack, 3);
	Print(&stack);

	//��ջ
	Push(&stack, 4);
	Print(&stack);


	//��ջ
	Push(&stack, 5);
	Print(&stack);

	//����֮�󣬳�����ջ
	Push(&stack, 6);
	Print(&stack);



	//��ջ
	for(int i=0;i<5;++i)
	{
		ElemType e = Pop(&stack);
		printf("��ջԪ��: %d\n", e);
		Print(&stack);
	}
	 

	//ջ���� �����Գ�ջ
	{
		ElemType e = Pop(&stack);
		printf("��ջԪ��: %d\n", e);
		Print(&stack);
	}


	//���ջ
	Clear(&stack);
}
