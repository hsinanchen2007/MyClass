#include <stdio.h>
#include <stdlib.h>

//定义类型的别名，方便切换数据类型
typedef    int   ElemType ;


//定义链表节点
typedef  struct Node
{
	ElemType elem; //节点值
	struct Node* next;//指向下一个节点 ，最后一个节点的next为NULL
	
}Node;


//定义一个链表
typedef  struct  List
{ 
	struct Node* pHead;//指向第一个节点
}List;

//初始化
void  Init(List* list)
{
	//空链表
	list->pHead = NULL;

	printf("初始化空链表成功！\n");
}

//头插法- 将节点插入到链表的头部
void  HeadInsert(List* list, ElemType e)
{
	/*
	//为节点分配内存
	Node* n = (Node*)malloc(sizeof(Node));
	n->elem = e;

	if (list->pHead == NULL)
	{//空链表，说明插入后只有一个节点
	    n->next = NULL;
		list->pHead = n; 
	}
	else
	{
		//节点的下一个为链表之前的第一个节点
		n->next = list->pHead;
		//这个节点成为新的头部节点
		list->pHead = n;
	}
	*/


	//为节点分配内存
	Node* n = (Node*)malloc(sizeof(Node));
	n->elem = e;
	
    //节点的下一个为链表之前的第一个节点
	n->next = list->pHead;  

	//这个节点成为新的头部节点
	list->pHead = n;
}



//尾插法- 将节点插入到链表的尾部
void  TailInsert(List* list, ElemType e)
{

	//为节点分配内存
	Node* n = (Node*)malloc(sizeof(Node));
	n->elem = e;
	//因为这个新节点是要放到最末尾，所以next一定是NULL
	n->next = NULL;

	//先找到链表的最末尾的一个元素
	Node* p = list->pHead;
	if (p == NULL)
	{//空链表
		list->pHead = n;
	}
	else
	{ 
		while (p->next != NULL)
		{
			//移动到下一个
			p=p->next;
		}
		//跳出循环后，此时p为最后一个节点
		
		//让最后一个元素的next指向新的 节点
		p->next = n;

	}

}


//任意位置插插入- 将节点插入到链表的第n（n>=1）个节点后
void   Insert(List* list, int n, ElemType e)
{
	 //找到第n个节点
	struct Node* p = list->pHead;

	// 当n=1时，代表第一个节点后插入，就是p
	// 当n=2时，代表第2个节点后插入，只需要一次 p= p->next;
	//当n =3时，代表第3个节点后插入，只需要两次 p= p->next;
	int i = 1;
	while (i++ < n && p != NULL)
	{
		p = p->next;
	}


	//就比如你这条链表就1个节点， 但是我n传的2 ，循环一次之后，p就为NULL
	//这个时候，说明我们的位置n指定错误了，根本就没有第2个节点
	if (p != NULL)
	{
		//说明真正找到这个节点了

		//为节点分配内存
		Node* no = (Node*)malloc(sizeof(Node));
		no->elem = e;
		//新节点的下一个，需要指向第n个节点的下一个
		no->next =  p->next;

		//第n个节点的下一个指向新插入的元素
		p->next = no;

	}
	else
	{
		printf("插入位置错误!\n");
	}

}



//查找第n（n>=1）个节点，返回节点指针
struct Node* FindN(List* list, int n)
{
	//找到第n个节点
	struct Node* p = list->pHead;

	// 当n=1时，代表查找第一个节点 ，就是p
	int i = 1;
	while (i++ < n && p != NULL)
	{
		p = p->next;
	}

	//如果超过了链表元素个数，返回的自然是NULL
	return  p;
}


//查找元素值为e的节点，返回节点指针
struct Node*  Find(List* list, ElemType e)
{
	//从第一个节点开始查找
	Node* p = list->pHead;
	while (p != NULL)
	{
		//说明查找到这个元素了
		if (p->elem == e)
		{
			return p;
		 }
		p = p->next; //让节点变成下一个
	}

	//前面没有查找到
	return NULL;
}


//头删法 -每次都删除第一个节点
void HeadDel(List* list)
{
	//保存了第一个节点的指针
	struct Node* p = list->pHead;

   //不是空链表
	if (p != NULL)
	{ 
		//改变pHead指向第一个节点的下一个
		list->pHead = list->pHead->next;

		//释放第一个节点
		free(p);
	}
	else
	{
		printf("空链表无法删除！\n");
	}

}



//尾删法 -每次都删除最后一个节点
void TailDel(List* list)
{
	//保存了第一个节点的指针
	struct Node* p = list->pHead;

	//不是空链表
	if (p != NULL)
	{
		//如果链表仅仅有一个节点
		if (p->next == NULL)
		{
			//释放这个节点的内存
			free(p);
			//更改头指针
			list->pHead = NULL;
		 }
		else
		{ //至少有两个节点，我就可以找到倒数第二个节点

			while ( p->next->next != NULL)
			{
				//继续向下找
				p = p->next;
			}

			//此刻p指向了倒数第二个节点
			free(p->next);
			//将p变成最后一个节点
			 p->next = NULL;
		}
	}
	else
	{
		printf("空链表无法删除！\n");
	}

}


