/*   �{���W�� : ch10_15.c                 */
/*   puts() ������                        */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char str1[80] = "UNIX C Introduction";
    char *str2 = "Introduction to UNIX";

    printf("�r���X�p�U \n");
    puts(str1);
    puts(str2);
    puts(str1+4);
    puts(&str1[4]);
    puts(str2+5);
    system("pause");
    return 0;
}
