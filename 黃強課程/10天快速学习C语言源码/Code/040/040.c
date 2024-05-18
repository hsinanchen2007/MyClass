
#include <stdio.h>

int main()
{
   //向文件中写入数据
	FILE*  fp1=fopen("文本文件.txt", "w+"); //默认是文本方式
	if (fp1 == NULL)
	{
		printf("打开文件失败！");
		return;
	}
	//写入内容
	char* str = "1234\n";
	fwrite(str/*写入的内容*/,5/*写多少字节*/,1/*写几次*/,fp1 /*往哪个文件写*/);
	//此刻，文件指针在文件末尾

	fseek(fp1, 0, SEEK_SET);//移动文件指针到文件开头,移动0字节

	//fseek(fp1, -6, SEEK_END);//移动到文件末尾，往前移动6字节

	//fseek(fp1, -6, SEEK_CUR);//从指针当前位置往前移动6字节

	//读取文件内容
	char buf[32] = { 0 };
	fread(buf, 5, 1, fp1);
	printf("读出的文件内容为 %s \n", buf);

   //关闭文件
	fclose(fp1);


	//向文件中以二进制的方式写入数据
	FILE* fp2 = fopen("二进制文件.txt", "wb"); //b表示以二进制的方式
	if (fp2 == NULL)
	{
		printf("打开文件失败！");
		return;
	}
	//写入内容 
	fwrite(str , 5 , 1 , fp2);

	//关闭文件
	fclose(fp2);

}
