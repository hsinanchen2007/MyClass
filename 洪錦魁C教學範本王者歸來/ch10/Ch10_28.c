/*   �{���W�� : ch10_28.c                 */
/*   main(argc,argv) ������               */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(argc,argv)
int argc;
char *argv[];
{
    int i;

    puts("��X�p�U");
    for ( i = 0; i < argc; i++ )
       puts(argv[i]);
    system("pause");
    return 0;
}
