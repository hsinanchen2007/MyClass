/*   �{���W�� : ch5_11.c                  */
/*   �t���ؤ�k�ϥΫ��а���}�C�ۥ[       */
#include <stdio.h>
#include <stdlib.h>
int main()
{
   int array[5];
   int sum, i;

   printf("�п�J 5 �Ӿ�� \n");
   for ( i = 0; i < 5; i++ )
      scanf("%d",&array[i]);
   sum = 0;
   for ( i = 0; i < 5; i++ )
      sum += *( array + i );
   printf("�}�C��ƩM�O %d\n",sum);
   system("pause");
   return 0;
}
