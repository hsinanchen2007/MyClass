/*   �{���W�� : ch4_24.c                  */
/*   �_���j������                         */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char ch;
    int year;

    printf("�A�O�_�n�r�� ?(y/n) ");
    ch = getche();
    printf("\n");
    if ( ch == 'y' )
    {
       printf("�A�X�� ? ");
       scanf("%d",&year);
       if ( year < 18 )
	      printf("�藍�_�A�~�֤Ӥp \n");
       else
	      printf("�A�ݭn�Ҿr�� \n");
    }
    system("pause");
    return 0;
}
