/*   程式名稱 : ch5_4.c                   */
/*   改良泡沫排序法                       */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int  i,j,tmp;
    int  num[] = { 3,6,7,5,9 }; /* 欲排序數字 */
    int  flag;

    for ( i = 1; i < 5; i++ )
    {
       flag = 1;
       for ( j = 0; j < 4; j++ )
	      if ( num[j] > num[j+1] )
	      {
	          tmp = num[j];
	          num[j] = num[j+1];
	          num[j+1] = tmp;
	          flag = 0;
	      }
       if ( flag )
          break;
       printf("loop %d ",i);
       for ( j = 0; j < 5; j++ )
	      printf("%4d",num[j]);
       printf("\n");
    }
    system("pause");
    return 0;
}
