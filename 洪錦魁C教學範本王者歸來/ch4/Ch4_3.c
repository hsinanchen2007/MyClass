/*   程式名稱 : ch4_3.c                   */
/*   計算 1 + 2 + ..... + 100             */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int sum = 0;
    int i = 1;

    for ( ; i <= 100; )
       sum += i++;
    printf("總和 = %d \n",sum);
    system("pause");
    return 0;
}
