/*   程式名稱 : ch13_21.c                 */
/*   設計拷貝檔案指令                     */
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#define  size    512
int main(int argc, char *argv[])
{
    int  fd1,fd2; /* fd1來源檔  fd2目的檔的檔案代號 */
    char buf[size];
    int  sizeread;

    if ( argc != 3 )
    {
       printf("輸入錯誤 ");
       exit(1);
    }
    fd1 = open(argv[1],O_RDONLY); /* 開啟來源檔 */ 
    fd2 = open(argv[2],O_CREAT);  /* 開啟目的檔 */ 
    while ( !eof(fd1) ) 
    {
       sizeread = read(fd1,buf,size);
       write(fd2,buf,sizeread);   /* 拷貝 */
    }
    close(fd1);                   /* 關閉來源檔 */ 
    close(fd2);                   /* 關閉目的檔 */ 
    system("pause");
    return 0;
}
