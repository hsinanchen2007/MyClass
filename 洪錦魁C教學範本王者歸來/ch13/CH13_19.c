/*   程式名稱 : ch13_19.c                 */
/*   open 和 close 函數應用               */
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
    int  fd;                  /* 檔案代號 */

    if ( argc != 2 )
    {
       printf("輸入錯誤 ");
       exit(1);
    }
    if ( (fd = open(argv[1],O_RDONLY)) == -1 )
    {
       printf("開檔失敗 \n");
       exit(1);
    }
    else
       printf("開檔 OK \n");

    if ( close(fd) == -1 )
       printf("關檔失敗 \n");
    else
       printf("關檔 OK \n");
    system("pause");
    return 0;   
}
