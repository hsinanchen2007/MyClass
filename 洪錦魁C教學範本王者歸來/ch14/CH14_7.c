/*   �{���W�� : ch14_7.c                  */
/*   ��o�ثe�ؿ����|                     */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char pathname[81];

    if ( getcwd(pathname,80) == NULL )
    {
       printf("��o�ثe�ؿ����|���~ \n");
       exit(1);
    }
    printf("�ثe�ؿ����|�O %s\n",pathname);
    system("pause");
    return 0;
}
