/*   �{���W�� : ch14_6.c                  */
/*   �R���l�ؿ�                           */
#include <stdio.h>
#include <stdlib.h>
void main(int argc, char *argv[])
{

    if ( argc != 2 )
       printf("��J���~ \n");
    if ( rmdir(argv[1]) == -1 )
       printf("�R���l�ؿ����~ \n");
    system("pause");
    return 0;   
}
