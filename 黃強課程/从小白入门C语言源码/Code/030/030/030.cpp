#include<stdio.h> //ϵͳͷ�ļ���������printf,scanf��ϵͳ����������

 

void  main()//ϵͳ�������������������ں�������������ļ�д
{


	//���ļ�fopen
	FILE  * fp = fopen("test.txt",  "w+" );
	if (fp != NULL)
	{ 
		printf("fopen�ɹ���\n");

		//�ɹ�ִ���򷵻�ʵ��д������ݿ���Ŀ��ʧ�ܷ���ֵС��countָ����ֵ
		int  count= fwrite( "hello\n", 8, 1, fp);//�˿̵��ļ�ָ���ƶ���ĩβ
		printf("fwrite  %d��\n", count);


		//���ļ�ָ���Ƶ��ļ���ͷ
		fseek(fp, 0, SEEK_SET);

		//�ɹ�����ʵ�ʶ�ȡ�����������С�ڻ����count�������ɹ�������ļ�ĩβ���� 0��
		char str[100] = {  '\0'  };
		count = fread(str, 100, 1, fp);
		printf("fread  %d      %s\n", count ,  str);

		//�ر��ļ�
		fclose(fp);

	}
	else
	{
		printf("fopenʧ�ܣ�\n");
	}

	 
}

