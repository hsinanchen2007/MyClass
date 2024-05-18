#include <stdio.h>

int main()
{
	//打印相关数据类型占用的字节数
	printf("字符型	char  %d字节\n", sizeof(char));

	printf("短整型	short  %d字节\n", sizeof(short));
	printf("整型		int  %d字节\n", sizeof(int));
	printf("长整型	long  %d字节\n", sizeof(long));

	printf("单精度浮点型	float  %d字节\n", sizeof(float));
	printf("双精度浮点型	double  %d字节\n", sizeof(double));
}
