#include<stdio.h> 
#include<string.h>
#include<assert.h> 

//模拟memcpy函数实现
void  *  MyMemcpy(void *dest, const void *source, size_t count)
{
	assert((NULL != dest) && (NULL != source));
	char *tmp_dest = (char *)dest;
	char *tmp_source = (char *)source;
	while (count--)//不判断是否重叠区域拷贝
		*tmp_dest++ = *tmp_source++;
	return dest;
}

//模拟memmove函数实现
void * MyMemmove(void *dest, const void *src, size_t n)
{
	char temp[256];
	int i;
	char *d =(char*) dest;
	const char *s =(char *) src;
	for (i = 0; i < n; i++)
		temp[i] = s[i];
	for (i = 0; i < n; i++)
		d[i] = temp[i];
	return dest;
}




int  main()
{
	 //strcpy进行字符串拷贝  
	//注意：  1. src字符串必须以'\0'结束，  2. dest内存大小必须>=src
	char  a[5];
	//char  b[5] = "ABC";//字符串结尾会自动的有\0 , 此处 b[4]就是'\0' 
	char  b[5];
	b[0] = 'A';
	b[1] = 'B';
	b[2] = 'C';
	b[3] = '\0';//必须加\0，否则strcpy一直向后寻找\0
	strcpy(a, b);
	printf("%s\n", a);

	//memcpy函数， 直接拷贝内存空间，指定拷贝的大小
	int   a2[5];
	int   b2[5] = { 1,2,3,4,5 };//不需要'\0'结束
	memcpy(a2, b2,   3 *sizeof(int)   );//指定拷贝的大小, 单位  字节数
	printf("%d , %d  ,%d\n" , a2[0] ,  a2[1],  a2[2]);

	MyMemcpy(a2 + 3, b2 + 3,   2 * sizeof(int));
	printf("%d , %d \n", a2[3], a2[4]);

	//演示内存重叠的情况
	char  a3[6] = "123";
	//MyMemcpy(a3 + 1, a3, 4); //得到11111
	memcpy(a3 + 1, a3, 4);//虽然它是正确的，但是不保证，重叠拷贝应该避免使用它
	printf("%s\n", a3);


	//memmove功能与memcpy一样，但是了考虑了重叠拷贝的问题，可以保证正确
	char  a4[6] = "123";
	//MyMemmove(a4 + 1, a4, 4);//可以保证正确
	memmove(a4 + 1, a4, 4);//可以保证正确
	printf("%s\n", a4);


	//memset比较简单， 把内存区域初始化化为某个值
	char a5[6];	memset(a5, 0, 6);	for (int i = 0; i < 6; ++i)	{		printf("%d", a5[i]);	}


	return 0;
}