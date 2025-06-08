/*   程式名稱 : ch4_23.c                  */
/*   繪製西洋棋盤                         */
#include <stdio.h>
#include <stdlib.h>
int main()
{
   int i,j;

   for ( i = 0; i < 8; i++ )
   {
      for ( j = 0; j < 8; j++ )
	 if ( ( i + j ) % 2 == 0 )
	    printf("%c%c",219,219); /* 列印黑方格 */
	 else
	    printf("  ");           /* 列印白方格 */
      printf("\n");
   }
   system("pause");
   return 0;
}
