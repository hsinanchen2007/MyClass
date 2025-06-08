/*   程式名稱 : ch10_22.c                 */
/*   strncat 的應用                       */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char str1[80] = "Introduction to C";
    char *str2 = "This is a good book for C";

    puts("第 1 次字串結合");
    strncat(str1,str2,4);
    puts(str1);
    puts("第 2 次字串結合");
    strncat(str1,str2,50);
    puts(str1);
    system("pause");
    return 0;
}
