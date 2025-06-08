/*   程式名稱 : ch13_10.c                 */
/*   fscanf() 函數應用                    */
#include <stdlib.h>
#include <stdio.h>
int main()
{
    FILE *fp;
    int  i,j,var;

    fp = fopen("sam10.txt","r"); /* 開啟檔案 */
    for ( i = 0; i < 5; i++ )
    {
       for ( j = 0; j < 5; j++ )
       {
          fscanf(fp,"%d",&var);
          printf("%c",var);
       }
       printf("\n");
    }
    fclose(fp);  /* 關閉檔案 */
    system("pause");
    return 0;
}
