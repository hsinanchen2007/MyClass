/*   �{���W�� : ch10_10.c                 */
/*   ²���r�����                         */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char *str1 = "Hello !";
    char *str2;

    str2 = str1;
    printf("�r�� 1 ===> %s\n",str1);
    printf("�r�� 2 ===> %s\n",str2);
    system("pause");
    return 0;
}
