/*   程式名稱 : ch13_20.c                 */
/*   計算檔案的字元數                     */
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#define  size    512
int main(int argc, char *argv[])
{
    int  fd;                  /* 檔案代號 */
    char buf[size];
    int  count = 0;
    int  i;

    if ( argc != 2 )
    {
       printf("輸入錯誤 ");
       exit(1);
    }
    fd = open(argv[1],O_RDONLY);
    while ( ( i = read(fd,buf,size) ) > 0 )
       count += i;
    printf("%s 的字元數是 %d\n",argv[1],count);
    close(fd);
    system("pause");
    return 0;
}
