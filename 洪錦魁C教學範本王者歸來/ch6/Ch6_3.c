/*   程式名稱 : ch6_3.c                   */
/*   列印較大值函數                       */
#include <stdio.h>
#include <stdlib.h>
void larger_value( a, b )
int a,b;
{
    if ( a < b )
       printf("較大值是 %d \n",b);
    else if ( a > b )
       printf("較大值是 %d \n",a);
    else
       printf("兩數值相等 \n");
}
int main()
{
    int i,j;

    printf("請輸入兩數值 \n ==> ");
    scanf("%d %d",&i,&j);
    larger_value(i,j);
    system("pause");
    return 0;
}
