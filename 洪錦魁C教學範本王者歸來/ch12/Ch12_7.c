/*   程式名稱 : ch12_7.c                  */
/*   測試 islower() 函數                  */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int count = 0;
    int ch;

    while ( ( ch = getche() ) != '\r' )
       if ( islower(ch) )  /* 如果是小寫字元 */ 
          count++;         /* 累計次數 */ 
    printf("\n小寫字元個數 = %d\n",count);
    system("pause");
    return 0;
}
