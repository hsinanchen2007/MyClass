/*   �{���W�� : ch10_5.c                  */
/*   �p��r�����                         */
#include <stdio.h>
#include <stdlib.h>
int string_length(char s[])
{
    int i = 0;        /* �]�w�r������ܼ� */ 

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
    printf("�� 1 �Ӧr����� ==> %d \n",j);
    j = string_length(string2);
    printf("�� 2 �Ӧr����� ==> %d \n",j);
    system("pause");
    return 0;
}
