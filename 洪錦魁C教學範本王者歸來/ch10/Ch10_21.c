/*   程式名稱 : ch10_21.c                 */
/*   strlen 的應用                        */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char str1[80] = "Introduction to C";
    char *str2 = "This is a good book for C";
    int i;

    i = strlen(str1);
    printf("字串 1 長度 ==> %d\n",i);
    i = strlen(str2);
    printf("字串 2 長度 ==> %d\n",i);
    system("pause");
    return 0;
}
