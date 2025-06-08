/*   程式名稱 : ch4_6.c                   */
/*   列出 9 * 9 乘法表使用雙層 for 迴路   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,j,result;

    for ( i = 1; i <= 9; i++ )
    {
       for ( j = 1; j <= 9; j++ )
       {
	       result = i * j;
	       printf("%d*%d=%-3d",i,j,result);
       }
       printf("\n");
    }
    system("pause");
    return 0;
}
