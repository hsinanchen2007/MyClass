/*   �{���W�� : ch4_33.c                  */
/*   for �M continue ����                 */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i;

    for ( i = 0; i <= 100; i++ )
    {
       if ( i >= 5 )
	      continue;
       printf("���ެO %d \n",i);
    }
    system("pause");
    return 0;
}
