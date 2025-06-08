/*   程式名稱 : ch10_26.c                 */
/*   相反方向輸出所輸入的句子             */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char str[4][80];
    int i;

    puts("請輸入 4 列句子");
    for ( i = 0; i < 4; i++ )
       gets(str[i]);
    puts("相反輸出如下");
    for ( i = 3; i >= 0; i-- )
       puts(str[i]);
    system("pause");
    return 0;
}
