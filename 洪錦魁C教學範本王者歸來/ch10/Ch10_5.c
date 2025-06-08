/*   程式名稱 : ch10_5.c                  */
/*   計算字串長度                         */
#include <stdio.h>
#include <stdlib.h>
int string_length(char s[])
{
    int i = 0;        /* 設定字串長度變數 */ 

    while ( s[i] != '\0' )
       i++;
    return i;
}
int main()
{
    char string1[] = {'t','e','s','t','i','n','g','\0'};
    char string2[] = {'t','e','s','t','\0'};
    int  j = 0;

    j = string_length(string1);
    printf("第 1 個字串長度 ==> %d \n",j);
    j = string_length(string2);
    printf("第 2 個字串長度 ==> %d \n",j);
    system("pause");
    return 0;
}
