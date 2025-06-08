/*   程式名稱 : ch4_10.c                  */
/*   改良前ㄧ個程式                       */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,sum;

    i = 1;
    sum = 0;
    while ( i <= 10 )
       sum += i++;
    printf("總和 = %d \n",sum);
    system("pause");
    return 0;
}
