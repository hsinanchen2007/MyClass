/*   程式名稱 : ch4_34.c                          */
/*   計算 2 + 4 + .... + 100 使用 for 和 continue */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,sum;

    sum = 0;
    for ( i = 2; i <= 100; i++ )
    {
       if ( ( i % 2 ) != 0 )
	      continue;
       sum += i;
    }
    printf("總和是 %d \n",sum);
    system("pause");
    return 0;
}
