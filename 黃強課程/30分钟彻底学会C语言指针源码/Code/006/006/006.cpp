#include<stdio.h> 
#include<stdlib.h> 


int  main()
{
	//��ָ���������ֵַ
	int  *p = (int *)malloc(sizeof(int));
	*p = 666;//���ڴ�����ֵ
	printf("%p  ,  %d\n", p,   *p);
	//Ұָ�����1 
	free(p);//�ѷ�����ڴ����٣��˿�p��ΪҰָ�룬��Ϊ��ָ�������ٵ��ڴ�

	printf("%p  ,  %d\n", p,  *p);//�Ѿ��������


    //Ұָ�����2
	int  *p2 = (int *)0x34458934;//��ָһ����Ұָ��
	//*p2 = 100;//�Ƿ��޸��ڴ������
	//printf("%d\n",  *p2);//������Ȩ�޵��ڴ�

	//���ָ�벻��ʼ������ô����ֵ��CCCCCCCC��Ұָ��
	int  *p3;
	printf("%p \n", p3); 

	//����Ұָ��ķ���
	//1.��ʼ��ΪNULL
	int  *p4 = NULL;

	
	//2.free����ΪNULL
	p4 = (int *)malloc(sizeof(int));
	*p4 = 888;
	free(p4);
	p4 = NULL; 
	if (p4 != NULL)
	{
		//��ʹ��p4
		printf("%p  ,  %d\n", p4, *p4); 
	}



	return 0;
}