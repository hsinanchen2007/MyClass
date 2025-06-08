/*   程式名稱 : ch14_6.c                  */
/*   刪除子目錄                           */
#include <stdio.h>
#include <stdlib.h>
void main(int argc, char *argv[])
{

    if ( argc != 2 )
       printf("輸入錯誤 \n");
    if ( rmdir(argv[1]) == -1 )
       printf("刪除子目錄錯誤 \n");
    system("pause");
    return 0;   
}