//删除第n(n>=1)个节点
void  Del(List* list, int n)
{
	//保存了第一个节点的指针
	struct Node* p = list->pHead;

	//不是空链表
	if (p == NULL)
	{
		printf("空链表无法删除！\n");
	}
	else
	{
		//如果删除的是第一个
		if (n == 1)
		{
			//先保存第二个节点的指针
			struct Node* tmp = p->next;
			//放心的删除第一个节点了
			free(p);
			//更改头指针
			list->pHead = tmp;
		}
		else if (n > 1)
		{
			//先找到第n-1个节点
			int i = 1;

			// 假设有4个节点  1  2   3  4， 此刻p是指向1节点的
			// 如果现在n =2，  我们需要找到第n-1个节点，1< 2-1 此刻需要循环0次
			// 如果现在n =3，  我们需要找到第n-1个节点，1< 3-1 此刻需要循环1次
			while (i++ < n - 1 && p != NULL)
			{
				p = p->next;
			}

			//如果节点没有这么长的长度，所以p 一定是NULL
			if (p == NULL || p->next == NULL)
			{//说明链表不够长
				printf("删除位置n错误!\n");
			}
			else
			{ //此刻p指向了第n-1个节点

				//先保存第n+1节点的指针
				struct Node* tmp = p->next->next;
				//放心的删除第n个节点
				free(p->next);
				//让第n-1个节点的next   指向  第n+1个节点
				p->next = tmp;
			}
		}
	}
}

//清空链表
void Clear(List* list)
{
	Node* p = list->pHead;
	while (p != NULL)
	{
		//先保存下一个节点的地址
		Node* tmp = p->next;

		//放心销毁节点内存
		free(p);

		//此刻p的next字段已经无效了，以下代码错误
		//p = p->next; //让节点变成下一个

		//大家一定要细细的品味
		p = tmp;
	}

	//全部销毁后，为空链表
	list->pHead = NULL;

	printf("链表清空成功!\n");
}

//打印链表
void Print(List* list)
{
	printf("\n");
	Node* p = list->pHead;
	while (p != NULL)
	{
		printf("%d  ", p->elem);
		p = p->next; //让节点变成下一个
	}
	printf("\n");
}

int main()
{
	 //定义链表结构体变量
	List list;

	Init(&list);

	//头部插入数据
	HeadInsert(&list, 1);
	Print(&list);

	//头部插入数据
	HeadInsert(&list, 2);
	Print(&list);

	//头部插入数据
	HeadInsert(&list, 3);
	Print(&list);



	//尾部插入数据
	TailInsert(&list, 4);
	Print(&list);

	//尾部插入数据
	TailInsert(&list, 5);
	Print(&list);

	//尾部插入数据
	TailInsert(&list, 6);
	Print(&list);

	//在链表的第1个节点后插入数据
	Insert(&list, 1, 111);
	Print(&list);

	//在链表的第4个节点后插入数据
	Insert(&list, 4, 222);
	Print(&list);

	//在链表的第8个节点后插入数据
	Insert(&list, 8, 333);
	Print(&list);


	//在链表的第20个节点后,非法位置插入数据
	Insert(&list, 20, 444);
	Print(&list);

	//获取第1个元素的指针
	{
		struct Node* ret = FindN(&list, 1);
		printf("查找的第1个元素值为 %d\n", ret->elem);
	}

	//获取第3个元素的指针
	{
		struct Node* ret = FindN(&list, 3);
		printf("查找的第3个元素值为 %d\n", ret->elem);
	}

	//获取第30个元素的指针
	{
		struct Node* ret = FindN(&list, 30);
		printf("查找的第30个元素是否查找到 %d\n", ret != NULL );
	}


	//查找元素值为111的节点 
	{
		struct Node* ret = Find(&list, 111);
		printf("查找元素值为111的节点，值为  %d\n",  ret->elem);
	}


	//查找元素值为9999的节点 ,找不到的
	{
		struct Node* ret = Find(&list, 9999);
		printf("查找元素值为9999 的节点，是否存在 %d \n", ret!=NULL);
	}


	//删除头部节点
	HeadDel(&list);
	Print(&list);

	 
	//删除头部节点
	HeadDel(&list);
	Print(&list);


	//删除头部节点
	HeadDel(&list);
	Print(&list);


	//删除尾部节点
	TailDel(&list);
	Print(&list);

	//删除尾部节点
	TailDel(&list);
	Print(&list);

	//删除尾部节点
	TailDel(&list);
	Print(&list);

	 //删除第3个节点
	 Del(&list,3);
	 Print(&list);

	 //删除第1个节点
	 Del(&list, 1);
	 Print(&list);

	 //删除第5个节点
	 Del(&list,5);
	 Print(&list);

	 //清空链表
	 Clear(&list);
	 Print(&list);

	return  0;
}
 