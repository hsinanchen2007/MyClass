/*   �{���W�� : ch4_19.c                  */
/*   �C�X����ȥi�ϥ� ctrl - c �������{�� */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i;

    while ( 1 )
    {
       printf("�п�J���N�� ==> ");
       scanf("%d",&i);
       if ( i < 0 )
          i = -i;
       printf("����ȬO %d \n",i);
    }
    system("pause");
    return 0;
}
