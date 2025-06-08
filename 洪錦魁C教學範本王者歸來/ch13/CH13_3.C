/*   程式名稱 : ch13_3.c                  */
/*   putc() 應用                          */
#include <stdio.h>
#include <conio.h>		/* 函數getche()在此定義 */
#include <stdlib.h>
int main()
{
   FILE *fp;
   char ch;	
   
   fp = fopen("sam3.txt","w");   
   printf("請輸入文字按ENTER鍵結束輸入 \n");
   while((ch=getche())!= '\r')  
       putc(ch,fp);
   fclose(fp);			/* 關閉檔案 */
   system("pause");
   return 0;
}

