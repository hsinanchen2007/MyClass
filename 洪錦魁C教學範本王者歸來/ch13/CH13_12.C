/*   程式名稱 : ch13_12.c                 */
/*   ferror() 應用                        */
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    FILE *fp;
    int  ch;

    fp = fopen(argv[1],"w");  /* 開啟可寫入檔 */ 
    ch = getc(fp);            /* 嘗試讀取資料 */ 
    if ( ferror(fp) != 0 )
       printf("讀檔失敗\n");
    else
       printf("讀檔OK\n");
    fclose(fp);               /* 關閉檔案 */
    system("pause");
    return 0;
}
