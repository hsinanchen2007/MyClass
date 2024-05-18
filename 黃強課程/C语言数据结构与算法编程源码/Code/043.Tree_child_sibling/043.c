#include<stdio.h>
#include<stdlib.h>

//���Ĵ洢- �����ֵܱ�ʾ��
 
//��������
typedef  char ElemType;

 
//�������ڵ�
typedef struct  Node
{
	ElemType  data;//�ڵ����� 

	struct  Node* firstChild;//ָ��˽ڵ�ĵ�һ������
	struct  Node* nextSibling;//ָ��˽ڵ���һ���ֵ�
}Node;


//�������ṹ
typedef struct  Tree
{
	Node*  root;//ָ����ڵ� 
}Tree;


//��ʼ����
void  Init(Tree* tree)
{
	tree->root = NULL;
	printf("��ʼ�����ɹ�!\n");
}
  
 //�ݹ�Ϊĳ���ڵ�  ����  ��һ�����ӡ���һ���ֵܵ� �ڵ�
void  _create(Node  * n)
{
	{  //�ڵ�n�ĵ�һ��ָ����
		printf("\n������ڵ�%c��һ�����ӵ�ֵ��", n->data);
		int c = getch();//��ȡ�û�������ַ�
		putch(c);

		//��ΪԼ�����û�����x�ַ�����ʾ û��
		if (c == 'x')
		{
			n->firstChild = NULL;
		}
		else
		{
			//������һ�����ӵĽڵ�
			Node* child = (Node*)malloc(sizeof(Node));
			child->data = c; //��ֵ ������

			//ָ���ڵ�n�� ��һ�����ӽڵ�
			n->firstChild = child;

			//���ü���Ϊ���ӽڵ�� ����ָ������и�ֵ
			_create(child);//�ݹ���ã�����ͬ��������
		}
	}
	

	{ //�ڵ�n�ĵڶ���ָ����
		printf("\n������ڵ�%c��һ���ֵܵ�ֵ��", n->data);
		int c = getch();//��ȡ�û�������ַ�
		putch(c);

		//��ΪԼ�����û�����x�ַ�����ʾ û��
		if (c == 'x')
		{
			n->nextSibling = NULL;
		}
		else
		{
			//������һ���ֵܵĽڵ�
			Node* sibling = (Node*)malloc(sizeof(Node));
			sibling->data = c; //��ֵ ������

			 //ָ���ڵ�n�� ��һ���ֵܽڵ�
			n->nextSibling = sibling;

			//���ü���Ϊ���ӽڵ�� ����ָ������и�ֵ
			_create(sibling);//�ݹ���ã�����ͬ��������
		}

	} 

 }


//������������ȥ���õݹ�
void Create(Tree* tree)
{
	printf("\n��������ڵ������ֵ��" );
	int c = getch();//��ȡ�û�������ַ�
	putch(c);

	//�������ڵ��ڴ�
	Node* root = (Node*)malloc(sizeof(Node));
	root->data = c; //��ֵ ������

	//Ϊ���ڵ�� ����ָ������и�ֵ
	_create(root); //�ݹ鿪ʼ

	//ָ�����ĸ��ڵ�
	tree->root = root;
}

//��ĳ���ڵ㿪ʼ�� ��ѰֵΪe�Ľڵ�
Node* _find(Node* n, ElemType  e)
{
	//�����ǰ�ڵ����Ҫ���ҵĽڵ�
	if (n->data == e)
	{
		//ֱ�ӷ��ص�ǰ�ڵ�
		return n;
	}

	Node* ret = NULL;
	if (n->firstChild != NULL)
	{
		//�ݹ�Ӹýڵ�ĵ�һ�����Ӳ���
		ret = _find(n->firstChild, e);
	}

	if (ret != NULL)
	{ //˵���Ѿ��ҵ���
		return ret;
	}

	if (n->nextSibling != NULL)
	{
		//�ݹ�Ӹýڵ����һ���ֵܲ���
		return _find(n->nextSibling, e);
	}

	return NULL;
}

//���ҵ����
Node* Find(Tree* tree, ElemType e)
{
	//�Ӹ��ڵ㿪ʼ��
	if (tree->root != NULL)
	{
		return _find(tree->root,e);
	}

	//û�ҵ�
	return NULL;
}

//��ӡĳ���ڵ�����к��ӽڵ�
void PrintChilds(Node* n)
{
	printf("\n��ӡ%c�����к��ӣ�", n->data);
	 
	//��һ���������ǿ϶�֪��
	Node* firstChild = n->firstChild;
	if (firstChild != NULL)
	{
		printf("%c  ", firstChild->data);

		//�����ĺ�����ô��ӡ��
		//��һ�����ӵ����ֵܣ�����n�ڵ����������
		Node* sib = firstChild->nextSibling;
		while (sib != NULL)
		{
			printf("%c  ", sib->data); 
			//��ȡ���ֵܵ� ��һ�����ֵ�
			sib = sib->nextSibling;
		}

	}
	else 
	{
		printf("�޺���!");
	}


	printf("\n");
}
 
void main()
{ 
	//������
	Tree  tree;

	//��ʼ����
	Init(&tree);

	//��ʼ�ݹ鴴��������Ҫ�û�����
	Create(&tree);
 

	//���Խڵ�Ĳ���
	Node *na = Find(&tree, 'A');
	printf("\n���ҵ��ڵ�%c\n", na->data);

	Node* nb = Find(&tree, 'B');
	printf("\n���ҵ��ڵ�%c\n", nb->data);

	Node* nf = Find(&tree, 'F');
	printf("\n���ҵ��ڵ�%c\n", nf->data);

	Node* nc = Find(&tree, 'C');
	printf("\n���ҵ��ڵ�%c\n", nc->data);

	Node* nq = Find(&tree, 'Q');
	printf("\n���ҵ�Q�ڵ��Ƿ�Ϊ�գ�%d \n", nq == NULL);

	//��ӡ�ڵ�����к���
	PrintChilds(na); 
	PrintChilds(nb);
	PrintChilds(nf);
	PrintChilds(nc);

}
