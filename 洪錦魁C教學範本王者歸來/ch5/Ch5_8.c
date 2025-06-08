/*   程式名稱 : ch5_8.c                   */
/*   基本指標運算                         */
#include <stdio.h>
#include <stdlib.h>
int main()
{
   int *ptr, i, val;

   i = 20;
   ptr = &i;
   val = *ptr;
   printf("*ptr = %d   val = %d\n", *ptr, val);
   system("pause");
   return 0;
}
