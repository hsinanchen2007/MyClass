/*   �{���W�� : ch13_21.c                 */
/*   �]�p�����ɮ׫��O                     */
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#define  size    512
int main(int argc, char *argv[])
{
    int  fd1,fd2; /* fd1�ӷ���  fd2�ت��ɪ��ɮץN�� */
    char buf[size];
    int  sizeread;

    if ( argc != 3 )
    {
       printf("��J���~ ");
       exit(1);
    }
    fd1 = open(argv[1],O_RDONLY); /* �}�Ҩӷ��� */ 
    fd2 = open(argv[2],O_CREAT);  /* �}�ҥت��� */ 
    while ( !eof(fd1) ) 
    {
       sizeread = read(fd1,buf,size);
       write(fd2,buf,sizeread);   /* ���� */
    }
    close(fd1);                   /* �����ӷ��� */ 
    close(fd2);                   /* �����ت��� */ 
    system("pause");
    return 0;
}
