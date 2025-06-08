/*   程式名稱 : ch13_6.c                  */
/*   檔案連接                             */
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    FILE *fp1,*fp2;
    char ch;

    if ( argc != 3 )
    {
       printf("指令錯誤 ");
       exit(1);
    }
    fp1 = fopen(argv[1],"r");  /* 開啟來源檔    */
    fp2 = fopen(argv[2],"a");  /* 開啟目的檔    */
    /* 讀取來源檔資料直至讀到檔案結束訊息       */
    while ( (ch = getc(fp1)) != EOF )
       putc(ch,fp2);          /* 存資料入目的檔 */
    fclose(fp1);              /* 關閉來源檔     */
    fclose(fp2);              /* 關閉目的檔     */
    system("pause");
    return 0;
}
