/*   程式名稱 : ch10_2.c                  */
/*   簡易字串拷貝                         */
#include <stdio.h>
#include <stdlib.h>
void string_copy(char s1[], char s2[], int num)
{
    int j;
    for ( j = 0; j < num; j++ )
        s2[j] = s1[j];  /* 將 s1 字串內容放至 s2 */ 
}        
int main()
{
    char str1[5] = {'B','o','o','k','s'};
    char str2[5];
    int  i;

    string_copy(str1,str2,5);
    for ( i = 0; i < 5; i++ )  /* 列印字串 */ 
        printf("%c",str2[i]);
    printf("\n");
    system("pause");
    return 0;
}












































































































































































































