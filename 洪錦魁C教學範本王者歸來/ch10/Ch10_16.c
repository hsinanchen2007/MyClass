/*   程式名稱 : ch10_16.c                 */
/*   strcat 函數應用                      */
#include <stdio.h>
#include <string.h>
int main()
{
    char str1[80] = "文魁";
    char *str2 = "松崗";

    printf("輸出字串如下 \n");
    strcat(str1,str2);
    puts(str1);
    system("pause");
    return 0;
}
