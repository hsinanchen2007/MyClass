/*   �{���W�� : ch10_16.c                 */
/*   strcat �������                      */
#include <stdio.h>
#include <string.h>
int main()
{
    char str1[80] = "���";
    char *str2 = "�Q�^";

    printf("��X�r��p�U \n");
    strcat(str1,str2);
    puts(str1);
    system("pause");
    return 0;
}
