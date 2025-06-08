/*   程式名稱 : ch6_15.c                  */
/*   設計 1 + 2 + .... + n 之ANSI函數     */
#include <stdio.h>
#include <stdlib.h>
int sum(int n)     /* ANSI函數宣告方式 */ 
{
    int i,ret_sum;

    ret_sum = 0;
    for ( i = 1; i <= n; i++ )
       ret_sum += i;
    return ret_sum;
}
int main()
{
    int n;

    printf("請輸入系列加總值 ==> ");
    scanf("%d",&n);
    printf("從 1 加到 %d = %d\n",n,sum(n));
    system("pause");
    return 0;
}
