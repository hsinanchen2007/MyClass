/*   program name : ch13_23.c                         */
/*   Design the TYPE command.                         */
/* ================================================== */
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int  fd;                    /* file handle */
    int  ch;

    if ( argc != 2 )
    {
       printf("\1: input argument error! ");
       exit(1);
    }
    setmode(1,O_BINARY);
    fd = open(argv[1],O_RDONLY | O_BINARY);
    while ( read(fd,ch,sizeof(ch)) == sizeof(ch) )
       write(1,ch,sizeof(ch));
    close(fd);
    system("pause");
    return 0;
}
