/*   程式名稱 : ch13_16.c                 */
/*   rewind() 函數應用                    */
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    FILE *fp;
    int  i,loop;
    char ch;

    fp = fopen(argv[1],"r");
    printf("你想輸出檔案幾次 %s",argv[1]);
    printf("\n ==> ");
    scanf("%d",&loop);  /* 讀取輸出檔案次數 */ 
    for ( i = 0; i < loop; i++ )
    {
       while ( ( ch = getc(fp) ) != EOF )
          printf("%c",ch);
       printf("\n");   
       rewind(fp);  /* 移動讀取檔案置開頭位置 */ 
    }
    fclose(fp);
    system("pause");
    return 0;
}
