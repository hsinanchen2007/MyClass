/*   �{���W�� : ch4_32.c                  */
/*   �L���j���q�Ʀr                       */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i;
    int count = 1;
    for ( ; ; )
    {
       printf("��J���q�Ʀr ");
       scanf("%d",&i);
       if ( i == 5 )   /* �]�w���q�Ʀr */ 
	      break;
       count++;
    }
    printf("�� %d ���q�� \n",count);
    system("pause");
    return 0;
}
