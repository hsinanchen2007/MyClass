/*   �{���W�� : ch14_8.c                  */
/*   ���ثe�ؿ����|                     */
#include <stdio.h>
#include <stdlib.h> 
int main(int argc, char *argv[])
{
    if ( argc != 2 )
    {
       printf("��J���~ \n");
       exit(1);
    }
    if ( chdir(argv[1]) != 0 )
       printf("���ثe�ؿ����| \n");
    system("pause");
    return 0;   
}
