/*   �{���W�� : ch10_21.c                 */
/*   strlen ������                        */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char str1[80] = "Introduction to C";
    char *str2 = "This is a good book for C";
    int i;

    i = strlen(str1);
    printf("�r�� 1 ���� ==> %d\n",i);
    i = strlen(str2);
    printf("�r�� 2 ���� ==> %d\n",i);
    system("pause");
    return 0;
}
