/*   �{���W�� : ch14_4.c                  */
/*   �p���ɮת���                         */
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
int main(int argc, char *argv[])
{
    long  length;
    int   fd;

    if ( argc != 2 )
       printf("��J���~ \n");
    fd = open(argv[1],O_RDONLY);
    length = filelength(fd);
    printf("%s �ɮת��׬O %ld\n",argv[1],length);
    system("pause");
    return 0; 
}
