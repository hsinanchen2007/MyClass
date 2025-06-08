/*   程式名稱 : ch10_20.c                 */
/*   strcpy 函數的應用                    */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char str1[80] = "Introduction to C";
    char *str2 = "This is a good book for C";
    char *s;
    char *strcpy();

    puts("呼叫 strcpy 前");
    printf("str1 = %s\n",str1);
    printf("str2 = %s\n",str2);
    s = strcpy(str1,str2);
    puts("呼叫 strcpy 後");
    printf("str1 = %s\n",str1);
    printf("str2 = %s\n",str2);
    printf("str2 = %s\n",s);
    system("pause");
    return 0;
}
