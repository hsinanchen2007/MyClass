/*   �{���W�� : ch12_4.c                  */
/*   ���� iscntrl() ���                  */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    char ch;

    do
    {
       ch = getche();
       if ( isalpha(ch) )  /* ��J�O����r�� */ 
       {
          putchar(ch);     /* �C�L */ 
          printf("\n");
       }
    }  while ( iscntrl(ch) );
    system("pause");
    return 0;
}
