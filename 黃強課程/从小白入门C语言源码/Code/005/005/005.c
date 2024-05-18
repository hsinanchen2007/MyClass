#include "stdio.h"

void  main()
{

	//前缀不一样，代表的进制不一样，二进制没办法表示
	printf("%d\n", 10000);//默认是十进制

	printf("%d\n", 010);//八进制，用0打头

	printf("%d\n", 0x10);//十六进制，用0x打头



	//用代码展示进制转换
	int a = 215;
	printf("十进制		 %d\n", a);
	printf("八进制		 %o\n", a); 
	printf("十六进制	 %x          %X          %p\n", a, a, a);


	char s[10];
	itoa(a, s, 2);//函数，转为二进制
	printf("二进制		 %s\n", s);

}