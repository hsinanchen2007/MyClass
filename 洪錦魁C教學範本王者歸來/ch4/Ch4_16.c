/*   �{���W�� : ch4_16.c                  */
/*   ø�s����ϧ�                         */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,j;

    i = 5;
    while ( i <= 9 )
    {
       j = 1;
       while ( j++ <= ( 9 - i ) )
	      printf(" ");
       j = 9;
       while ( ( j++ - i ) < i )
	      printf("%c",1);
       i++;
       printf("\n");
    }
    system("pause");
    return 0;
}
