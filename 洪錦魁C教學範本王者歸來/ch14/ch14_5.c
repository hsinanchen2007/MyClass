/*   程式名稱 : ch14_5.c                  */
/*   建立子目錄                           */
#include <stdio.h>
#include <stdlib.h> 
int main(int argc, char *argv[])
{

    if ( argc != 2 )
       printf("輸入錯誤 \n");
    if ( mkdir(argv[1]) == -1 )
       printf("建立子目錄錯誤 \n");
    system("pause");
    return 0;   
}
