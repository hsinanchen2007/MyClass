/*   程式名稱 : ch10_4.c                  */
/*   字串比較                             */
#include <stdio.h>
#include <stdlib.h>
int string_compare(char s1[],char s2[],int n1,int n2)
{
    int  i;
    int  true = 1;
    int  false = 0;

    if ( n1 != n2 )           /* 比較字串長度 */ 
       return false;          /* 字串不同 */
    else
       for ( i = 0; i < n1; i++ )
	      if ( s1[i] != s2[i] )
	         return false;    /* 字串不同 */
    return true;              /* 字串相同傳回 1 */ 
}
int main()
{
    char string1[4] = { 't', 'e', 's', 't' };
    char string2[4] = { 't', 'e', 's', 't' };
    int  value;

    value = string_compare(string1,string2,4,4);
    if ( value )
       printf("字串相同\n");
    else
       printf("字串不同\n");
    system("pause");
    return 0;   
}
