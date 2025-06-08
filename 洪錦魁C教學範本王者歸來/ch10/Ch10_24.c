/*   程式名稱 : ch10_24.c                 */
/*   strncpy 的應用                       */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char str1[80] = "Introduction to C";
    char *str2 = "This is a good book for C";

    puts("呼叫 strcpy 前");
    printf("str1 = %s\n",str1);
    printf("str2 = %s\n",str2);
    strncpy(str1,str2,10);
    puts("呼叫 strcpy 第 1 次後");
    printf("str1 = %s\n",str1);
    printf("str2 = %s\n",str2);
    strncpy(str1,str2,60);
    puts("呼叫 strcpy 第 2 次後");
    printf("str1 = %s\n",str1);
    printf("str2 = %s\n",str2);
    system("pause");
    return 0;
}
