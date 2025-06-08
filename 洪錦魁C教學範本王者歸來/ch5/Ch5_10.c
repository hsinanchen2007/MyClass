/*   程式名稱 : ch5_10.c                  */
/*   使用指標執行陣列相加                 */
#include <stdio.h>
#include <stdlib.h>
int main()
{
   int array[5];
   int *ptr, sum, i;

   printf("請輸入 5 個整數 \n");
   for ( i = 0; i < 5; i++ )
      scanf("%d",&array[i]);
   sum = 0;
   for ( ptr = array; ptr < &array[5]; ptr++ )
      sum += *ptr;
   printf("陣列整數和是 %d\n",sum);
   system("pause");
   return 0;
}
