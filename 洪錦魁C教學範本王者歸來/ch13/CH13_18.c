/*   �{���W�� : ch13_18.c                 */
/*   �]�p PRINT ���O                      */
/* �A�� �з� C   Turbo/Visual C           */ 
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    FILE *fp;
    char ch;

    if ( argc != 2 )
    {
       printf("��J���~ \n");
       exit(1);
    }
    fp = fopen(argv[1],"rb");
    while ( (ch = getc(fp)) != EOF )
       putc(ch,stdprn);    /* �ѦL����C�L */ 
    fclose(fp);
    system("pause");
    return 0;
}
