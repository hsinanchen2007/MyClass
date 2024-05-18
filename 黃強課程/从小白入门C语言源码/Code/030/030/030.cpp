#include<stdio.h> //系统头文件，包含了printf,scanf等系统函数的声明

 

void  main()//系统主函数，整个程序的入口函数，这个是它的简写
{


	//打开文件fopen
	FILE  * fp = fopen("test.txt",  "w+" );
	if (fp != NULL)
	{ 
		printf("fopen成功！\n");

		//成功执行则返回实际写入的数据块数目，失败返回值小于count指定的值
		int  count= fwrite( "hello\n", 8, 1, fp);//此刻的文件指针移动到末尾
		printf("fwrite  %d！\n", count);


		//把文件指针移到文件开头
		fseek(fp, 0, SEEK_SET);

		//成功返回实际读取到的项个数（小于或等于count），不成功或读到文件末尾返回 0。
		char str[100] = {  '\0'  };
		count = fread(str, 100, 1, fp);
		printf("fread  %d      %s\n", count ,  str);

		//关闭文件
		fclose(fp);

	}
	else
	{
		printf("fopen失败！\n");
	}

	 
}

