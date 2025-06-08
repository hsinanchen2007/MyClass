/*   程式名稱 : ch13_8.c                  */
/*   以二元檔方式開啟檔案再計算字元數     */
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    FILE *fp;
    int  count = 0;

    if ( argc != 2 )
    {
       printf("指令錯誤 ");
       exit(1);
    }
    fp = fopen(argv[1],"rb");   /* 開啟二元檔案 */
    /* 讀到檔案末端才結束 */
    while ( getc(fp) != EOF )
       count++;                   /* 計算字元數 */
    printf("%s檔案的字元數是 %d\n",argv[1],count);
    fclose(fp);                   /* 關閉檔案   */
    system("pause");
    return 0;
}
