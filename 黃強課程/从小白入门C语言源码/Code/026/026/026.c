#include<stdio.h> //ϵͳͷ�ļ���������printf,scanf��ϵͳ����������
 

//��������Ľṹ�壨�𳵳��ᣩ
struct  Node
{
	int   data;//�����򣨳�����Ļ��
	struct  Node  *  next;// ָ���� (�����복��Ĺҹ�)
};

 
void  main()//ϵͳ�������������������ں�������������ļ�д
{ 
	//�ȶ������ڻ𳵳��Ტ��ʼ��
	struct  Node  n1 = { 60 ,  NULL  };
	struct  Node  n2 = { 70 ,  NULL };
	struct  Node  n3 = { 80 ,  NULL };

	//��ÿ�ڳ�����������
	n1.next = &n2; //�ѵ�һ����ڶ�������
	n2.next = &n3; //�ѵڶ��������������

	//��ͷָ��ָ���һ�ڳ���
	struct  Node *pHead = &n1;

	//��ӡ�������� 
	while (pHead!=NULL)
	{
		printf("����:%d  ",  pHead->data);
		pHead = pHead->next;
	}


}

