/*   程式名稱 : ch4_13.c                  */
/*   將輸入直接輸出, 版本 1               */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char ch;

    ch = getche();
    while ( ch != '\r' )
    {
       putchar(ch);
       printf("\n");
       ch = getche();
    }
    system("pause");
    return 0;
}
