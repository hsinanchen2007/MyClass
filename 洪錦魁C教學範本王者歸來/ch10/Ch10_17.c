/*   �{���W�� : ch10_17.c                 */
/*   strcat �������                      */
#include <stdio.h>
#include <string.h>
int main()
{
    char str1[80] = "���";
    char *str2 = "�Q�^";
    char *str;
    char *strcat();

    printf("��X�r��p�U \n");
    str = strcat(str1,str2);
    puts(str1);
    puts(str);
    system("pause");
    return 0;
}
