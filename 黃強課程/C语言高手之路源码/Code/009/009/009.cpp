#include<stdio.h>
#include<stdarg.h>

//�����Ĳ����Ǵ����������
void   fun1(int  a, char *b, int  c)
{
	printf("%p\n" ,&a); 
	printf("%p\n", &b);
	printf("%p\n", &c); //c�ڸߵ�ַ��ջ�����ڸߵ�ַ��C��ջ��
}

//����...��ʾ�ɱ��������
void   fun2(int  a, char *b, int  c)
{
	//��ȡ��һ���������׵�ַ
	char *p = (char *)&a;

	//�ڶ����������׵�ַ
	char *p2 = p + sizeof(int);

	//�������������׵�ַ
	char *p3 = p2 + sizeof(char *);

	printf(" %d ,  %s , %d \n", *((int *)p),  (*((int*)p2) ),   *((int *)p3) ); 
}


// ���� va_list����( char *  ) 
// va_start��ȡ�����׵�ַ     va_argȡ������ֵ  va_end���ָ��
//�ɱ������������ͺ���
int   var_sum(int  n, ...) //��ΪԼ��nΪ�����ĸ���
{
	int  sum = 0;

	va_list  ap;
	va_start(ap, n);//��ʼ��apΪ�׵�ַ

	for (size_t i = 0; i <  n ; i++)
	{
	    int  val= 	va_arg(ap, int); //����ÿ��������ֵ
		sum += val;
	}

	va_end(ap);//ָ����0�� ������������

	return  sum;
}

//ģ��ʵ��printf����
int    MyPrintf(const char *  fmt, ...)
{
	va_list  ap;
	va_start(ap, fmt);//��ʼ��apΪ�׵�ַ

	const char *p = fmt;
	while (*p)
	{
		if (*p == '%')
		{ 
			++p;
			if (*p == 'd')
			{
			   int  i =	va_arg(ap, int);
			   printf("%d",i);
			}
			else   if(*p == 's')
			{
				char *  s = va_arg(ap, char *);
				printf("%s", s);
			}
			else   if (*p == 'c')
			{
				char   c= va_arg(ap, char );
				printf("%c", c);
			}
		} 
		else
		{ 
			putchar(*p);
		} 

		++p;
	} 

	va_end(ap);

	return 0;
}

int  main()
{

	//��ӡ��������ջ�ڴ��ַ
	fun1(111,"222",333);


	//��ʾ���õ�ַ�����ʲ���
	fun2(111, "222", 333);


	//���Կɱ��������var_sum
	printf("%d \n", var_sum(2  ,33,44));
	printf("%d \n", var_sum(5, 1,2,3,4,5));

	//ϵͳ��printf����
	   printf("int:%d    str:%s    char:%c   \n" ,  666,   "aaa",    'A' );

	//����MyPrintf
	   MyPrintf("int:%d    str:%s    char:%c \n", 666, "aaa", 'A');


	return    0;
}