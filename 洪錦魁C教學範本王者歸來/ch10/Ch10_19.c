/*   �{���W�� : ch10_19.c                 */
/*   strcpy �������                      */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char str1[80] = "Introduction to C";
    char *str2 = "This is a good book for C";

    puts("�I�s strcpy �e");
    printf("str1 = %s\n",str1);
    printf("str2 = %s\n",str2);
    strcpy(str1,str2);
    puts("�I�s strcpy ��");
    printf("str1 = %s\n",str1);
    printf("str2 = %s\n",str2);
    system("pause");
    return 0;
}
