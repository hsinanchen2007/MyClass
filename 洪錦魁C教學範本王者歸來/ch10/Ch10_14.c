/*   �{���W�� : ch10_14.c                 */
/*   puts() �������                      */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char str1[80], *str2;
    char *gets();

    printf("�п�J�y�l .. \n");
    /* Ctrl - c �i�����{�� */ 
    while ( (str2 = gets(str1) ) != NULL )
    {
       printf("�r�� 1 ===> ");
       puts(str1);
       printf("�r�� 2 ===> ");
       puts(str2);
    }
    system("pause");
    return 0;
}
