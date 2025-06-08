/*   程式名稱 : ch6_12.c                  */
/*   求階乘的遞迴函數設計                 */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i;
    int factorial();

    for ( i = 0; i < 5; i++ )  /* 求 0 到 4 的階乘 */ 
       printf("%d!  =  %d \n",i,factriol(i));
    system("pause");
    return 0;   
}
int factriol(j)
int j;
{
    int sum;                         /* 遞回階層數 */ 

    if ( j == 0 )                    /* 終止條件   */ 
       sum = 1;
    else
       sum = j * factriol( j - 1 );  /* 遞回呼叫   */ 
    return sum;
}
