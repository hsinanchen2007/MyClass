/*   程式名稱 : ch4_33.c                  */
/*   for 和 continue 應用                 */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i;

    for ( i = 0; i <= 100; i++ )
    {
       if ( i >= 5 )
	      continue;
       printf("索引是 %d \n",i);
    }
    system("pause");
    return 0;
}
