#include<stdio.h>
#include<stdlib.h>

//定义栈的结构体

#define  STACKSIZE  5

typedef  int  ElemType ;

//栈
typedef  struct  Stack
{
	//数组实现栈
	ElemType  elem[STACKSIZE];
	//栈顶的数组下标索引
	int top; //栈顶索引
}Stack;

void  Init(Stack* stack)
{
	stack->top = -1;//表示目前没有任何元素
	printf("初始化栈成功!\n");
}


//入栈，压栈
void  Push(Stack* stack, ElemType e)
{
	 //判断栈是否还有空间
	if (stack->top >= STACKSIZE - 1)
	{
		//已经是最大索引或者超出最大索引

		printf("入栈失败,栈已经满了！\n");
	 }
	else
	{
		stack->elem[++(stack->top)] = e;
	}

}


//出栈，退栈
ElemType  Pop(Stack* stack )
{
	//判断栈是否为空
	if (stack->top < 0 )
	{
		printf("出栈失败,栈是空的！\n"); 
		return -1;//返回一个人为约定的无效值
	}
	else
	{
		//直接返回值
		return   stack->elem[stack->top--]; 
	}

}


//清空栈
void Clear(Stack* stack)
{
	stack->top = -1;
	printf("栈清空成功!\n");
}

//打印栈
void  Print(Stack* stack )
{

	printf("从栈顶到栈底方向：");
	for ( int i = stack->top ; i >=0 ; --i)
	{
		printf("%d   ", stack->elem[i]);
	}
	printf("\n"); 

}

void main()
{

	//定义栈
	Stack stack;

	//初始化栈
	Init(&stack);

	//入栈
	Push(&stack, 1);
	Print(&stack);

	//入栈
	Push(&stack, 2);
	Print(&stack);

	//入栈
	Push(&stack, 3);
	Print(&stack);

	//入栈
	Push(&stack, 4);
	Print(&stack);


	//入栈
	Push(&stack, 5);
	Print(&stack);

	//满了之后，尝试入栈
	Push(&stack, 6);
	Print(&stack);



	//出栈
	for(int i=0;i<5;++i)
	{
		ElemType e = Pop(&stack);
		printf("出栈元素: %d\n", e);
		Print(&stack);
	}
	 

	//栈空了 ，尝试出栈
	{
		ElemType e = Pop(&stack);
		printf("出栈元素: %d\n", e);
		Print(&stack);
	}


	//清空栈
	Clear(&stack);
}
