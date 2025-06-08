/*   程式名稱 : ch5_3.c                   */
/*   泡沫排序法                           */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int  i,j,tmp;
    int  num[5] = { 3,6,7,5,9 }; /* 欲排序數字 */ 

    for ( i = 1; i < 5; i++ )
    {
       for ( j = 0; j < 4; j++ )
          if ( num[j] > num[j+1] )
          {
             tmp = num[j];
             num[j] = num[j+1];
             num[j+1] = tmp;
          }
       printf("loop %d ",i);
       for ( j = 0; j < 5; j++ )
          printf("%4d",num[j]);
       printf("\n");
    }
    system("pause");
    return 0;          
}
