/*   �{���W�� : ch7_1.c                   */
/*   auto �ܼƫŧi����                    */
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
          auto int num = 1;
          printf("���� num = %d \n",num);
          num++;
       }
    }
    system("pause");
    return 0;
}
