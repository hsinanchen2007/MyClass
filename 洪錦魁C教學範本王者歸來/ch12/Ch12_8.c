/*   �{���W�� : ch12_8.c                  */
/*   ���� isprint() ���                  */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    int ch;

    while ( ( ch = getche() ) != '\r' )
       if ( isprint(ch) )  /* �O�_�i�C�L */ 
       {
          putchar(ch);     /* �C�L */ 
          printf("\n");
       }
    system("pause");
    return 0;
}
