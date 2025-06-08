/*   �{���W�� : ch10_6.c                  */
/*   �p��r����שM����r�ꤺ�e�O�_�ۦP   */
#include <stdio.h>
#include <stdlib.h>
int string_compare(char s1[], char s2[], int n1, int n2)
{
    int i;
    int true = 1;
    int false = 0;

    if ( n1 != n2 )               /* ����r����� */
       return false;              /* �r�ꤣ�P */
    else
       for ( i = 0; i < n1; i++ )
          if ( s1[i] != s2[i] )
             return false;        /* �r�ꤣ�P */
    return true;                  /* �r��ۦP�Ǧ^ 1 */
}
int string_length(char s[])
{
    int i = 0;     /* �]�w�r������ܼ� */

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
    printf("�� 1 �Ӧr����� ==> %d \n",i);
    j = string_length(string2);
    printf("�� 2 �Ӧr����� ==> %d \n",j);
    value = string_compare(string1,string2,i,j);
    if ( value )
       printf("�r��ۦP \n");
    else
       printf("�r�ꤣ�P \n");
    system("pause");
    return 0; 
}
