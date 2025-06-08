/*   程式名稱 : ch4_30.c                  */
/*   switch 和 break 混合應用             */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i;

    for ( i = 1; i <= 5; i ++ )
       switch ( i )
       {
	      case 1 : printf("如果你計畫 \n");
		       break;
	      case 2 : printf("獲得好職務, 你必須 \n");
	      case 3 : printf("努力工作 ");
		       break;
	      case 4 : printf("\n相信 ");
	      case 5 : printf("或不信 \n");
       }
    system("pause");
    return 0;   
}
