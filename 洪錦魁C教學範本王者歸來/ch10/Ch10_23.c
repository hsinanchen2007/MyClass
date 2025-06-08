/*   程式名稱 : ch10_23.c                 */
/*   strncmp 的應用                       */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char str1[80] = "Borland C++ Introduction";
    char *str2 = "Visual C++ Introduction";
    int i;

    i = strncmp(str1,str2,10);
    if ( i == 0 )
       printf("前 10 個字元相等 \n");
    else if ( i > 0 )
    {
       printf("前 10 個字元不同 \n");
       puts("str1 字元值大於 str2");
    }
    else
    {
       printf("前 10 個字元不同 \n");
       puts("str2 字元值大於 str1");
    }
    system("pause");
    return 0;
}
