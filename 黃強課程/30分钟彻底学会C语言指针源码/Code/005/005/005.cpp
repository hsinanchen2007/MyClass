#include<stdio.h> 
 
void  fun()
{
	printf("fun()\n");
}

int   max(int a, int b)
{
	int  c = a > b ? a : b;
	printf("%d\n" ,c );
	return  c;
}


typedef  int(*PFUN3)(int); 
PFUN3    fun3(int  a)
{
	return   NULL;
}



int  main()
{
	//�������ڴ��׵�ַ ���� ������ , ��&Ҳ����
	printf("fun    %p   ,    %p\n", &fun, fun);


	//����fun������Ӧ��  ����ָ�����ͣ��Ƽ���
	typedef  void  (*PFUN)(); 
	//���ú���ָ�����Ͷ��庯��ָ�����
	PFUN   pfun=NULL; 
	printf("����ָ�����ͣ�  %d\n",sizeof(PFUN));
	pfun = &fun;//����ֵַ


	//����typedef ����ֱ�Ӷ��庯��ָ����������Ƽ�
	void(*pfun2)();
	pfun2 = &fun;//����ֵַ

	//���ú���ָ��������ú���
	pfun();//ָ��������ɺ���������
	pfun2();


	//һ�����ӵ�ĺ���ָ��
	typedef  int (*PMAX)(int ,int );
	PMAX  pmax = max;//���庯��ָ�����
	max(555, 888);


	//һ�������ӵĺ���ָ������
	//typedef   PFUN3 (*PFUN4)(int);
	//PFUN4   f4 = fun3;

	typedef    int   (*  (*PFUN4)(int)   )(int);
	PFUN4  f4 = fun3;


	return 0;
}