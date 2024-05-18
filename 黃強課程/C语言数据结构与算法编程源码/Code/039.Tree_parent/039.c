#include<stdio.h>
#include<stdlib.h>

//树的存储- 双亲表示法

//数据类型
typedef  char ElemType;

#define TREESIZE  7

//定义树节点
typedef struct  Node
{
	ElemType  data;//节点数据
	int   parent;//父节点（双亲节点）所在的 数组下标索引
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
 

//向树结构中添加节点
void  Add(Tree* tree, ElemType  e, int parent)
{
	if (tree->count >= TREESIZE)
	{
		printf("添加失败，空间已满!\n");
	}
	else
	{

		//检查下标索引是不是数组合法的某个节点的索引
		if (parent < tree->count)
		{
			//定义一个节点
			Node n;
			n.data = e;//数据
			n.parent = parent;//父节点在数组中的下标索引

			//把节点放到数组中
			tree->elem[tree->count++] = n;
		}
		else {
			printf("添加失败，父节点索引非法!\n");
		} 

	}


}


//查找某个节点的父节点（双亲节点）是谁
Node* FindParent(Tree* tree, ElemType  e)
{
	//遍历数组，对比每个节点的元素值
	for (size_t i = 0; i < tree->count; i++)
	{
		//查找到了
		if (tree->elem[i].data == e)
		{
			//获取该元素的父节点所在数组中的下标索引
			int parent = tree->elem[i].parent;

			//如果是合法的索引
			if (parent >= 0)
			{ 
				//返回父节点的地址
				return   &(tree->elem[parent]);
			}
		}
	}

	//表示没找到元素，或者该元素没有父节点
	return NULL;
}

void main()
{ 
	//定义树
	Tree  tree;

	//初始化树
	Init(&tree);
	 

	//向树中加入节点
	Add(&tree, 'A', -1); // A的下标为0

	Add(&tree, 'B', 5);// 模拟非法的下标索引

	Add(&tree, 'B', 0);// B的下标为1
	Add(&tree, 'C', 0);// C的下标为2

	Add(&tree, 'D', 1);// D的下标为3
	Add(&tree, 'E', 1);// E的下标为4
	Add(&tree, 'F', 1); // F的下标为5

	Add(&tree, 'G', 2); // G的下标为6

	Add(&tree, 'H', 2); // 树已满

	//查找
	Node* pc = FindParent(&tree, 'C');
	printf("C的父节点是:%c\n", pc->data);


	Node* pf = FindParent(&tree, 'F');
	printf("F的父节点是:%c\n", pf->data);


	Node* pa= FindParent(&tree, 'A');
	if (pa == NULL)
	{
		printf("A节点不存在或者父节点为空!\n");
	}
	
	Node* pq = FindParent(&tree, 'Q');
	if (pq == NULL)
	{
		printf("Q节点不存在或者父节点为空!\n");
	}


}
