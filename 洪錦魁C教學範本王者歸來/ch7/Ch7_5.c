/*   �{���W�� : ch7_5.c                   */
/*   �t�����R�A  static �ܼƪ�����        */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int  i,num;

    num = 2;
    for ( i = 0; i < 3; i++ )
    {
       printf("�~�� num = %d \n",num);
       num++;
       {
          static int num = 1;   /* �ŧi�R�A�ܼ� */ 
          printf("���� num = %d \n",num);
          num++;
       }
    }
    system("pause");
    return 0;
}
