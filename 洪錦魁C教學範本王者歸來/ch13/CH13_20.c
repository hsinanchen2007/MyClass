/*   �{���W�� : ch13_20.c                 */
/*   �p���ɮת��r����                     */
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#define  size    512
int main(int argc, char *argv[])
{
    int  fd;                  /* �ɮץN�� */
    char buf[size];
    int  count = 0;
    int  i;

    if ( argc != 2 )
    {
       printf("��J���~ ");
       exit(1);
    }
    fd = open(argv[1],O_RDONLY);
    while ( ( i = read(fd,buf,size) ) > 0 )
       count += i;
    printf("%s ���r���ƬO %d\n",argv[1],count);
    close(fd);
    system("pause");
    return 0;
}
