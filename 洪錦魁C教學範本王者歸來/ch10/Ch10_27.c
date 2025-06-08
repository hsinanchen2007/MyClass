/*   程式名稱 : ch10_27.c                 */
/*   字串指標的應用                       */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char str[4][80];
    char *str1[4];
    int i;

    puts("請輸入 4 列句子");
    for ( i = 0; i < 4; i++ )
    {
       gets(str[i]);
       str1[i] = str[i];
    }
    puts("相反輸出如下");
    for ( i = 3; i >= 0; i-- )
       puts(str1[i]);
    system("pause");
    return 0;   
}
