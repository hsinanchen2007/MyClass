/*   �{���W�� : ch10_29.c                 */
/*   main(argc,argv) ������               */
#include <stdio.h>
#include <stdlib.h>
int main(int argc,char *argv[])
{
    int i;

    puts("��X�p�U");
    for ( i = 0; i < argc; i++ )
       puts(argv[i]);
    system("pause");
    return 0;
}
