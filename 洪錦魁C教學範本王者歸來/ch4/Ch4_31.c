/*   程式名稱 : ch4_31.c                  */
/*   for 和 break 混合應用                */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i;

    for ( i = 1; i <= 100; i ++ )
    {
       printf("迴路索引 %d \n",i);
       if ( i >= 5 )
	      break;
    }
    system("pause");
    return 0;
}
