/*   程式名稱 : ch13_4.c                  */
/*   檔案的輸出                           */
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    FILE *fp;
    char ch;

    if ( argc != 2 )
    {
       printf("指令錯誤 ");
       exit(1);
    }
    fp = fopen(argv[1],"r");
    while ( (ch = getc(fp)) != EOF )
       printf("%c",ch);
    fclose(fp);
    system("pause");
    return 0;
}
