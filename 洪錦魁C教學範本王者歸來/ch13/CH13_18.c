/*   程式名稱 : ch13_18.c                 */
/*   設計 PRINT 指令                      */
/* 適用 標準 C   Turbo/Visual C           */ 
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    FILE *fp;
    char ch;

    if ( argc != 2 )
    {
       printf("輸入錯誤 \n");
       exit(1);
    }
    fp = fopen(argv[1],"rb");
    while ( (ch = getc(fp)) != EOF )
       putc(ch,stdprn);    /* 由印表機列印 */ 
    fclose(fp);
    system("pause");
    return 0;
}
