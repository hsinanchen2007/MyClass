#include<stdio.h>
 
int  sum(int a, int b)
{
	return a + b;
}

typedef  int(*PFUN) (int);

//�˺������غ���ָ�룬����Ϊ����
PFUN   fun(int  a)
{
	return NULL;
}



void  main()
{
	//����������һ����ֵַ
	printf("%p\n", sum);

	//����sum����ָ�����pSum
	int(*pSum)(int ,int );
	pSum = sum;//������ָ���������ֵַ

	 //����sum����ָ�����pSum2
	int(*pSum2)(int, int);

	//���庯��ָ������
	typedef   int(*PSUM) (int, int);//ֻ��Ҫ����typedef

	//ͨ������ָ�����ͣ�����ָ�����
	PSUM   pSum3 = sum;

	//ͨ��ָ��������ú���
	int  c = pSum3(111,999);
	printf("%d\n", c);

	//p��һ������ָ�룬 ָ��ĺ������������ͣ� 
	//����ֵ����һ������ָ�루����������ֵ�������ͣ�
	int(*(*p)(int)) (int);
	p = fun;

	//����
	p(111);

}