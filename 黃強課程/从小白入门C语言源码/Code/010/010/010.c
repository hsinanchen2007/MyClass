#include<stdio.h>

void main()
{ 
	//break��� 
	for (int i = 0; i < 10; ++i)
	{
		//��i==4��ʱ����ֹ��ӡ
		if (i == 4)
		{
			break;//��ֹ���ǵ�ѭ��
		}
		printf("%d     ",i);
	}

	printf("\n");

	//continue��� 
	for (int i = 0; i < 10; ++i)
	{
		//��i==4��ʱ����ֹһ�δ�ӡ
		if (i == 4)
		{
			continue;//ֻ��������ѭ����Ȼ�����
		}
		printf("%d     ", i);
	}

	printf("\n");

  /*
	//goto loop��䣬̫ǿ�󣬲�̫����ʹ�ã���Ϊ��Ӱ�����Ŀɶ��� 
	for (int i = 0; i < 10; ++i)
	{
		//��i==4��ʱ����ת
		if (i == 4)
		{
			goto  loop;//��ת��loop��λ��
		}
		printf("%d     ", i);
	}
loop:;
*/

	//���ѭ���ĳ���

	for (int j = 0; j < 10; j++)
	{
		printf("\n%d ---->", j);

		for (int k = 0; k < 10; k++)
		{
			if (k== 2)
			{
				//break;//ֻ������һ��ѭ��
				//continue;//�϶�������ֹ
				goto loop;
			}
			printf("%d     ",k);
		} 
	
	}

	loop:;
}