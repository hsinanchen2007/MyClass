/*   程式名稱 : ch15_3.c                  */
/*   將字串轉成長整數                     */
#include <stdlib.h>
#include <stdio.h>
int main(void)
{
    long  value;
    char *str1 = "1233421";
    char *str2 = "123876tre";
    char *str3 = "r541231";

    value = atol(str1);
    printf("%ld \n",value);
    value = atol(str2);
    printf("%ld \n",value);
    value = atol(str3);
    printf("%ld \n",value);
    system("pause");
    return 0;
}
