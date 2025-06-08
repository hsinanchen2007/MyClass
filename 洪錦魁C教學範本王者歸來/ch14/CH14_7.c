/*   程式名稱 : ch14_7.c                  */
/*   獲得目前目錄路徑                     */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char pathname[81];

    if ( getcwd(pathname,80) == NULL )
    {
       printf("獲得目前目錄路徑錯誤 \n");
       exit(1);
    }
    printf("目前目錄路徑是 %s\n",pathname);
    system("pause");
    return 0;
}
