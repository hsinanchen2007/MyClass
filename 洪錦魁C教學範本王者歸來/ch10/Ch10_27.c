/*   �{���W�� : ch10_27.c                 */
/*   �r����Ъ�����                       */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char str[4][80];
    char *str1[4];
    int i;

    puts("�п�J 4 �C�y�l");
    for ( i = 0; i < 4; i++ )
    {
       gets(str[i]);
       str1[i] = str[i];
    }
    puts("�ۤϿ�X�p�U");
    for ( i = 3; i >= 0; i-- )
       puts(str1[i]);
    system("pause");
    return 0;   
}
