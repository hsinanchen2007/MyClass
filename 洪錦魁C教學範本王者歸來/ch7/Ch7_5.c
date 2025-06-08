/*   祘Α嘿 : ch7_5.c                   */
/*   ８繰篈  static 跑计莱ノ        */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int  i,num;

    num = 2;
    for ( i = 0; i < 3; i++ )
    {
       printf("场 num = %d \n",num);
       num++;
       {
          static int num = 1;   /* 繰篈跑计 */ 
          printf("ず场 num = %d \n",num);
          num++;
       }
    }
    system("pause");
    return 0;
}
