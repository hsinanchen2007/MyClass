/*   程式名稱 : ch10_6.c                  */
/*   計算字串長度和比較字串內容是否相同   */
#include <stdio.h>
#include <stdlib.h>
int string_compare(char s1[], char s2[], int n1, int n2)
{
    int i;
    int true = 1;
    int false = 0;

    if ( n1 != n2 )               /* 比較字串長度 */
       return false;              /* 字串不同 */
    else
       for ( i = 0; i < n1; i++ )
          if ( s1[i] != s2[i] )
             return false;        /* 字串不同 */
    return true;                  /* 字串相同傳回 1 */
}
int string_length(char s[])
{
    int i = 0;     /* 設定字串長度變數 */

    while ( s[i] != '\0' )
       i++;
    return i;
}
int main()
{
    char string1[] = {'t','e','s','t','i','n','g','\0'};
    char string2[] = {'t','e','s','t','i','j','k','\0'};
    int  i,j;
    int  value;

    i = string_length(string1);
    printf("第 1 個字串長度 ==> %d \n",i);
    j = string_length(string2);
    printf("第 2 個字串長度 ==> %d \n",j);
    value = string_compare(string1,string2,i,j);
    if ( value )
       printf("字串相同 \n");
    else
       printf("字串不同 \n");
    system("pause");
    return 0; 
}
