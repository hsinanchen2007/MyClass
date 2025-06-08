/*   程式名稱 : ch10_14.c                 */
/*   puts() 函數應用                      */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char str1[80], *str2;
    char *gets();

    printf("請輸入句子 .. \n");
    /* Ctrl - c 可結束程式 */ 
    while ( (str2 = gets(str1) ) != NULL )
    {
       printf("字串 1 ===> ");
       puts(str1);
       printf("字串 2 ===> ");
       puts(str2);
    }
    system("pause");
    return 0;
}
