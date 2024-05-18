#include<stdio.h>
#include<stdlib.h>

//���Ĵ洢- ˫�ױ�ʾ��

//��������
typedef  char ElemType;

#define TREESIZE  7

//�������ڵ�
typedef struct  Node
{
	ElemType  data;//�ڵ�����
	int   parent;//���ڵ㣨˫�׽ڵ㣩���ڵ� �����±�����
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
 

//�����ṹ����ӽڵ�
void  Add(Tree* tree, ElemType  e, int parent)
{
	if (tree->count >= TREESIZE)
	{
		printf("���ʧ�ܣ��ռ�����!\n");
	}
	else
	{

		//����±������ǲ�������Ϸ���ĳ���ڵ������
		if (parent < tree->count)
		{
			//����һ���ڵ�
			Node n;
			n.data = e;//����
			n.parent = parent;//���ڵ��������е��±�����

			//�ѽڵ�ŵ�������
			tree->elem[tree->count++] = n;
		}
		else {
			printf("���ʧ�ܣ����ڵ������Ƿ�!\n");
		} 

	}


}


//����ĳ���ڵ�ĸ��ڵ㣨˫�׽ڵ㣩��˭
Node* FindParent(Tree* tree, ElemType  e)
{
	//�������飬�Ա�ÿ���ڵ��Ԫ��ֵ
	for (size_t i = 0; i < tree->count; i++)
	{
		//���ҵ���
		if (tree->elem[i].data == e)
		{
			//��ȡ��Ԫ�صĸ��ڵ����������е��±�����
			int parent = tree->elem[i].parent;

			//����ǺϷ�������
			if (parent >= 0)
			{ 
				//���ظ��ڵ�ĵ�ַ
				return   &(tree->elem[parent]);
			}
		}
	}

	//��ʾû�ҵ�Ԫ�أ����߸�Ԫ��û�и��ڵ�
	return NULL;
}

void main()
{ 
	//������
	Tree  tree;

	//��ʼ����
	Init(&tree);
	 

	//�����м���ڵ�
	Add(&tree, 'A', -1); // A���±�Ϊ0

	Add(&tree, 'B', 5);// ģ��Ƿ����±�����

	Add(&tree, 'B', 0);// B���±�Ϊ1
	Add(&tree, 'C', 0);// C���±�Ϊ2

	Add(&tree, 'D', 1);// D���±�Ϊ3
	Add(&tree, 'E', 1);// E���±�Ϊ4
	Add(&tree, 'F', 1); // F���±�Ϊ5

	Add(&tree, 'G', 2); // G���±�Ϊ6

	Add(&tree, 'H', 2); // ������

	//����
	Node* pc = FindParent(&tree, 'C');
	printf("C�ĸ��ڵ���:%c\n", pc->data);


	Node* pf = FindParent(&tree, 'F');
	printf("F�ĸ��ڵ���:%c\n", pf->data);


	Node* pa= FindParent(&tree, 'A');
	if (pa == NULL)
	{
		printf("A�ڵ㲻���ڻ��߸��ڵ�Ϊ��!\n");
	}
	
	Node* pq = FindParent(&tree, 'Q');
	if (pq == NULL)
	{
		printf("Q�ڵ㲻���ڻ��߸��ڵ�Ϊ��!\n");
	}


}
