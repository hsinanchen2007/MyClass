#include<stdio.h> 
#include<string.h>
#include<assert.h> 

//ģ��memcpy����ʵ��
void  *  MyMemcpy(void *dest, const void *source, size_t count)
{
	assert((NULL != dest) && (NULL != source));
	char *tmp_dest = (char *)dest;
	char *tmp_source = (char *)source;
	while (count--)//���ж��Ƿ��ص����򿽱�
		*tmp_dest++ = *tmp_source++;
	return dest;
}

//ģ��memmove����ʵ��
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
	 //strcpy�����ַ�������  
	//ע�⣺  1. src�ַ���������'\0'������  2. dest�ڴ��С����>=src
	char  a[5];
	//char  b[5] = "ABC";//�ַ�����β���Զ�����\0 , �˴� b[4]����'\0' 
	char  b[5];
	b[0] = 'A';
	b[1] = 'B';
	b[2] = 'C';
	b[3] = '\0';//�����\0������strcpyһֱ���Ѱ��\0
	strcpy(a, b);
	printf("%s\n", a);

	//memcpy������ ֱ�ӿ����ڴ�ռ䣬ָ�������Ĵ�С
	int   a2[5];
	int   b2[5] = { 1,2,3,4,5 };//����Ҫ'\0'����
	memcpy(a2, b2,   3 *sizeof(int)   );//ָ�������Ĵ�С, ��λ  �ֽ���
	printf("%d , %d  ,%d\n" , a2[0] ,  a2[1],  a2[2]);

	MyMemcpy(a2 + 3, b2 + 3,   2 * sizeof(int));
	printf("%d , %d \n", a2[3], a2[4]);

	//��ʾ�ڴ��ص������
	char  a3[6] = "123";
	//MyMemcpy(a3 + 1, a3, 4); //�õ�11111
	memcpy(a3 + 1, a3, 4);//��Ȼ������ȷ�ģ����ǲ���֤���ص�����Ӧ�ñ���ʹ����
	printf("%s\n", a3);


	//memmove������memcpyһ���������˿������ص����������⣬���Ա�֤��ȷ
	char  a4[6] = "123";
	//MyMemmove(a4 + 1, a4, 4);//���Ա�֤��ȷ
	memmove(a4 + 1, a4, 4);//���Ա�֤��ȷ
	printf("%s\n", a4);


	//memset�Ƚϼ򵥣� ���ڴ������ʼ����Ϊĳ��ֵ
	char a5[6];	memset(a5, 0, 6);	for (int i = 0; i < 6; ++i)	{		printf("%d", a5[i]);	}


	return 0;
}