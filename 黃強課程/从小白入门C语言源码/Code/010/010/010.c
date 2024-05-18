#include<stdio.h>

void main()
{ 
	//break语句 
	for (int i = 0; i < 10; ++i)
	{
		//当i==4的时候，终止打印
		if (i == 4)
		{
			break;//终止我们的循环
		}
		printf("%d     ",i);
	}

	printf("\n");

	//continue语句 
	for (int i = 0; i < 10; ++i)
	{
		//当i==4的时候，终止一次打印
		if (i == 4)
		{
			continue;//只结束本次循环，然后继续
		}
		printf("%d     ", i);
	}

	printf("\n");

  /*
	//goto loop语句，太强大，不太建议使用，因为会影响程序的可读性 
	for (int i = 0; i < 10; ++i)
	{
		//当i==4的时候，跳转
		if (i == 4)
		{
			goto  loop;//跳转到loop的位置
		}
		printf("%d     ", i);
	}
loop:;
*/

	//多层循环的场景

	for (int j = 0; j < 10; j++)
	{
		printf("\n%d ---->", j);

		for (int k = 0; k < 10; k++)
		{
			if (k== 2)
			{
				//break;//只能跳出一层循环
				//continue;//肯定不能终止
				goto loop;
			}
			printf("%d     ",k);
		} 
	
	}

	loop:;
}