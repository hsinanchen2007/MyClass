/*   程式名稱 : ch7_1.c                   */
/*   auto 變數宣告應用                    */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int  i,num;

    num = 2;
    for ( i = 0; i < 3; i++ )
    {
       printf("外圈 num = %d \n",num);
       num++;
       {
          auto int num = 1;
          printf("內圈 num = %d \n",num);
          num++;
       }
    }
    system("pause");
    return 0;
}
