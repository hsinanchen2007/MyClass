/*   程式名稱 : ch10_10.c                 */
/*   簡易字串指標                         */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char *str1 = "Hello !";
    char *str2;

    str2 = str1;
    printf("字串 1 ===> %s\n",str1);
    printf("字串 2 ===> %s\n",str2);
    system("pause");
    return 0;
}
