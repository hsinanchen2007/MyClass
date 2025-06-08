/*   程式名稱 : ch12_5.c                  */
/*   測試 isdigit() 函數                  */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    char ch;

    ch = getche();
    if ( isdigit(ch) )
    {
       putchar(ch);     /* 列印數字 */ 
       printf("\n");
    }
    system("pause");
    return 0;
}
