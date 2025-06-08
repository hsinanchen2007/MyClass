/*   程式名稱 : ch4_28.c                  */
/*   列印較大值                           */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a,b,z;

    printf("請輸入任意 2 數字 ==> ");
    scanf("%d%d",&a,&b);
    z = ( a > b ) ? a : b;
    printf("較大值是 %d \n",z);
    system("pause");
    return 0;
}
