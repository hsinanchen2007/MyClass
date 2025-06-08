/*   程式名稱 : ch10_7.c                  */
/*   簡單宣告字串同時將字串顯示在螢幕上   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char string[] = "Hello !";
    int  i = 0;

    while ( string[i] != '\0' )
       printf("%c",string[i++]);
    printf("\n");
    system("pause");
    return 0;
}
