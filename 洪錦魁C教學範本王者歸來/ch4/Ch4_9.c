/*   程式名稱 : ch4_9.c                   */
/*   執行 1 + 2 + ..... + 10 使用 while   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,sum;

    i = 1;
    sum = 0;
    while ( i <= 10 )
    {
       sum += i;
       i++;
    }
    printf("總和 = %d \n",sum);
    system("pause");
    return 0;
}
