/*   程式名稱 : ch4_8.c                   */
/*   列印樓梯                             */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,j;

    printf(" \n");    /* 最上留空白 */ 
    for ( i = 1; i <= 10; i++ )
    {
       for ( j = 1; j <= i; j++ )
	      printf("%c%c",97,97);
       printf("\n");
    }
    system("pause");
    return 0;
}
