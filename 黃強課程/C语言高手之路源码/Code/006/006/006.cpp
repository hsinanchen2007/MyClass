#include<stdio.h>

#pragma  pack(1) //����1�ֽڶ���
//#pragma  pack( ) //ȡ��1�ֽڶ���

int  main()
{ 

	struct A
	{
		char  a;  //0-1
		int     b; //4-7
		char  c[10];//8-17
	}; 
	printf("A  %d\n", sizeof(A));  //20 


	struct B
	{
		int   a;  //0-3
		double     b; //8-15
		float  c; //16-20
	};
	printf("B  %d\n", sizeof(B));  //24



	//�ṹ��Ƕ��
	struct C
	{
		char  a;  // �������������Ա����������ʼ��4-5
		int     b; //8-12
	};
	struct D
	{
		char   a;  //0-1
		C     b; 
		float  c;//12-16
	};
	printf("D  %d\n", sizeof(D));  //16

 

	//������
	struct E
	{
		int        a;//[24]....[27]
		double b;//[32].....[39]������������ԭ��
		float     c;//[40]..[44] ��������ԭ��
	};
	struct F
	{
		char a[2];//[0]...[2]
		int  b; //[4]...[7]�������������� ԭ��
		double c;//[8]....[15]��������
		short d;//[16]...[17]����������������
		E     e;//[24]......[47]���������� ��ԭ��
	};

	printf("F  %d\n", sizeof(F));  //48

 




	return 0;
}