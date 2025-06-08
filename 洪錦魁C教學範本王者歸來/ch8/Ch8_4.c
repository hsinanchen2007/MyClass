/*   程式名稱 : ch8_4.c                   */
/*   #define 的應用 4                     */
#include <stdio.h>
#include <stdlib.h>
#define   MAX(a,b)    ( a > b ) ? a : b

int main()
{
    int x,y,max;

    x = 5;
    y = 10;
    max = MAX(x,y);
    printf("較大值 = %d\n",max);
    system("pause");
    return 0;
}
