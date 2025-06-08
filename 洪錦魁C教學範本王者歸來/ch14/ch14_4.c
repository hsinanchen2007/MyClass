/*   程式名稱 : ch14_4.c                  */
/*   計算檔案長度                         */
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
int main(int argc, char *argv[])
{
    long  length;
    int   fd;

    if ( argc != 2 )
       printf("輸入錯誤 \n");
    fd = open(argv[1],O_RDONLY);
    length = filelength(fd);
    printf("%s 檔案長度是 %ld\n",argv[1],length);
    system("pause");
    return 0; 
}
