#include<stdio.h>
#include<stdlib.h>

typedef  int ElemType;

//链表节点
typedef  struct Node
{
	ElemType  e;//节点元素值
	struct Node* next;//指向下一个节点
}Node;

//栈结构 - 使用链表来实现
typedef  struct  Stack
{ 
	  Node *  top;//指向栈顶节点节点
}Stack;


//初始化栈
void Init(Stack* stack)
{
	//约定top 为NULL时， 为空栈
	stack->top = NULL;

	printf("栈初始化成功!\n");
}


//入栈、压栈、进栈 (等价于链表的 头插法)
void Push(Stack* stack, ElemType e)
{
	//产生一个新节点
	Node* n = (Node*)malloc(sizeof(Node));
	n->e = e; //元素值

	//新元素的next指向原来的栈顶元素
	n->next = stack->top;
	//把top等价于链表的pHead

	//新节点成为 栈顶元素
	stack->top = n;

	//就是链表操作的头插法，这样会先进后出、后进先出
}


//出栈(等价于 链表的 头删法)
ElemType  Pop(Stack* stack)
{

	if (stack->top != NULL)
	{
		//先保存栈顶节点的指针,方便后面释放
		Node* tmp = stack->top; 
		//保存栈顶节点的元素，方便后面返回出栈元素
		ElemType  e = stack->top->e;

		//让下一个节点成为新的栈顶
		stack->top = stack->top->next;

		//释放之前的栈顶节点
		free(tmp);

		//返回栈顶元素值
		return e; 
	}
	else
	{
		printf("出栈失败，栈是空的！\n");
		return -1; //返回人为约定的无效元素值
	}

}

//清空栈（等价于 链表的遍历删除）
void  Clear(Stack* stack)
{
	Node* p = stack->top;  
	while (p != NULL)
	{
		//提前保存好下一个节点的地址
		Node* tmp = p->next;

	    //可以放心的释放节点
		free(p);

		 //将p赋值为下一个节点的地址
		p =  tmp ;
	}

	//空栈将top设置为NULL
	stack->top = NULL;

	printf("栈清空成功!\n");
}


//打印栈 （等价于 链表的遍历）
void Print(Stack* stack)
{
	Node* p = stack->top;

	printf("从栈顶到栈底： " );
	while (p!=NULL)
	{
		printf("%d  ", p->e);
		p = p->next;
	}

	printf("\n");
}

void main()
{
	//定义栈结构变量
	Stack stack;

	//初始化栈
	Init(&stack);
	 

	for (size_t i = 1; i <= 5; i++)
	{
		//入栈
		Push(&stack,  i );
		Print(&stack);
	}
	
  
	for (size_t i = 1; i <= 6; i++)
	{
		//出栈
		ElemType  e= Pop(&stack);
		printf("出栈元素是: %d\n", e);
		Print(&stack);
	}
 
	 

	//清空栈
	Clear(&stack); 



}
