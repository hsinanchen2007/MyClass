/*   �{���W�� : ch8_6.c                   */
/*   �]�p exchange ���������ƹ��       */
#include <stdio.h>
#include <stdlib.h>
#define   exchange(a,b)    {         \
                               int t;\
                               t = a;\
                               a = b;\
                               b = t;\
                           }
int main()
{
   int x = 10;
   int y = 20;

   printf("x = %d;   y = %d\n",x,y);
   exchange(x,y);
   printf("x = %d;   y = %d\n",x,y);
   system("pause");
   return 0;
}
