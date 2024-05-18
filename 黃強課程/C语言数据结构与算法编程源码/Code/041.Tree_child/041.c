#include<stdio.h>
#include<stdlib.h>

//���Ĵ洢- ���ӱ�ʾ��


//��������
typedef  char ElemType;

#define TREESIZE  7

//���庢������ڵ�
typedef struct  ChildNode
{
	int   index;//�����������е� �±�����
	struct  ChildNode *next;//��һ�����ӽڵ�
}ChildNode;



//�������ڵ�
typedef struct  Node
{
	ElemType  data;//�ڵ�����
	ChildNode* firstChild;//�ýڵ㺢�������ͷָ��
}Node;


//�������ṹ
typedef struct  Tree
{
	//�ṹ������
	Node elem[TREESIZE]; 
	int    count;//������ж��ٸ����ڵ�

}Tree;


//��ʼ����
void  Init(Tree* tree)
{
	tree->count = 0;
	printf("��ʼ�����ɹ�!\n");
}
  

//���Ԫ�ص�����
void  AddNode(Tree* tree, ElemType  e)
{
	//�жϴ�С
	if (tree->count < TREESIZE)
	{
		Node node;
		node.data = e;//�ڵ������
		node.firstChild = NULL;//������ΪĬ��ֵ

		//�ŵ�������
		tree->elem[tree->count++] = node;
	}
	else
	{
		printf("���ʧ��,������!\n");
	}
}

//����Ԫ��ֵ�����Ҹ����ڵ��������е� �±�����
int  FindNodeindex(Tree* tree, ElemType e)
{
	for (size_t i = 0; i < tree->count; i++)
	{
		if (tree->elem[i].data == e)
		{
			return i;
		}
	}

	//δ���������ҵ���Ԫ��
	return -1;
}


//Ϊp�ڵ� ��� c�ڵ� ������������ȥ
void  AddChildNode(Tree* tree, ElemType p, ElemType c)
{
	//�ҵ�ĳ��ֵ�������е��±�����
	int parent = FindNodeindex(tree ,p);
	int child = FindNodeindex(tree , c);

	if (parent != -1 && child != -1)
	{
		//����һ�����ӽڵ�
		ChildNode* c = (ChildNode*)malloc(sizeof(ChildNode));
		c->index = child;
		c->next = NULL;//�ŵ��������һ��λ��

		ChildNode* p = tree->elem[parent].firstChild;
		if (p == NULL)
		{
			//˵���ǵ�һ���ڵ� 
			tree->elem[parent].firstChild = c;
		}
		else
		{
			//�������������ҵ����һ���ڵ�
			while (p->next != NULL)
			{
				p = p->next;
			 }

			//����ѭ���󣬴�ʱpΪ���һ���ڵ�

			//��c��Ϊ���һ���ڵ�
			p->next = c;

		}

	}
	else
	{
		printf("δ�ҵ����׻������ڵ㣡\n");
	}

}


//����ĳ���ڵ��� ���еĺ���
void  FindNodeChilds(Tree* tree, ElemType e)
{
	for (size_t i = 0; i < tree->count; i++)
	{
		if (tree->elem[i].data == e)
		{
			printf("%c�ĺ�����: ", e);

			//������Ԫ�صĺ�������
			ChildNode* p = tree->elem[i].firstChild;
			while (p)
			{
				int index = p->index;//���ӵ�����
				ElemType child = tree->elem[index].data;
				printf(" %c ", child);
				//��ȡ��һ������
				p = p->next;
			}

			printf("\n" );

			return;
		}
	}

	printf("δ���ҵ��ýڵ㣡\n");
}



void main()
{ 
	//������
	Tree  tree;

	//��ʼ����
	Init(&tree);

	//��ӽڵ�
	AddNode(&tree, 'A');
	AddNode(&tree, 'B');
	AddNode(&tree, 'C');
	AddNode(&tree, 'D');
	AddNode(&tree, 'E');
	AddNode(&tree, 'F');
	AddNode(&tree, 'G');

	AddNode(&tree, 'H');//�������ʧ��

	//Ϊĳ���ڵ�� ���� ��Ӻ��ӽڵ�
	AddChildNode(&tree, 'A', 'B');
	AddChildNode(&tree, 'A', 'C');

	AddChildNode(&tree, 'B', 'D');
	AddChildNode(&tree, 'B', 'E');
	AddChildNode(&tree, 'B', 'F');

	AddChildNode(&tree, 'C', 'G');

	//����ĳ���ڵ��ȫ������
	FindNodeChilds(&tree, 'A');

	FindNodeChilds(&tree, 'B');

	FindNodeChilds(&tree, 'C');

	FindNodeChilds(&tree, 'D');

	FindNodeChilds(&tree, 'Q');
}
