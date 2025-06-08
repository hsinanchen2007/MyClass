/*   程式名稱 : ch13_13.c                 */
/*   fwrite() 應用                        */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int main()
{
    FILE *fp;
    struct score
    {
       int math;                  /* 數學成績 */
       char  name[10];            /* 姓名欄位 */ 
    }  var;

    fp = fopen("sam13.txt","wb"); /*開啟檔案供存資料*/ 
    do
    {
       printf("\n請輸入姓名 : ");
       scanf("%s",&var.name);
       printf("請輸入數學成績 : ");
       scanf("%d",&var.math);
       fwrite(&var,sizeof(var),1,fp);
       printf("是否繼續輸入 ? (y/n) ");
    }  while ( getche() == 'y' );
    fclose(fp);                   /* 關閉檔案 */ 
    system("pause");
    return 0;
}
