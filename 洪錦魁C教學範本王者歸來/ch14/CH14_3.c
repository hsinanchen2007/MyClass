/*   程式名稱 : ch14_3.c                  */
/*   更改檔案名稱                         */
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int i;

    if ( argc != 3 )
       printf("輸入錯誤 \n");
    rename(argv[1],argv[2]);    
    system("pause");
    return 0;  
}
