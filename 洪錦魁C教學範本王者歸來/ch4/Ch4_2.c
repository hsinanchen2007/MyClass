/*   程式名稱 name : ch4_2.c              */
/*   計算 1 + 2 + ..... + 100             */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int sum = 0;
    int i;

    for ( i = 1; i <= 100; i++ )
       sum += i;
    printf("總和 = %d \n",sum);
    system("pause");
    return 0; 
}
