/*   �{���W�� : ch10_4.c                  */
/*   �r����                             */
#include <stdio.h>
#include <stdlib.h>
int string_compare(char s1[],char s2[],int n1,int n2)
{
    int  i;
    int  true = 1;
    int  false = 0;

    if ( n1 != n2 )           /* ����r����� */ 
       return false;          /* �r�ꤣ�P */
    else
       for ( i = 0; i < n1; i++ )
	      if ( s1[i] != s2[i] )
	         return false;    /* �r�ꤣ�P */
    return true;              /* �r��ۦP�Ǧ^ 1 */ 
}
int main()
{
    char string1[4] = { 't', 'e', 's', 't' };
    char string2[4] = { 't', 'e', 's', 't' };
    int  value;

    value = string_compare(string1,string2,4,4);
    if ( value )
       printf("�r��ۦP\n");
    else
       printf("�r�ꤣ�P\n");
    system("pause");
    return 0;   
}
