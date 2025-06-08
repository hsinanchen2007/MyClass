/*   程式名稱 : ch5_9.c                  */
/*   基本指標運算                        */
#include <stdio.h>
#include <stdlib.h>
int main()
{
   int i, k, *j;

   i = 5;
   j = &i;
   printf(" j = %d\n j 位址 = %u\n", *j, j);
   k = 10;
   *j = k; /* 也可以直接將變數設定給指標 */ 
   printf(" j = %d\n j 位址 = %u\n", *j, j);
   system("pause");
   return 0;
}
