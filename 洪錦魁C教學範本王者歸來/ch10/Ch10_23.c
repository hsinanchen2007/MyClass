/*   �{���W�� : ch10_23.c                 */
/*   strncmp ������                       */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char str1[80] = "Borland C++ Introduction";
    char *str2 = "Visual C++ Introduction";
    int i;

    i = strncmp(str1,str2,10);
    if ( i == 0 )
       printf("�e 10 �Ӧr���۵� \n");
    else if ( i > 0 )
    {
       printf("�e 10 �Ӧr�����P \n");
       puts("str1 �r���Ȥj�� str2");
    }
    else
    {
       printf("�e 10 �Ӧr�����P \n");
       puts("str2 �r���Ȥj�� str1");
    }
    system("pause");
    return 0;
}
