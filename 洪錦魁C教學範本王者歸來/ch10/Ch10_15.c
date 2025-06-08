/*   程式名稱 : ch10_15.c                 */
/*   puts() 的應用                        */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char str1[80] = "UNIX C Introduction";
    char *str2 = "Introduction to UNIX";

    printf("字串輸出如下 \n");
    puts(str1);
    puts(str2);
    puts(str1+4);
    puts(&str1[4]);
    puts(str2+5);
    system("pause");
    return 0;
}
