/*   �{���W�� : ch12_10.c                 */
/*   ���� isspace() ���                  */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    char ch;

    while ( ch = getche() )
    {
       if ( isspace(ch) )
          break;
       putchar(ch);
       printf("\n");
    }
    system("pause");
    return 0;
}
