#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 

char  * GetBuf()
{
	return  (char *)malloc(10);
}

void  GetBuf2(char *p)//p已经是一份拷贝，和原参数无任何关系
{
	p= (char *)malloc(10);
}

char  * GetBuf3()
{
	char  *p = "hello";//常量内存区，不可更改
	return p;
}


int main()
{
 
	//1.丢失了分配的内存的首地址，导致无法释放
	GetBuf();//忘记接收返回值了


	//2.丢失分配的内存地址
	char  *p1= (char *)malloc(10);
	char  *p2 = (char *)malloc(10);
	p1 = p2;//这一步，导致第一次分配的堆内存丢失，无法释放

	//3.企图希望传入指针变量获取对内存，殊不知是拷贝
	char  *p3 = NULL;
	GetBuf2(p3); //应该使用指针的指针，或者引用
	//strcpy(p3, "hello"); //错误，这里的p3仍然为NULL

	//4.每循环一次，泄露一次内存
	char  * p4 = NULL;
	for (int i = 0; i < 10; ++i)
	{
		p4= (char *)malloc(10);
	}
	strcpy(p4, "hello"); // 这里的p4只指向最后一次分配的，前面的全部内存泄漏

	//5.非法访问常量区
	char *p5 = GetBuf3();
	strcpy(p5, "hello");  



	return 0;
}