/*   程式名稱 : ch4_14.c                  */
/*   將輸入直接輸出, 版本 2               */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char ch;

    while ( ( ch = getche() ) != '\r' )
    {
       putchar(ch);
       printf("\n");
    }
    system("pause");
    return 0;
}
