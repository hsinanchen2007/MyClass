/*   程式名稱 : ch14_8.c                  */
/*   更改目前目錄路徑                     */
#include <stdio.h>
#include <stdlib.h> 
int main(int argc, char *argv[])
{
    if ( argc != 2 )
    {
       printf("輸入錯誤 \n");
       exit(1);
    }
    if ( chdir(argv[1]) != 0 )
       printf("更改目前目錄路徑 \n");
    system("pause");
    return 0;   
}
