/*   程式名稱 : ch4_19.c                  */
/*   列出絕對值可使用 ctrl - c 結束本程式 */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i;

    while ( 1 )
    {
       printf("請輸入任意值 ==> ");
       scanf("%d",&i);
       if ( i < 0 )
          i = -i;
       printf("絕對值是 %d \n",i);
    }
    system("pause");
    return 0;
}
