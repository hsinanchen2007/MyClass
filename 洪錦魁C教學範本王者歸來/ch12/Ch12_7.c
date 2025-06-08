/*   祘Α嘿 : ch12_7.c                  */
/*   代刚 islower() ㄧ计                  */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int count = 0;
    int ch;

    while ( ( ch = getche() ) != '\r' )
       if ( islower(ch) )  /* 狦琌糶じ */ 
          count++;         /* 仓璸Ω计 */ 
    printf("\n糶じ计 = %d\n",count);
    system("pause");
    return 0;
}
