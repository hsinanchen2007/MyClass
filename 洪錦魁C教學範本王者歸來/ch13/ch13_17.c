/*   �{���W�� : ch13_17.c                 */
/*   �ɮת���X                           */
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    FILE *fp;
    char ch;

    if ( argc != 2 )
    {
       printf("���O���~ ");
       exit(1);
    }
    fp = fopen(argv[1],"r");
    while ( (ch = getc(fp)) != EOF )
       putc(ch,stdout);  /* �C�L��ƨ�ù� */ 
    fclose(fp);
    system("pause");
    return 0;
}
