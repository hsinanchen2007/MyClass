#include<stdio.h>

void  main()
{
	int  a[2][3] = { {1,2,3},{4,5,6} };

	//����ָ���ֵ��ȫһ��
	printf("%p     %p     %p    %p \n"   ,    a,   a[0],  &a[0],  &a[0][0]);

	int(*p1)[3] = a; //ָ��һ����ά�����ָ��
	int *p2  = a[0];//����ġ�a[0]������һ��int * ����ָͨ��
	int(*p3)[3] = &a[0];
	int *p4 = &a[0][0];// ����ġ�Ҳֻ��һ����ָͨ��

	//��ָͨ�����ά����ָ�������
	printf("%p     %p     \n",  p2, p2+1);//��ͨ��ƫ����4���ֽ�
	printf("%p     %p     \n",  p1, p1+1);//��ά��ƫ����12���ֽ�,  3X4= 12

	//1��ָ�뵱�ɶ�ά������
	 for (int i = 0; i < 2; i++)
	 for (int j = 0; j < 3; j++)
	 {
		 printf("%d      ", p1[i][j]);
     }
	 printf("\n" );

	 //2 
	 for (int i = 0; i < 2; i++)
	 for (int j = 0; j < 3; j++)
	  {
			 printf("%d      ",  *(  p1[i]+j)); // p1[i]��һά������׵�ַ
	 }
	 printf("\n");


	 //3
	 for (int i = 0; i < 2; i++)
	 for (int j = 0; j < 3; j++)
		 {
			 printf("%d      ",   *( *(p1+i) + j)); // p1����ָ�룬 *(p1+i) �ȼ��� p1[i]
		 }
	 printf("\n");



	 //4
	 for (int i = 0; i < 2; i++)
		 for (int j = 0; j < 3; j++)
		 {
			 printf("%d      ", *(  *(&p1[i])   + j)); // p1����ָ�룬*(&p1[i])  �ȼ��� p1[i]
		 }
	 printf("\n");
}