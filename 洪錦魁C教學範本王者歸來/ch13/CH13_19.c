/*   �{���W�� : ch13_19.c                 */
/*   open �M close �������               */
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
    int  fd;                  /* �ɮץN�� */

    if ( argc != 2 )
    {
       printf("��J���~ ");
       exit(1);
    }
    if ( (fd = open(argv[1],O_RDONLY)) == -1 )
    {
       printf("�}�ɥ��� \n");
       exit(1);
    }
    else
       printf("�}�� OK \n");

    if ( close(fd) == -1 )
       printf("���ɥ��� \n");
    else
       printf("���� OK \n");
    system("pause");
    return 0;   
}
