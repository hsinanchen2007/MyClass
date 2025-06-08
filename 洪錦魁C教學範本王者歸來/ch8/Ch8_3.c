/*   程式名稱 : ch8_3.c                   */
/*   #define 的另ㄧ個應用                 */
#include <stdio.h>
#include <stdlib.h>
#define   TRUE   1
#define   FALSE  0
#define   SQ(x)  ( x * x )

int main()
{
    int num;
    int again = 1;

    printf("如果輸入小於 50 程式將自動結束 \n");
    while ( again )   /* 如果大於或等於 50 程式繼續 */ 
    {
       printf("請輸入數值 ==> ");
       scanf("%d",&num);
       printf("平方值是 = %d \n",SQ(num));
       if ( num >= 50 )      
          again = TRUE;
       else
          again = FALSE;  /* 輸入小於 50 則設定 */ 
    }
    system("pause");
    return 0;
}
