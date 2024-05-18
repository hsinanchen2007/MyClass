#include<stdio.h>
#include<stdlib.h>

//�������Ĵ洢-����
 
//��������
typedef  char ElemType;

 
//����������ڵ�
typedef struct  Node
{
	ElemType  data;//�ڵ����� 

	struct  Node* leftChild;//ָ����ߵĺ���
	struct  Node* rightChild;//ָ����ߵĺ���
	 
}Node;


//����������ṹ
typedef struct  BinaryTree
{
	Node*  root;//ָ����ڵ� 
}BinaryTree;


//��ʼ��������
void  Init(BinaryTree* tree)
{
	tree->root = NULL;
	printf("��ʼ���������ɹ�!\n");
}

//�ݹ鴴�� �ڵ�n  �� ���ӣ��Һ���
void  _create(Node* n)
{
	{
		printf("\n������%c�ڵ�����ӵ�ֵ:", n->data);
		int c = getch();
		putch(c);

		//��ΪԼ�� x ��ʾû������ڵ�
		if (c == 'x')
		{
			n->leftChild = NULL;
		}
		else
		{
			//�������ӽڵ��ڴ�
			Node* leftChild = (Node*)malloc(sizeof(Node));
			leftChild->data = c;

			//�ǳ��ؼ���һ��( Ϊ���Ӹ�ֵΪ�����Ľڵ�)
			n->leftChild = leftChild;

			//�ݹ�ȥΪ���Ӵ����������ӡ��Һ���
			_create(leftChild);
			
		}
	}


	{
		printf("\n������%c�ڵ���Һ��ӵ�ֵ:", n->data);
		int c = getch();
		putch(c);

		//��ΪԼ�� x ��ʾû������ڵ�
		if (c == 'x')
		{
			n->rightChild = NULL;
		}
		else
		{
			//�����Һ��ӽڵ��ڴ�
			Node* rightChild = (Node*)malloc(sizeof(Node));
			rightChild->data = c;

			//�ǳ��ؼ���һ��( Ϊ�Һ��Ӹ�ֵΪ�����Ľڵ�)
			n->rightChild = rightChild;

			//�ݹ�ȥΪ�Һ��Ӵ����������ӡ��Һ���
			_create(rightChild);
		}
	}

}
    

//�����������ĸ��ڵ� 
void Create(BinaryTree* tree)
{
	printf("\n��������ڵ��ֵ:" );
	int c = getch();
	putch(c);

	//�������ڵ��ڴ�
	Node* root = (Node*)malloc(sizeof(Node));
	root->data = c;

	//�Ӹ��ڵ㿪ʼ���´���������
	_create(root);

	//�����ṹ����
	tree->root = root;
}
 

//�ݹ� ����ĳ���ڵ�� Ԫ��ֵ �Ƿ�Ϊe
Node* _find(Node* n, ElemType e)
{
	//˵��n��������ҪѰ�ҵ�����ڵ�
	if (n->data == e)
	{
		return  n;
	}

	Node* ret = NULL;
	//���n�ڵ㲻�ǣ���ô�������Ƚ����������ǲ���e
	if (n->leftChild != NULL)
	{
		//�ݹ����
		ret= _find(n->leftChild,e);
	}

	//�Ѿ��ҵ���
	if (ret != NULL)
	{
		return ret;
	}

	//������Ӳ��ǣ���ô�������Ƚ������Һ����ǲ���e
	if (n->rightChild != NULL)
	{
		//�ݹ����
		return _find(n->rightChild, e);
	}

	return NULL;
}


//�����в���ֵΪe�Ľڵ�
Node* Find(BinaryTree* tree, ElemType e)
{
	if (tree->root != NULL)
	{
		//�Ӹ��ڵ㿪ʼ����
		 return  _find(tree->root, e);
	}

	return NULL;
}

//��ӡĳ���ڵ�ĺ���
void   PrintChilds(Node* n)
{
	printf("\n%c���������ӣ�", n->data);
	if (n->leftChild != NULL)
	{
		printf(" ���ӣ�%c", n->leftChild->data);
	}
	if (n->rightChild != NULL)
	{
		printf(" �Һ��ӣ�%c", n->rightChild->data);
	}

	printf("\n");
}


//������� -   ��   ����������������
void  PreOrder(Node* n)
{ 
	if (n != NULL)
	{
		//�ȴ�ӡ��
		printf("%c   ", n->data);
		
		//�������������
		PreOrder(n->leftChild);

		//�������������
		PreOrder(n->rightChild);
	}
}


//������� - ��������  ��   ��������
void  MidOrder(Node* n)
{
	if (n != NULL)
	{ 
		//�������������
		MidOrder(n->leftChild);
		
		//��ӡ��
		printf("%c   ", n->data);
		 
		//�������������
		MidOrder(n->rightChild);
	}
}


//������� - ������  ����������  �� 
void  PostOrder(Node* n)
{
	if (n != NULL)
	{
		//�������������
		PostOrder(n->leftChild);

		//�������������
		PostOrder(n->rightChild);
		 
		//����ӡ��
		printf("%c   ", n->data);
	}
}


void main()
{ 
	//������
	BinaryTree  tree;

	//��ʼ����
	Init(&tree);

	//�������ڵ����
	Create(&tree);

	//���ҽڵ�
	Node *fb =Find(&tree, 'B');
	PrintChilds(fb);

	Node* fc = Find(&tree, 'C');
	PrintChilds(fc);

	 Node* ff = Find(&tree, 'F');
	 PrintChilds(ff);

	 //�������
	 printf("\n�������: ");
	 PreOrder(tree.root);

	 //�������
	 printf("\n�������: ");
	 MidOrder(tree.root);


	 //�������
	 printf("\n�������: ");
	 PostOrder(tree.root);
}
