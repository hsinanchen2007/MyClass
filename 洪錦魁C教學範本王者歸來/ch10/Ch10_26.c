/*   �{���W�� : ch10_26.c                 */
/*   �ۤϤ�V��X�ҿ�J���y�l             */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char str[4][80];
    int i;

    puts("�п�J 4 �C�y�l");
    for ( i = 0; i < 4; i++ )
       gets(str[i]);
    puts("�ۤϿ�X�p�U");
    for ( i = 3; i >= 0; i-- )
       puts(str[i]);
    system("pause");
    return 0;
}
