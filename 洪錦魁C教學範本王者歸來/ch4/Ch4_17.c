/*   程式名稱 : ch4_17.c                     */
/*   執行 1 + 2 + .... + 100 使用 do ..while */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,sum;

    i = 1;
    sum = 0;
    do
    {
       sum += i++;
    } while ( i <= 100 );
    printf("總和 = %d \n",sum);
    system("pause");
    return 0;
}
