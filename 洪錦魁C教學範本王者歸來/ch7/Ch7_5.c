/*   程式名稱 : ch7_5.c                   */
/*   另ㄧ個靜態  static 變數的應用        */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int  i,num;

    num = 2;
    for ( i = 0; i < 3; i++ )
    {
       printf("外部 num = %d \n",num);
       num++;
       {
          static int num = 1;   /* 宣告靜態變數 */ 
          printf("內部 num = %d \n",num);
          num++;
       }
    }
    system("pause");
    return 0;
}
