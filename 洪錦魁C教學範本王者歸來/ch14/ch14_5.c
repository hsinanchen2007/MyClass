/*   �{���W�� : ch14_5.c                  */
/*   �إߤl�ؿ�                           */
#include <stdio.h>
#include <stdlib.h> 
int main(int argc, char *argv[])
{

    if ( argc != 2 )
       printf("��J���~ \n");
    if ( mkdir(argv[1]) == -1 )
       printf("�إߤl�ؿ����~ \n");
    system("pause");
    return 0;   
}
