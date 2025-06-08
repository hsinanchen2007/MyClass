/*   程式名稱 : ch12_10.c                 */
/*   測試 isspace() 函數                  */
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
