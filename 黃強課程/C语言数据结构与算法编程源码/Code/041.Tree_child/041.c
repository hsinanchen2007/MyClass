#include<stdio.h>
#include<stdlib.h>

//树的存储- 孩子表示法


//数据类型
typedef  char ElemType;

#define TREESIZE  7

//定义孩子链表节点
typedef struct  ChildNode
{
	int   index;//孩子在数组中的 下标索引
	struct  ChildNode *next;//下一个孩子节点
}ChildNode;



//定义树节点
typedef struct  Node
{
	ElemType  data;//节点数据
	ChildNode* firstChild;//该节点孩子链表的头指针
}Node;


//定义树结构
typedef struct  Tree
{
	//结构体数组
	Node elem[TREESIZE]; 
	int    count;//这棵树有多少个树节点

}Tree;


//初始化树
void  Init(Tree* tree)
{
	tree->count = 0;
	printf("初始化树成功!\n");
}
  

//添加元素到树中
void  AddNode(Tree* tree, ElemType  e)
{
	//判断大小
	if (tree->count < TREESIZE)
	{
		Node node;
		node.data = e;//节点的数据
		node.firstChild = NULL;//先设置为默认值

		//放到数组中
		tree->elem[tree->count++] = node;
	}
	else
	{
		printf("添加失败,树已满!\n");
	}
}

//根据元素值，查找该树节点在数组中的 下标索引
int  FindNodeindex(Tree* tree, ElemType e)
{
	for (size_t i = 0; i < tree->count; i++)
	{
		if (tree->elem[i].data == e)
		{
			return i;
		}
	}

	//未在数组中找到此元素
	return -1;
}


//为p节点 添加 c节点 到孩子链表中去
void  AddChildNode(Tree* tree, ElemType p, ElemType c)
{
	//找到某个值在数组中的下标索引
	int parent = FindNodeindex(tree ,p);
	int child = FindNodeindex(tree , c);

	if (parent != -1 && child != -1)
	{
		//产生一个孩子节点
		ChildNode* c = (ChildNode*)malloc(sizeof(ChildNode));
		c->index = child;
		c->next = NULL;//放到链表最后一个位置

		ChildNode* p = tree->elem[parent].firstChild;
		if (p == NULL)
		{
			//说明是第一个节点 
			tree->elem[parent].firstChild = c;
		}
		else
		{
			//变量孩子链表，找到最后一个节点
			while (p->next != NULL)
			{
				p = p->next;
			 }

			//跳出循环后，此时p为最后一个节点

			//让c成为最后一个节点
			p->next = c;

		}

	}
	else
	{
		printf("未找到父亲或孩子树节点！\n");
	}

}


//查找某个节点下 所有的孩子
void  FindNodeChilds(Tree* tree, ElemType e)
{
	for (size_t i = 0; i < tree->count; i++)
	{
		if (tree->elem[i].data == e)
		{
			printf("%c的孩子有: ", e);

			//遍历该元素的孩子链表
			ChildNode* p = tree->elem[i].firstChild;
			while (p)
			{
				int index = p->index;//孩子的索引
				ElemType child = tree->elem[index].data;
				printf(" %c ", child);
				//获取下一个孩子
				p = p->next;
			}

			printf("\n" );

			return;
		}
	}

	printf("未查找到该节点！\n");
}



void main()
{ 
	//定义树
	Tree  tree;

	//初始化树
	Init(&tree);

	//添加节点
	AddNode(&tree, 'A');
	AddNode(&tree, 'B');
	AddNode(&tree, 'C');
	AddNode(&tree, 'D');
	AddNode(&tree, 'E');
	AddNode(&tree, 'F');
	AddNode(&tree, 'G');

	AddNode(&tree, 'H');//测试添加失败

	//为某个节点的 链表 添加孩子节点
	AddChildNode(&tree, 'A', 'B');
	AddChildNode(&tree, 'A', 'C');

	AddChildNode(&tree, 'B', 'D');
	AddChildNode(&tree, 'B', 'E');
	AddChildNode(&tree, 'B', 'F');

	AddChildNode(&tree, 'C', 'G');

	//测试某个节点的全部孩子
	FindNodeChilds(&tree, 'A');

	FindNodeChilds(&tree, 'B');

	FindNodeChilds(&tree, 'C');

	FindNodeChilds(&tree, 'D');

	FindNodeChilds(&tree, 'Q');
}
