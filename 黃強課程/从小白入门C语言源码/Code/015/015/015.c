#include<stdio.h> //ϵͳͷ�ļ���������printf,scanf��ϵͳ����������
 

//���1��n���ۼӺͣ��õݹ�ķ�ʽʵ��
int   NFun(int  n)
{
	//˼·�����N=3��  3+ NFun��2����    ���N=2��  2+ NFun��1����    ���N=1��   NFun��1��=1 

	//�ս�����
	if (n==1)
	{
		return 1;
	}
	else
	{
		return  n+ NFun(n-1);//���ҵ���
	}

}


void  main()//ϵͳ�������������������ں�������������ļ�д
{
	int  sum = NFun(100);
	printf("%d\n",sum);
}

 