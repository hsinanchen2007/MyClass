/*   程式名稱 : ch13_1.c                  */
/*   fopen() 應用                         */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fp;

    if ( ( fp = fopen("sample.txt","r") ) == NULL )
       printf("檔案開啟失敗 \n");
    else
       printf("檔案開啟OK \n");
    system("pause");
    return 0;   
}
