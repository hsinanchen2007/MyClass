/*   �{���W�� : ch16_2.c                  */
/*   �� malloc ����                     */
#include <stdlib.h>
#include <stdio.h>
int main()
{
    char  *str;

    if (( str = (char *) malloc(80*sizeof(char))) == NULL)
    {
       printf("�L�k���o�O����Ŷ� \n");
       exit(1);
    }
    printf("����J�y�l \n");
    gets(str);
    printf("�A��J���y�l�O \n");
    puts(str);
    system("pause");
    return 0;
}
