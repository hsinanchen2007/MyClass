/*   程式名稱 : ch10_18.c                 */
/*   strcmp 函數應用                      */
#include <stdio.h>
#include <string.h>
int main()
{
    char str1[80] = "Borland C++ Introduction";
    char *str2 = "Visual C++ Introduction";
    int i;

    i = strcmp(str1,str2);
    if ( i == 0 )
       printf("字串相同 \n");
    else if ( i > 0 )
    {
       printf("字串不同 \n");
       puts("str1 字元值大於 str2");
    }
    else
    {
       printf("字串不同 \n");
       puts("str2 字元值大於 str1");
    }
    system("pause");
    return 0;
}
