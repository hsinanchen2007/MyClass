/*   程式名稱 : ch12_4.c                  */
/*   測試 iscntrl() 函數                  */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    char ch;

    do
    {
       ch = getche();
       if ( isalpha(ch) )  /* 輸入是ㄧ般字元 */ 
       {
          putchar(ch);     /* 列印 */ 
          printf("\n");
       }
    }  while ( iscntrl(ch) );
    system("pause");
    return 0;
}
