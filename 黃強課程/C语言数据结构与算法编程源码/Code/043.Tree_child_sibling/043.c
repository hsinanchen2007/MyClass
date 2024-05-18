#include<stdio.h>
#include<stdlib.h>

//树的存储- 孩子兄弟表示法
 
//数据类型
typedef  char ElemType;

 
//定义树节点
typedef struct  Node
{
	ElemType  data;//节点数据 

	struct  Node* firstChild;//指向此节点的第一个孩子
	struct  Node* nextSibling;//指向此节点下一个兄弟
}Node;


//定义树结构
typedef struct  Tree
{
	Node*  root;//指向根节点 
}Tree;


//初始化树
void  Init(Tree* tree)
{
	tree->root = NULL;
	printf("初始化树成功!\n");
}
  
 //递归为某个节点  创建  第一个孩子、下一个兄弟的 节点
void  _create(Node  * n)
{
	{  //节点n的第一个指针域
		printf("\n请输入节点%c第一个孩子的值：", n->data);
		int c = getch();//获取用户输入的字符
		putch(c);

		//人为约定，用户输入x字符，表示 没有
		if (c == 'x')
		{
			n->firstChild = NULL;
		}
		else
		{
			//创建第一个孩子的节点
			Node* child = (Node*)malloc(sizeof(Node));
			child->data = c; //赋值 数据域

			//指定节点n的 第一个孩子节点
			n->firstChild = child;

			//还得继续为孩子节点的 两个指针域进行赋值
			_create(child);//递归调用，经历同样的流程
		}
	}
	

	{ //节点n的第二个指针域
		printf("\n请输入节点%c下一个兄弟的值：", n->data);
		int c = getch();//获取用户输入的字符
		putch(c);

		//人为约定，用户输入x字符，表示 没有
		if (c == 'x')
		{
			n->nextSibling = NULL;
		}
		else
		{
			//创建下一个兄弟的节点
			Node* sibling = (Node*)malloc(sizeof(Node));
			sibling->data = c; //赋值 数据域

			 //指定节点n的 下一个兄弟节点
			n->nextSibling = sibling;

			//还得继续为孩子节点的 两个指针域进行赋值
			_create(sibling);//递归调用，经历同样的流程
		}

	} 

 }


//创建树，里面去调用递归
void Create(Tree* tree)
{
	printf("\n请输入根节点的数据值：" );
	int c = getch();//获取用户输入的字符
	putch(c);

	//创建根节点内存
	Node* root = (Node*)malloc(sizeof(Node));
	root->data = c; //赋值 数据域

	//为根节点的 两个指针域进行赋值
	_create(root); //递归开始

	//指定树的根节点
	tree->root = root;
}

//从某个节点开始， 搜寻值为e的节点
Node* _find(Node* n, ElemType  e)
{
	//如果当前节点就是要查找的节点
	if (n->data == e)
	{
		//直接返回当前节点
		return n;
	}

	Node* ret = NULL;
	if (n->firstChild != NULL)
	{
		//递归从该节点的第一个孩子查找
		ret = _find(n->firstChild, e);
	}

	if (ret != NULL)
	{ //说明已经找到了
		return ret;
	}

	if (n->nextSibling != NULL)
	{
		//递归从该节点的下一个兄弟查找
		return _find(n->nextSibling, e);
	}

	return NULL;
}

//查找的入口
Node* Find(Tree* tree, ElemType e)
{
	//从根节点开始找
	if (tree->root != NULL)
	{
		return _find(tree->root,e);
	}

	//没找到
	return NULL;
}

//打印某个节点的所有孩子节点
void PrintChilds(Node* n)
{
	printf("\n打印%c的所有孩子：", n->data);
	 
	//第一个孩子我们肯定知道
	Node* firstChild = n->firstChild;
	if (firstChild != NULL)
	{
		printf("%c  ", firstChild->data);

		//其它的孩子怎么打印？
		//第一个孩子的亲兄弟，就是n节点的其它孩子
		Node* sib = firstChild->nextSibling;
		while (sib != NULL)
		{
			printf("%c  ", sib->data); 
			//获取亲兄弟的 下一个亲兄弟
			sib = sib->nextSibling;
		}

	}
	else 
	{
		printf("无孩子!");
	}


	printf("\n");
}
 
void main()
{ 
	//定义树
	Tree  tree;

	//初始化树
	Init(&tree);

	//开始递归创建树，需要用户交互
	Create(&tree);
 

	//测试节点的查找
	Node *na = Find(&tree, 'A');
	printf("\n查找到节点%c\n", na->data);

	Node* nb = Find(&tree, 'B');
	printf("\n查找到节点%c\n", nb->data);

	Node* nf = Find(&tree, 'F');
	printf("\n查找到节点%c\n", nf->data);

	Node* nc = Find(&tree, 'C');
	printf("\n查找到节点%c\n", nc->data);

	Node* nq = Find(&tree, 'Q');
	printf("\n查找到Q节点是否为空：%d \n", nq == NULL);

	//打印节点的所有孩子
	PrintChilds(na); 
	PrintChilds(nb);
	PrintChilds(nf);
	PrintChilds(nc);

}
