/*   �{���W�� : ch5_9.c                  */
/*   �򥻫��йB��                        */
#include <stdio.h>
#include <stdlib.h>
int main()
{
   int i, k, *j;

   i = 5;
   j = &i;
   printf(" j = %d\n j ��} = %u\n", *j, j);
   k = 10;
   *j = k; /* �]�i�H�����N�ܼƳ]�w������ */ 
   printf(" j = %d\n j ��} = %u\n", *j, j);
   system("pause");
   return 0;
}
