/*   程式名稱 : ch12_9.c                  */
/*   測試 ispunct() 函數                  */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    int ch;

    for ( ;  ; )    
    {
       ch = getche();
       if ( ispunct(ch) )
       { 
          putchar(ch);
          printf("\n");
       }   
       else
          break;    /* 跳出 for 迴路 */ 
    }
    system("pause");
    return 0;
} 
