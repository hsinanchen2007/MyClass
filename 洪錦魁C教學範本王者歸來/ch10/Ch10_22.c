/*   �{���W�� : ch10_22.c                 */
/*   strncat ������                       */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char str1[80] = "Introduction to C";
    char *str2 = "This is a good book for C";

    puts("�� 1 ���r�굲�X");
    strncat(str1,str2,4);
    puts(str1);
    puts("�� 2 ���r�굲�X");
    strncat(str1,str2,50);
    puts(str1);
    system("pause");
    return 0;
}
