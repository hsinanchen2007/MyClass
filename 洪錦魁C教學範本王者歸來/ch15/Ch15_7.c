/*   程式名稱 : ch15_7.c                  */
/*   使用 rand() 函數列出 10 個隨機數     */
#include <stdlib.h>
#include <stdio.h>
int main()
{
    int  i;

    for ( i = 0; i < 10; i++ )
       printf("%d\n",rand());
    system("pause");
    return 0;   
}
