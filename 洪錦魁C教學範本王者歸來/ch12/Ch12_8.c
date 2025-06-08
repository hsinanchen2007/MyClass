/*   程式名稱 : ch12_8.c                  */
/*   測試 isprint() 函數                  */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    int ch;

    while ( ( ch = getche() ) != '\r' )
       if ( isprint(ch) )  /* 是否可列印 */ 
       {
          putchar(ch);     /* 列印 */ 
          printf("\n");
       }
    system("pause");
    return 0;
}
