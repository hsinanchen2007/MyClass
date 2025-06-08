/*   程式名稱 : ch12_11.c                 */
/*   測試 isupper() 函數                  */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    char ch;

    while ( ch = getche() )
    {
       if ( isupper(ch) == 0 )
          break;
       putchar(ch);
       printf("\n");
    }
    system("pause");
    return 0;
}
