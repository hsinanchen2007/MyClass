/*   程式名稱 : ch4_7.c                   */
/*   列出 9 * 9 乘法表使用雙層 for 迴路   */
/*   使用 != 運算子取代 <=                */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,j,result;

    for ( i = 1; i != 10; i++ )
    {
       for ( j = 1; j != 10; j++ )
       {
	       result = i * j;
	       printf("%d*%d=%-3d",i,j,result);
       }
       printf("\n");
    }
    system("pause");
    return 0;
}
