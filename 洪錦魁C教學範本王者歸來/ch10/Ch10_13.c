/*   程式名稱 : ch10_13.c                 */
/*   將輸入字串重複輸出  ctrl - c 可結束  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char str1[80], *str2;
    char *gets();

    printf("請輸入句子 .. \n");
    while ( (str2 = gets(str1) ) != NULL )
    {
       printf("字串 1 ===> %s\n",str1);
       printf("字串 2 ===> %s\n",str2);
    }
    system("pause");
    return 0;
}
