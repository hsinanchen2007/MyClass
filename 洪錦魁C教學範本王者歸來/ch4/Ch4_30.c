/*   �{���W�� : ch4_30.c                  */
/*   switch �M break �V�X����             */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i;

    for ( i = 1; i <= 5; i ++ )
       switch ( i )
       {
	      case 1 : printf("�p�G�A�p�e \n");
		       break;
	      case 2 : printf("��o�n¾��, �A���� \n");
	      case 3 : printf("�V�O�u�@ ");
		       break;
	      case 4 : printf("\n�۫H ");
	      case 5 : printf("�Τ��H \n");
       }
    system("pause");
    return 0;   
}
