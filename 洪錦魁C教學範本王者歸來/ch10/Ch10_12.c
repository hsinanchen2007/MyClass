/*   程式名稱 : ch10_12.c                 */
/*   將 gets() 宣告成字串指標             */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char str1[80], *str2;
    char *gets();

    printf("請輸入句子 .. \n");
    str2 = gets(str1);
    printf("字串 1  ===> %s\n",str1);
    printf("字串 2  ===> %s\n",str2);
    system("pause");
    return 0;
}
