/*   �{���W�� : ch10_12.c                 */
/*   �N gets() �ŧi���r�����             */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char str1[80], *str2;
    char *gets();

    printf("�п�J�y�l .. \n");
    str2 = gets(str1);
    printf("�r�� 1  ===> %s\n",str1);
    printf("�r�� 2  ===> %s\n",str2);
    system("pause");
    return 0;
}
