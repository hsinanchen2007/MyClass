/*   程式名稱 : ch13_2.c                  */
/*   fclose() 應用                        */
#include <stdio.h>
#include <stdlib.h> 
int main()
{
    FILE *fp;
    int  ret_code;

    if ( ( fp = fopen("ch13_1.c","r") ) == NULL )
    { 
       printf("檔案開啟失敗! \n");
       system("pause");
       exit(1); 
    }
    else
       printf("檔案開啟OK \n");
    if ( ( ret_code = fclose(fp) ) == NULL )
       printf("檔案關閉OK \n");
    system("pause");
    return 0;   
}
