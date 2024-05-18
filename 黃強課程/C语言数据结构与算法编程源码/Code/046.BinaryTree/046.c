#include<stdio.h>
#include<stdlib.h>

//二叉树的存储-链表
 
//数据类型
typedef  char ElemType;

 
//定义二叉树节点
typedef struct  Node
{
	ElemType  data;//节点数据 

	struct  Node* leftChild;//指向左边的孩子
	struct  Node* rightChild;//指向左边的孩子
	 
}Node;


//定义二叉树结构
typedef struct  BinaryTree
{
	Node*  root;//指向根节点 
}BinaryTree;


//初始化二叉树
void  Init(BinaryTree* tree)
{
	tree->root = NULL;
	printf("初始化二叉树成功!\n");
}

//递归创建 节点n  的 左孩子，右孩子
void  _create(Node* n)
{
	{
		printf("\n请输入%c节点的左孩子的值:", n->data);
		int c = getch();
		putch(c);

		//人为约定 x 表示没有这个节点
		if (c == 'x')
		{
			n->leftChild = NULL;
		}
		else
		{
			//创建左孩子节点内存
			Node* leftChild = (Node*)malloc(sizeof(Node));
			leftChild->data = c;

			//非常关键的一步( 为左孩子赋值为创建的节点)
			n->leftChild = leftChild;

			//递归去为左孩子创建他的左孩子、右孩子
			_create(leftChild);
			
		}
	}


	{
		printf("\n请输入%c节点的右孩子的值:", n->data);
		int c = getch();
		putch(c);

		//人为约定 x 表示没有这个节点
		if (c == 'x')
		{
			n->rightChild = NULL;
		}
		else
		{
			//创建右孩子节点内存
			Node* rightChild = (Node*)malloc(sizeof(Node));
			rightChild->data = c;

			//非常关键的一步( 为右孩子赋值为创建的节点)
			n->rightChild = rightChild;

			//递归去为右孩子创建他的左孩子、右孩子
			_create(rightChild);
		}
	}

}
    

//创建二叉树的根节点 
void Create(BinaryTree* tree)
{
	printf("\n请输入根节点的值:" );
	int c = getch();
	putch(c);

	//创建根节点内存
	Node* root = (Node*)malloc(sizeof(Node));
	root->data = c;

	//从根节点开始向下创建二叉树
	_create(root);

	//和树结构关联
	tree->root = root;
}
 

//递归 查找某个节点的 元素值 是否为e
Node* _find(Node* n, ElemType e)
{
	//说明n就是我们要寻找的这个节点
	if (n->data == e)
	{
		return  n;
	}

	Node* ret = NULL;
	//如果n节点不是，那么我们来比较他的左孩子是不是e
	if (n->leftChild != NULL)
	{
		//递归查找
		ret= _find(n->leftChild,e);
	}

	//已经找到啦
	if (ret != NULL)
	{
		return ret;
	}

	//如果左孩子不是，那么我们来比较他的右孩子是不是e
	if (n->rightChild != NULL)
	{
		//递归查找
		return _find(n->rightChild, e);
	}

	return NULL;
}


//从树中查找值为e的节点
Node* Find(BinaryTree* tree, ElemType e)
{
	if (tree->root != NULL)
	{
		//从根节点开始查找
		 return  _find(tree->root, e);
	}

	return NULL;
}

//打印某个节点的孩子
void   PrintChilds(Node* n)
{
	printf("\n%c的两个孩子：", n->data);
	if (n->leftChild != NULL)
	{
		printf(" 左孩子：%c", n->leftChild->data);
	}
	if (n->rightChild != NULL)
	{
		printf(" 右孩子：%c", n->rightChild->data);
	}

	printf("\n");
}


//先序遍历 -   根   、左子树、右子树
void  PreOrder(Node* n)
{ 
	if (n != NULL)
	{
		//先打印根
		printf("%c   ", n->data);
		
		//先序遍历左子树
		PreOrder(n->leftChild);

		//先序遍历右子树
		PreOrder(n->rightChild);
	}
}


//中序遍历 - 左子树、  根   、右子树
void  MidOrder(Node* n)
{
	if (n != NULL)
	{ 
		//中序遍历左子树
		MidOrder(n->leftChild);
		
		//打印根
		printf("%c   ", n->data);
		 
		//中序遍历右子树
		MidOrder(n->rightChild);
	}
}


//后序遍历 - 左子树  、右子树、  根 
void  PostOrder(Node* n)
{
	if (n != NULL)
	{
		//后序遍历左子树
		PostOrder(n->leftChild);

		//后序遍历右子树
		PostOrder(n->rightChild);
		 
		//最后打印根
		printf("%c   ", n->data);
	}
}


void main()
{ 
	//定义树
	BinaryTree  tree;

	//初始化树
	Init(&tree);

	//创建根节点和树
	Create(&tree);

	//查找节点
	Node *fb =Find(&tree, 'B');
	PrintChilds(fb);

	Node* fc = Find(&tree, 'C');
	PrintChilds(fc);

	 Node* ff = Find(&tree, 'F');
	 PrintChilds(ff);

	 //先序遍历
	 printf("\n先序遍历: ");
	 PreOrder(tree.root);

	 //中序遍历
	 printf("\n中序遍历: ");
	 MidOrder(tree.root);


	 //后序遍历
	 printf("\n后序遍历: ");
	 PostOrder(tree.root);
}
