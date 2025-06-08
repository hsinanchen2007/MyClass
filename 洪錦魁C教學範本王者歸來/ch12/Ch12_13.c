/*   程式名稱 : ch12_13.c                 */
/*   測試 tolower() 和 toupper() 函數     */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    char ch;

    while ( (ch = getche()) != '\r' )
    {
       if ( islower(ch) != 0 )
          putchar(toupper(ch));
       else
          if ( isupper(ch) != 0 )
             putchar(tolower(ch));
       printf("\n");
    }
    system("pause");
    return 0;
}
